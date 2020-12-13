HEADERS += $$PWD/protobuf-files.h

PROTOBUF_FILES = $$files($$PWD/*.proto, true)

PROTOBUF_HEADERS = $$files($$PWD/*.pb.h, true)
PROTOBUF_SOURCES = $$files($$PWD/*.pb.cc, true)

HEADERS += $${PROTOBUF_HEADERS}
SOURCES += $${PROTOBUF_SOURCES}
