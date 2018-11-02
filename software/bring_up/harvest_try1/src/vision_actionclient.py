#!/usr/bin/env python
import rospy
import actionlib
from harvest_try1.msg import *
import sys

def cbFeedback(feedback):
    rospy.loginfo("feedback: %s" %(feedback))
    
def fhbaction_client():
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    client = actionlib.SimpleActionClient('fhb_act', FhbActAction)

    # Waits until the action server has started up and started
    # listening for goals.
    client.wait_for_server()

    # Creates a goal to send to the action server.
    goal = FhbActGoal()
    #a gold for debug purpose
    goal.act_seq=1
    goal.act_id=200
    goal.act_subid=3
    goal.i1=4
    goal.i2=5
    goal.f1=6.0
    goal.f2=7.0
    goal.line="abc"

    # Sends the goal to the action server. assign feedback callback
    # send_goal(self, goal, done_cb=None, active_cb=None, feedback_cb=None)
    client.send_goal(goal,None,None,cbFeedback)

    # Waits for the server to finish performing the action.
    client.wait_for_result()

    # Prints out the result of executing the action
    return client.get_result()  # A FibonacciResult

if __name__ == '__main__':
    try:
        # Initializes a rospy node so that the SimpleActionClient can
        # publish and subscribe over ROS.
        rospy.init_node('fhbact_client')
        result = fhbaction_client()
        rospy.loginfo("Result: %s" %(result))
    except rospy.ROSInterruptException:
        rospy.loginfo("program interrupted before completion")
  
