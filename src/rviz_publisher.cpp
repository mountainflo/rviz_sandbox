#include "ros/ros.h"
#include <geometry_msgs/Point.h>
//#include <visualization_msgs/Marker.h>


#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "rviz_publisher"); //node name

  ros::NodeHandle n;

  ros::Publisher rviz_pub = n.advertise<geometry_msgs::Point>("geo_publisher", 1000); //topic name

  ros::Rate loop_rate(1); // run with 10 Hz


  ROS_INFO("rviz_publisher started.");

  int count = 0;
  while (ros::ok())
  {

    geometry_msgs::Point msg;
    msg.x = count;
    msg.y = 1;
    msg.z = 0;

    //    ROS_INFO("Sum: %ld", (long int)srv.response.sum);

    ROS_INFO("published messages: x:%f, y:%f, z:%f", msg.x, msg.y, msg.z);
    rviz_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}