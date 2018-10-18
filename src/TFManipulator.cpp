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
  subscriberStatic_ = nodeHandle_.subscribe(subscriberTopicStatic_, 1, 
                                            &TFManipulator::topicCallbackStatic, this);

  publisher_ = nodeHandle_.advertise<tf2_msgs::TFMessage>("/tf", 100);
  publisherStatic_ = nodeHandle_.advertise<tf2_msgs::TFMessage>("/tf_static", 100);
  
  ROS_INFO("Successfully launched node.");
}

TFManipulator::~TFManipulator()
{
}

bool TFManipulator::readParameters()
{
  return ((nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) && 
          (nodeHandle_.getParam("subscriber_topic_static", subscriberTopicStatic_)));
}

void TFManipulator::topicCallback(const tf2_msgs::TFMessage& message)
{
  algorithm_.processData(3);
  publisher_.publish(message);
  ROS_INFO("rdeuber: Message published");
}

void TFManipulator::topicCallbackStatic(const tf2_msgs::TFMessage& message)
{
  algorithm_.processData(3);
  publisherStatic_.publish(message);
  ROS_INFO("rdeuber: Static Message published");
}


} /* namespace */
