#ifndef REFEREE_SSL_CLIENT_H
#define REFEREE_SSL_CLIENT_H
#include "libs/net/netraw.h"
#include <string>
#include "libs/pb/referee.pb.h"
using namespace std;

class RefereeSSLClient{
protected:
  static const int MaxDataGramSize = 65536;
  char * in_buffer;
  Net::UDP mc; // multicast client
  int _port;
  string _net_address;
  string _net_interface;
public:
    RefereeSSLClient(int port = 10003,
                     string net_ref_address="224.5.23.1",
                     string net_ref_interface="");

    ~RefereeSSLClient();
    bool open(bool blocking=false);
    void close();
    bool receive(SSL_Referee & packet);
    int getPort();
    void setPort(int port);
    string getIpAddress();
    void setIpAddress(string net_address);

};

#endif




