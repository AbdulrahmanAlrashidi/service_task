/*
node -- > Motorcontrol.cpp
node -- > IMU.cpp  
MSG : x , y , z : type float64

service : MotorControl is a client for IMU_Server 
MotorControl will request IMU_Server to compute Yaw Angle
IMU_Server will respond with response.angle 

print angle from client.

*/

#include "ros/ros.h"
#include "service_task_pkg/MSG.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "IMU");
  if (argc != 3)
  {
    ROS_INFO("usage: IMU X Y Z");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<service_task_pkg::MSG>("Yaw_angle");
  service_task_pkg::MSG srv;
  srv.request.x = atoll(argv[1]);
  srv.request.y = atoll(argv[2]);
  srv.request.z = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Yaw_angle: %f", (float)srv.response.result);
  }
  else
  {
    ROS_ERROR("Failed to call service Yaw angle");
    return 1;
  }

  return 0;
}