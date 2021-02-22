#include "referee_ssl_client.h"

RefereeSSLClient::RefereeSSLClient(int port, std::string net_address, std::string net_interface) {
  _port = port;
  _net_address = net_address;
  _net_interface = net_interface;
  in_buffer = new char[65536];
}

RefereeSSLClient::~RefereeSSLClient() {
  delete[] in_buffer;
}

void RefereeSSLClient::close() {
  mc.close();
}

bool RefereeSSLClient::open(bool blocking) {
  close();
  if (!mc.open(_port, true, true, blocking)) {
    fprintf(stderr, "Unable to open UDP network port: %d\n", _port);
    fflush(stderr);
    return (false);
  }

  Net::Address multiaddr, interface;
  multiaddr.setHost(_net_address.c_str(), _port);
  if (_net_interface.length() > 0) {
    interface.setHost(_net_interface.c_str(), _port);
  } else {
    interface.setAny();
  }

  if (!mc.addMulticast(multiaddr, interface)) {
    fprintf(stderr, "Unable to setup UDP multicast\n");
    fflush(stderr);
    return (false);
  }

  return (true);
}

bool RefereeSSLClient::receive(SSL_Referee& packet) {
  Net::Address src;
  int r = 0;
  r = mc.recv(in_buffer, MaxDataGramSize, src);
  if (r > 0) {
    fflush(stdout);
    // decode packet:
    return packet.ParseFromArray(in_buffer, r);
  }
  return false;
}

int RefereeSSLClient::getPort() {
  return _port;
}

void RefereeSSLClient::setPort(int port) {
  this->close();
  this->_port = port;
  this->open(false);
}

std::string RefereeSSLClient::getIpAddress() {
  return _net_address;
}

void RefereeSSLClient::setIpAddress(std::string net_address) {
  this->close();
  this->_net_address = net_address;
  this->open(false);
}
