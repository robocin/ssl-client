#ifndef REFEREE_SSL_CLIENT_H
#define REFEREE_SSL_CLIENT_H

#include <string>
#include "ssl-client/net/netraw/netraw.h"
#include "ssl-client/protobuf-files/protobuf-files.h"

class RefereeSSLClient {
 protected:
  static const int MaxDataGramSize = 65536;
  char* in_buffer;
  Net::UDP mc; // multicast client
  int _port;
  std::string _net_address;
  std::string _net_interface;

 public:
  RefereeSSLClient(int port = 10003,
                   std::string net_ref_address = "224.5.23.1",
                   std::string net_ref_interface = "");

  ~RefereeSSLClient();
  bool open(bool blocking = false);
  void close();
  bool receive(SSL_Referee& packet);
  int getPort();
  void setPort(int port);
  std::string getIpAddress();
  void setIpAddress(std::string net_address);
};

#endif
