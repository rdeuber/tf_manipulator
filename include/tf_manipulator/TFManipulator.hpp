#pragma once

#include "tf_manipulator/Algorithm.hpp"

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>
#include <tf2_msgs/TFMessage.h>
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


  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  //! ROS topic publisher.
  ros::Publisher publisher_;

  //! ROS topic name to subscribe to.
  std::string subscriberTopic_;

  //! Algorithm computation object.
  Algorithm algorithm_;
};

} /* namespace */
