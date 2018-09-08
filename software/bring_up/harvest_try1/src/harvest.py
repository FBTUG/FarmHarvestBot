#!/usr/bin/env python
import rospy
from harvest_try1.msg import FruitCnt

def vision_sub_callback(data):
    rospy.loginfo("I heard fruit_cnt=%i", data.fruit_cnt)

def vision_sub():
    #rospy.init_node('vision_sub')  
    rospy.Subscriber('vision_fruit_cnt', FruitCnt, vision_sub_callback)


if __name__ == '__main__':
    try:
        rospy.init_node('harvest')
        vision_sub()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

