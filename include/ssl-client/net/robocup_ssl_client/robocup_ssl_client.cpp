//========================================================================
//  This software is free: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License Version 3,
//  as published by the Free Software Foundation.
//
//  This software is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  Version 3 in the file COPYING that came with this distribution.
//  If not, see <http://www.gnu.org/licenses/>.
//========================================================================
/*!
  \file    robocup_ssl_client.cpp
  \brief   C++ Implementation: robocup_ssl_client
  \author  Stefan Zickler, 2009
*/
//========================================================================
#include "robocup_ssl_client.h"
#include <cstdio>

RoboCupSSLClient::RoboCupSSLClient(int port, std::string net_address, std::string net_interface) {
  _port = port;
  _net_address = net_address;
  _net_interface = net_interface;
  in_buffer = new char[65536];

  //  std::cout << std::endl;
  //  std::cout << "SSL Client Ip: " << getIpAdress() << std::endl;
  //  std::cout << "SSL Client Port: " << getPort() << std::endl;
  //  setPort(1202);
  //  setIpAdress("224.5.23.1");
  //  std::cout << "SSL Client Ip: " << getIpAdress() << std::endl;
  //  std::cout << "SSL Client Port: " << getPort() << std::endl;
}

RoboCupSSLClient::~RoboCupSSLClient() {
  delete[] in_buffer;
}

void RoboCupSSLClient::close() {
  mc.close();
}

bool RoboCupSSLClient::open(bool blocking) {
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

bool RoboCupSSLClient::receive(SSL_WrapperPacket& packet) {
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

bool RoboCupSSLClient::receive(TrackerWrapperPacket& packet) {
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

int RoboCupSSLClient::getPort() {
  return _port;
}

void RoboCupSSLClient::setPort(int port) {
  this->close();
  this->_port = port;
  this->open(false);
}

std::string RoboCupSSLClient::getIpAddress() {
  return _net_address;
}

void RoboCupSSLClient::setIpAddress(std::string net_address) {
  this->close();
  this->_net_address = net_address;
  this->open(false);
}
