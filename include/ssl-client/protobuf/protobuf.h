#ifndef PROTOBUF_H
#define PROTOBUF_H

#if __has_include("pb/game_event.pb.h")
  #include "pb/game_event.pb.h"
#else
  #warning "pb/game_event.pb.h" was not found.
#endif

#if __has_include("pb/grSim_Commands.pb.h")
  #include "pb/grSim_Commands.pb.h"
#else
  #warning "pb/grSim_Commands.pb.h" was not found.
#endif

#if __has_include("pb/grSim_Packet.pb.h")
  #include "pb/grSim_Packet.pb.h"
#else
  #warning "pb/grSim_Packet.pb.h" was not found.
#endif

#if __has_include("pb/grSim_Replacement.pb.h")
  #include "pb/grSim_Replacement.pb.h"
#else
  #warning "pb/grSim_Replacement.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_detection.pb.h")
  #include "pb/messages_robocup_ssl_detection.pb.h"
#else
  #warning "pb/messages_robocup_ssl_detection.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_detection_tracked.pb.h")
  #include "pb/messages_robocup_ssl_detection_tracked.pb.h"
#else
  #warning "pb/messages_robocup_ssl_detection_tracked.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_geometry.pb.h")
  #include "pb/messages_robocup_ssl_geometry.pb.h"
#else
  #warning "pb/messages_robocup_ssl_geometry.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_geometry_legacy.pb.h")
  #include "pb/messages_robocup_ssl_geometry_legacy.pb.h"
#else
  #warning "pb/messages_robocup_ssl_geometry_legacy.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_refbox_log.pb.h")
  #include "pb/messages_robocup_ssl_refbox_log.pb.h"
#else
  #warning "pb/messages_robocup_ssl_refbox_log.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_wrapper.pb.h")
  #include "pb/messages_robocup_ssl_wrapper.pb.h"
#else
  #warning "pb/messages_robocup_ssl_wrapper.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_wrapper_legacy.pb.h")
  #include "pb/messages_robocup_ssl_wrapper_legacy.pb.h"
#else
  #warning "pb/messages_robocup_ssl_wrapper_legacy.pb.h" was not found.
#endif

#if __has_include("pb/messages_robocup_ssl_wrapper_tracked.pb.h")
  #include "pb/messages_robocup_ssl_wrapper_tracked.pb.h"
#else
  #warning "pb/messages_robocup_ssl_wrapper_tracked.pb.h" was not found.
#endif

#if __has_include("pb/rcon.pb.h")
  #include "pb/rcon.pb.h"
#else
  #warning "pb/rcon.pb.h" was not found.
#endif

#if __has_include("pb/referee.pb.h")
  #include "pb/referee.pb.h"
#else
  #warning "pb/referee.pb.h" was not found.
#endif

#if __has_include("pb/savestate.pb.h")
  #include "pb/savestate.pb.h"
#else
  #warning "pb/savestate.pb.h" was not found.
#endif

#endif // PROTOBUF_H
