#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "cone_publisher");

  ros::NodeHandle n;
  ros::Publisher cone_pub = n.advertise<visualization_msgs::Marker>("cone_publisher", 50);
  tf::TransformBroadcaster odom_broadcaster;


  double x = -1.0;
  double y = 0.0;
  double th = 0.0;

  double vx = 5.75;
  double vy = -5.75;
  double vth = 1;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();

  int max_amount_cones = 50;

  ros::Rate r(10.0);
  int count = 0;
  while(n.ok()){

    
    if (count > max_amount_cones) {
      count = 0;
    }

    ros::spinOnce(); // check for incoming messages
    current_time = ros::Time::now();


    //------------------------------------------------------------
    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec();
    double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
    double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
    double delta_th = vth * dt;

    x += delta_x;
    y += delta_y;
    th += delta_th;


    //------------------------------------------------------------
    //next, we'll publish the odometry message over ROS
    visualization_msgs::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = current_time; // 0 -> always displayed marker
    marker.id = count;

    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = x; //move x position over time
    marker.pose.position.y = y;
    marker.pose.position.z = 0.0;

    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;

    //publish the message
    cone_pub.publish(marker);



    //------------------------------------------------------------
    last_time = current_time;
    ++count;
    r.sleep();
  }
}