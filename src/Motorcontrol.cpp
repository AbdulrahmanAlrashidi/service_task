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

bool compute(service_task_pkg::MSG::Request  &req,
         service_task_pkg::MSG::Response &res)
{
  res.result = req.z;
  ROS_INFO("request: x=%d, y=%d, z=%d", (double)req.x, (double)req.y,(double)req.z );
  ROS_INFO("sending back response: [%d]", (double)res.result);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Motorcontrol");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("Yaw_angle", compute);
  ROS_INFO("Ready to compute Yaw angle.");
  ros::spin();

  return 0;
}