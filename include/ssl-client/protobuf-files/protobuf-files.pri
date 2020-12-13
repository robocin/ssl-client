HEADERS += $$PWD/protobuf-files.h

PROTOBUF_FILES = $$files($$PWD/pb/*.proto, true)

PROTOBUF_HEADERS = $$files($$PWD/pb/*.pb.h, false)
PROTOBUF_SOURCES = $$files($$PWD/pb/*.pb.cc, false)

if (isEmpty(PROTOBUF_HEADERS) | isEmpty(PROTOBUF_SOURCES)) {
  protobuf_decl.name = protobuf headers
  protobuf_decl.input = PROTOBUF_FILES
  protobuf_decl.output = ${QMAKE_FILE_BASE}.pb.h
  protobuf_decl.commands = protoc --cpp_out=$$PWD/pb --proto_path=${QMAKE_FILE_IN_PATH} ${QMAKE_FILE_NAME}
  protobuf_decl.variable_out = PROTOBUF_HEADERS
  QMAKE_EXTRA_COMPILERS += protobuf_decl

  protobuf_impl.name = protobuf sources
  protobuf_impl.input = PROTOBUF_FILES
  protobuf_impl.output = ${QMAKE_FILE_BASE}.pb.cc
  protobuf_impl.depends = ${QMAKE_FILE_BASE}.pb.h
  protobuf_impl.commands = $$escape_expand(\n)
  protobuf_impl.variable_out = PROTOBUF_SOURCES
  QMAKE_EXTRA_COMPILERS += protobuf_impl
}

HEADERS += $${PROTOBUF_HEADERS}
SOURCES += $${PROTOBUF_SOURCES}
