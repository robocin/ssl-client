// myudp.cpp

#include "net/myudp.h"
#include "pb/grSim_Packet.pb.h"
#include "pb/grSim_Commands.pb.h"
#include "pb/grSim_Replacement.pb.h"


MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{
    // create a QUDP socket
    socket = new QUdpSocket(this);

    this->_addr.setAddress("192.168.25.206");
    this->_port = quint16(20011);

    socket->bind(this->_addr, this->_port);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::sendCommand(double velX, int id){
    double zero = 0.0;
    grSim_Packet packet;
    bool yellow = false;
    packet.mutable_commands()->set_isteamyellow(yellow);
    packet.mutable_commands()->set_timestamp(0.0);
    grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
    command->set_id(id);

    command->set_wheelsspeed(!true);
    command->set_wheel1(zero);
    command->set_wheel2(zero);
    command->set_wheel3(zero);
    command->set_wheel4(zero);
    command->set_veltangent(velX);
    command->set_velnormal(zero);
    command->set_velangular(zero);

    command->set_kickspeedx(zero);
    command->set_kickspeedz(zero);
    command->set_spinner(false);

    QByteArray dgram;
    dgram.resize(packet.ByteSize());
    packet.SerializeToArray(dgram.data(), dgram.size());
    if(socket->writeDatagram(dgram, this->_addr, this->_port) > -1){
        printf("send data\n");
    }
}

void MyUDP::readyRead(){
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
