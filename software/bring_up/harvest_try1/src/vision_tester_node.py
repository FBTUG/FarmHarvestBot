#!/usr/bin/env python
PKG = 'harvest_try1'
import rospy
import roslib 
import unittest,rostest
import sys
from harvest_try1.msg import FruitCnt



## A sample python unit test
class VisionTesterNode(unittest.TestCase):

    def __init__(self, *args):
        super(VisionTesterNode, self).__init__(*args)
        self.msg_received = False

    def setup(self):
        # Setup the node
        rospy.init_node('vision_tester_node', anonymous=False)

        # Setup the publisher and subscriber
        self.sub_vision_fruit_cnt = rospy.Subscriber('vision_fruit_cnt', FruitCnt, self.vision_sub_callback)


        # Wait for the node  to finish starting up
        timeout = rospy.Time.now() + rospy.Duration(5) # Wait at most 5 seconds for the node to come up
        while (self.sub_vision_fruit_cnt.get_num_connections() < 1 ) and \
                not rospy.is_shutdown() and rospy.Time.now() < timeout:
            rospy.sleep(0.1)
    def vision_sub_callback(self,data):
        rospy.loginfo("I heard fruit_cnt=%i", data.fruit_cnt)
        self.msg_received = True

    def test_subscriber(self):
        self.setup()    # Setup the node
        self.assertGreaterEqual(self.sub_vision_fruit_cnt.get_num_connections(), 1, "No connections found on sub_vision_fruit_cnt topic")
        self.assertEquals(self.msg_received, True, "sub_vision_fruit_cnt not received")

    ## test 1 == 1
    def test_one_equals_one(self): # only functions with 'test_'-prefix will be run!
        self.assertEquals(1, 1, "1!=1")

    
if __name__ == '__main__':
    #rospy.init_node('vision_tester_node', anonymous=False)
    rostest.rosrun(PKG, 'vision_tester_node', VisionTesterNode)