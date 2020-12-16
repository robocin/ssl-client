!isEqual(QT_MAJOR_VERSION, 5): error(requires Qt Creator 5)
lessThan(QT_MINOR_VERSION, 15): error(requires Qt Creator at least 5.15)

DESTDIR     = $$PWD/../bin
OBJECTS_DIR = .qt-generated-files/objects
MOC_DIR     = .qt-generated-files/moc
UI_DIR      = .qt-generated-files/ui

QT += core
QT += gui
QT += widgets
QT += opengl
QT += concurrent
QT += network

CONFIG += c++17

include($$PWD/../include/include.pri)
SOURCES += $$PWD/main.cpp

TARGET = ssl-client

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
