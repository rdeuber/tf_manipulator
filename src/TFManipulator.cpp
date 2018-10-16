#include "tf_manipulator/TFManipulator.hpp"

// STD
#include <string>

namespace tf_manipulator {

TFManipulator::TFManipulator(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1,
                                      &TFManipulator::topicCallback, this);
  publisher_ = nodeHandle_.advertise<tf2_msgs::TFMessage>("/tf", 100);
  
  ROS_INFO("Successfully launched node.");
}

TFManipulator::~TFManipulator()
{
}

bool TFManipulator::readParameters()
{
  if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
  return true;
}

void TFManipulator::topicCallback(const tf2_msgs::TFMessage& message)
{
  algorithm_.processData(3);
  publisher_.publish(message);
  ROS_INFO("rdeuber: Message published");
}


} /* namespace */
