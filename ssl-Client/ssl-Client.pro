TARGET = main
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core
QT += network

SOURCES += main.cpp \
    pb/messages_robocup_ssl_wrapper.pb.cc \
    pb/messages_robocup_ssl_detection.pb.cc \
    pb/messages_robocup_ssl_geometry.pb.cc \
    pb/grSim_Commands.pb.cc \
    pb/grSim_Packet.pb.cc \
    pb/grSim_Replacement.pb.cc \
    net/robocup_ssl_client.cpp \
    net/netraw.cpp \
    net/grSim_client.cpp

HEADERS += pb/messages_robocup_ssl_wrapper.pb.h \
    pb/messages_robocup_ssl_detection.pb.h \
    pb/messages_robocup_ssl_geometry.pb.h \
    pb/grSim_Commands.pb.h \
    pb/grSim_Packet.pb.h \
    pb/grSim_Replacement.pb.h \
    net/robocup_ssl_client.h \
    net/netraw.h \
    util/timer.h \
    util/util.h \
    net/grSim_client.h

INCLUDEPATH += include
LIBS += -Llibs/ -lprotobuf\
-lpthread
