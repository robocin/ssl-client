INCLUDEPATH += $$PWD

LIBS += -lpthread -L/usr/local/lib -lprotobuf -lz

HEADERS += $$PWD/ssl-client/ssl-client.h \
  $$PWD/ssl-client/net/net.h \
  $$PWD/ssl-client/net/grSim_client/grSim_client.h \
  $$PWD/ssl-client/net/netraw/netraw.h \
  $$PWD/ssl-client/net/referee_ssl_client/referee_ssl_client.h \
  $$PWD/ssl-client/net/robocup_ssl_client/robocup_ssl_client.h \
  $$PWD/ssl-client/net/robocup_ssl_server/robocup_ssl_server.h \
  $$PWD/ssl-client/protobuf/protobuf.h \
  $$PWD/ssl-client/utils/utils/timer.h \
  $$PWD/ssl-client/utils/utils/util.h \
  $$PWD/ssl-client/utils/utils.h

SOURCES += \
  $$PWD/ssl-client/net/grSim_client/grSim_client.cpp \
  $$PWD/ssl-client/net/netraw/netraw.cpp \
  $$PWD/ssl-client/net/referee_ssl_client/referee_ssl_client.cpp \
  $$PWD/ssl-client/net/robocup_ssl_client/robocup_ssl_client.cpp \
  $$PWD/ssl-client/net/robocup_ssl_server/robocup_ssl_server.cpp

HEADERS += \
  $$PWD/ssl-client/protobuf/pb/game_event.pb.h \
  $$PWD/ssl-client/protobuf/pb/grSim_Commands.pb.h \
  $$PWD/ssl-client/protobuf/pb/grSim_Packet.pb.h \
  $$PWD/ssl-client/protobuf/pb/grSim_Replacement.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_detection.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_detection_tracked.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_geometry.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_geometry_legacy.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_refbox_log.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper_legacy.pb.h \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper_tracked.pb.h \
  $$PWD/ssl-client/protobuf/pb/rcon.pb.h \
  $$PWD/ssl-client/protobuf/pb/referee.pb.h \
  $$PWD/ssl-client/protobuf/pb/savestate.pb.h

SOURCES += \
  $$PWD/ssl-client/protobuf/pb/game_event.pb.cc \
  $$PWD/ssl-client/protobuf/pb/grSim_Commands.pb.cc \
  $$PWD/ssl-client/protobuf/pb/grSim_Packet.pb.cc \
  $$PWD/ssl-client/protobuf/pb/grSim_Replacement.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_detection.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_detection_tracked.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_geometry.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_geometry_legacy.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_refbox_log.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper_legacy.pb.cc \
  $$PWD/ssl-client/protobuf/pb/messages_robocup_ssl_wrapper_tracked.pb.cc \
  $$PWD/ssl-client/protobuf/pb/rcon.pb.cc \
  $$PWD/ssl-client/protobuf/pb/referee.pb.cc \
  $$PWD/ssl-client/protobuf/pb/savestate.pb.cc
