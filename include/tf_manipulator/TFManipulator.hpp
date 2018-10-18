#pragma once

#include "tf_manipulator/Algorithm.hpp"

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>
#include <tf2_msgs/TFMessage.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <std_srvs/Trigger.h>

namespace tf_manipulator {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class TFManipulator
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  TFManipulator(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~TFManipulator();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallback(const tf2_msgs::TFMessage& message);

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallbackStatic(const tf2_msgs::TFMessage& message);

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscribers.
  ros::Subscriber subscriber_;
  ros::Subscriber subscriberStatic_;

  //! ROS topic publisher.
  ros::Publisher publisher_;
  tf2_ros::StaticTransformBroadcaster static_broadcaster_;

  //! ROS topic names to subscribe to.
  std::string subscriberTopic_;
  std::string subscriberTopicStatic_;

  //! Algorithm computation object.
  Algorithm algorithm_;
};

} /* namespace */
