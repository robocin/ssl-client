INCLUDEPATH += $$PWD

LIBS += -lpthread -lprotobuf -lz

HEADERS += $$PWD/ssl-client/ssl-client.h \
  $$PWD/ssl-client/net/grSim_client_example/grSim_client_example.h \
  $$PWD/ssl-client/net/net.h \
  $$PWD/ssl-client/net/netraw/netraw.h \
  $$PWD/ssl-client/net/referee_ssl_client/referee_ssl_client.h \
  $$PWD/ssl-client/net/robocup_ssl_client/robocup_ssl_client.h \
  $$PWD/ssl-client/net/robocup_ssl_server/robocup_ssl_server.h \
  $$PWD/ssl-client/utils/utils/timer.h \
  $$PWD/ssl-client/utils/utils/util.h \
  $$PWD/ssl-client/utils/utils.h

SOURCES += \
  $$PWD/ssl-client/net/grSim_client_example/grSim_client_example.cpp \
  $$PWD/ssl-client/net/netraw/netraw.cpp \
  $$PWD/ssl-client/net/referee_ssl_client/referee_ssl_client.cpp \
  $$PWD/ssl-client/net/robocup_ssl_client/robocup_ssl_client.cpp \
  $$PWD/ssl-client/net/robocup_ssl_server/robocup_ssl_server.cpp

include($$PWD/ssl-client/protobuf-files/protobuf-files.pri)
