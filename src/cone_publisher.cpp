#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/ColorRGBA.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "cone_publisher");

  ros::NodeHandle n;
  ros::Publisher cone_pub = n.advertise<visualization_msgs::Marker>("cone_publisher", 50);

  //-----------------------------
  // define cone positions
  double x_blue_cone = 3.0; // blue on the right side
  double y_blue_cone = -4.0;
  double x_yellow_cone = 5.0; // yellow on the left side
  double y_yellow_cone = 0.0;

  ros::Time current_time = ros::Time::now();

  int max_amount_cones = 20;

  ros::Rate rate(1.0); //rate in Hz
  int count = 0;
  while (n.ok()){

    if (count > max_amount_cones) {
      count = 0;
    }

    ros::spinOnce(); //check for incoming messages

    current_time = ros::Time::now(); //specify time for both cones


    //------------------------------------------------------------
    //publish blue cone

    visualization_msgs::Marker marker_blue_cone;
    marker_blue_cone.header.frame_id = "base_link"; //publish to coordinate frame of the urdf-car-model
    marker_blue_cone.header.stamp = current_time;
    marker_blue_cone.id = count;

    marker_blue_cone.type = visualization_msgs::Marker::SPHERE;
    marker_blue_cone.action = visualization_msgs::Marker::ADD;

    marker_blue_cone.pose.position.x = x_blue_cone; 
    marker_blue_cone.pose.position.y = y_blue_cone;
    marker_blue_cone.pose.position.z = 0.0;

    marker_blue_cone.scale.x = 0.5;
    marker_blue_cone.scale.y = 0.5;
    marker_blue_cone.scale.z = 0.5;

    marker_blue_cone.color.r = 0.0;
    marker_blue_cone.color.g = 0.0;
    marker_blue_cone.color.b = 1.0;
    marker_blue_cone.color.a = 1.0;

    cone_pub.publish(marker_blue_cone);


    //------------------------------------------------------------
    //publish yellow cone
    
    visualization_msgs::Marker marker_yellow_cone;
    marker_yellow_cone.header.frame_id = "base_link";
    marker_yellow_cone.header.stamp = current_time;
    marker_yellow_cone.id = ++count;

    marker_yellow_cone.type = visualization_msgs::Marker::SPHERE;
    marker_yellow_cone.action = visualization_msgs::Marker::ADD;

    marker_yellow_cone.pose.position.x = x_yellow_cone; 
    marker_yellow_cone.pose.position.y = y_yellow_cone;
    marker_yellow_cone.pose.position.z = 0.0;

    marker_yellow_cone.scale.x = 0.5;
    marker_yellow_cone.scale.y = 0.5;
    marker_yellow_cone.scale.z = 0.5;

    marker_yellow_cone.color.r = 1.0;
    marker_yellow_cone.color.g = 1.0;
    marker_yellow_cone.color.b = 0.0;
    marker_yellow_cone.color.a = 1.0;
    
    cone_pub.publish(marker_yellow_cone);



    //------------------------------------------------------------
    ++count;
    rate.sleep();
  }
}