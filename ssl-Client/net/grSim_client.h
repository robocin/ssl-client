#ifndef GRSIMCLIENT_H
#define GRSIMCLIENT_H

#include <QObject>
#include <QUdpSocket>

class GrSim_Client : public QObject
{
    Q_OBJECT
public:
    explicit GrSim_Client(QObject *parent = 0);
    void sendCommand(double velX, int id);
    QHostAddress _addr;
    quint16 _port;

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;

};

#endif // GRSIMCLIENT_H
