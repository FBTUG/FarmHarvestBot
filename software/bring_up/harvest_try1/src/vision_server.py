#!/usr/bin/env python

from harvest_try1.srv import *
import rospy
fruit_pos_idx=0
def handle_fruit_pos(req):
    rospy.loginfo("vision_server get request! Ignore useless input %s , %s ]"%(req.a, req.b))
    global fruit_pos_idx
    fruit_pos_idx +=1
    if fruit_pos_idx % 5 ==0:
        fruit_pos_idx = 0
    return fruit_posResponse(fruit_pos_idx)

def vision_server():
    rospy.init_node('vision_server')
    s = rospy.Service('fruit_pos', fruit_pos, handle_fruit_pos)
    rospy.loginfo( "Ready to process vision commands..")
    rospy.spin()

if __name__ == "__main__":
    vision_server()
