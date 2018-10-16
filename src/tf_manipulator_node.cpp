#include <ros/ros.h>
#include "tf_manipulator/TFManipulator.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "tf_manipulator");
  ros::NodeHandle nodeHandle("~");

  tf_manipulator::TFManipulator TFManipulator(nodeHandle);

  ros::spin();
  return 0;
}
