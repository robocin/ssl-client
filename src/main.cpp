// author  Renato Sousa, 2018
#include <QDebug>
#include <QtNetwork>
#include <ssl-client/ssl-client.h>

void printRobotInfo(const SSL_DetectionRobot& robot) {
  qDebug("CONF=%4.2f ", robot.confidence());
  if (robot.has_robot_id()) {
    qDebug("ID=%3d ", robot.robot_id());
  } else {
    qDebug("ID=N/A ");
  }
  qDebug(" HEIGHT=%6.2f POS=<%9.2f,%9.2f> ",
         robot.height(),
         robot.x(),
         robot.y());
  if (robot.has_orientation()) {
    qDebug("ANGLE=%6.3f ", robot.orientation());
  } else {
    qDebug("ANGLE=N/A    ");
  }
  qDebug("RAW=<%8.2f,%8.2f>\n", robot.pixel_x(), robot.pixel_y());
}

int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;

  RoboCupSSLClient client(10020, "224.5.23.2");

  client.open(true);
  SSL_WrapperPacket packet;

  GrSim_Client_Example grSim_client;
  grSim_client.setPortAndAddress(20011, "127.0.0.1");

  while (true) {
    // grSim_client.sendCommand(1.0, 0);
    if (client.receive(packet)) {
      qDebug(
          "-----Received Wrapper Packet---------------------------------------------\n");
      // see if the packet contains a robot detection frame:
      if (packet.has_detection()) {
        SSL_DetectionFrame detection = packet.detection();
        // Display the contents of the robot detection results:
        double t_now = GetTimeSec();

        qDebug("-[Detection Data]-------\n");
        // Frame info:
        qDebug("Camera ID=%d FRAME=%d T_CAPTURE=%.4f\n",
               detection.camera_id(),
               detection.frame_number(),
               detection.t_capture());

        qDebug("SSL-Vision Processing Latency                   %7.3fms\n",
               (detection.t_sent() - detection.t_capture()) * 1000.0);
        qDebug("Network Latency (assuming synched system clock) %7.3fms\n",
               (t_now - detection.t_sent()) * 1000.0);
        qDebug("Total Latency   (assuming synched system clock) %7.3fms\n",
               (t_now - detection.t_capture()) * 1000.0);
        int balls_n = detection.balls_size();
        int robots_blue_n = detection.robots_blue_size();
        int robots_yellow_n = detection.robots_yellow_size();

        // Ball info:
        for (int i = 0; i < balls_n; i++) {
          SSL_DetectionBall ball = detection.balls(i);
          qDebug("-Ball (%2d/%2d): CONF=%4.2f POS=<%9.2f,%9.2f> ",
                 i + 1,
                 balls_n,
                 ball.confidence(),
                 ball.x(),
                 ball.y());
          if (ball.has_z()) {
            qDebug("Z=%7.2f ", ball.z());
          } else {
            qDebug("Z=N/A   ");
          }
          qDebug("RAW=<%8.2f,%8.2f>\n", ball.pixel_x(), ball.pixel_y());
        }

        // Blue robot info:
        for (int i = 0; i < robots_blue_n; i++) {
          SSL_DetectionRobot robot = detection.robots_blue(i);
          qDebug("-Robot(B) (%2d/%2d): ", i + 1, robots_blue_n);
          printRobotInfo(robot);
          if (robot.x() <= 0) {
            grSim_client.sendCommand(1.0, i);
          } else {
            grSim_client.sendCommand(-1.0, i);
          }
        }

        // Yellow robot info:
        for (int i = 0; i < robots_yellow_n; i++) {
          SSL_DetectionRobot robot = detection.robots_yellow(i);
          qDebug("-Robot(Y) (%2d/%2d): ", i + 1, robots_yellow_n);
          printRobotInfo(robot);
        }
      }

      // see if packet contains geometry data:
      if (packet.has_geometry()) {
        const SSL_GeometryData& geom = packet.geometry();
        qDebug("-[Geometry Data]-------\n");

        const SSL_GeometryFieldSize& field = geom.field();
        qDebug("Field Dimensions:\n");
        qDebug("  -field_length=%d (mm)\n", field.field_length());
        qDebug("  -field_width=%d (mm)\n", field.field_width());
        qDebug("  -boundary_width=%d (mm)\n", field.boundary_width());
        qDebug("  -goal_width=%d (mm)\n", field.goal_width());
        qDebug("  -goal_depth=%d (mm)\n", field.goal_depth());
        qDebug("  -field_lines_size=%d\n", field.field_lines_size());
        qDebug("  -field_arcs_size=%d\n", field.field_arcs_size());

        int calib_n = geom.calib_size();
        for (int i = 0; i < calib_n; i++) {
          const SSL_GeometryCameraCalibration& calib = geom.calib(i);
          qDebug("Camera Geometry for Camera ID %d:\n", calib.camera_id());
          qDebug("  -focal_length=%.2f\n", calib.focal_length());
          qDebug("  -principal_point_x=%.2f\n", calib.principal_point_x());
          qDebug("  -principal_point_y=%.2f\n", calib.principal_point_y());
          qDebug("  -distortion=%.2f\n", calib.distortion());
          qDebug("  -q0=%.2f\n", calib.q0());
          qDebug("  -q1=%.2f\n", calib.q1());
          qDebug("  -q2=%.2f\n", calib.q2());
          qDebug("  -q3=%.2f\n", calib.q3());
          qDebug("  -tx=%.2f\n", calib.tx());
          qDebug("  -ty=%.2f\n", calib.ty());
          qDebug("  -tz=%.2f\n", calib.tz());

          if (calib.has_derived_camera_world_tx() &&
              calib.has_derived_camera_world_ty() &&
              calib.has_derived_camera_world_tz()) {
            qDebug("  -derived_camera_world_tx=%.f\n",
                   calib.derived_camera_world_tx());
            qDebug("  -derived_camera_world_ty=%.f\n",
                   calib.derived_camera_world_ty());
            qDebug("  -derived_camera_world_tz=%.f\n",
                   calib.derived_camera_world_tz());
          }
        }
      }
    }
  }

  return 0;
}
