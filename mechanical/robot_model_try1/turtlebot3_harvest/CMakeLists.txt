################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 2.8.3)
project(turtlebot3_harvest)

################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
  tf
  turtlebot3_msgs
)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS rospy std_msgs sensor_msgs geometry_msgs nav_msgs tf turtlebot3_msgs
)

################################################################################
# Build
################################################################################
#include_directories(
#  include
#  ${catkin_INCLUDE_DIRS}
#)

#add_executable(turtlebot3_harvest_node src/turtlebot3_harvest.cpp)
#add_dependencies(turtlebot3_harvest_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(turtlebot3_harvest_node ${catkin_LIBRARIES})

################################################################################
# Install
################################################################################
#install(TARGETS turtlebot3_harvest_node
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#)

#install(DIRECTORY launch rviz
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)

################################################################################
# Test
################################################################################
