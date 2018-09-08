#!/usr/bin/env python

from harvest_try1.srv import *
import rospy

def handle_fruit_pos(req):
    print "Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b))
    return fruit_posResponse(req.a + req.b)

def vision_server():
    rospy.init_node('vision_server')
    s = rospy.Service('fruit_pos', fruit_pos, handle_fruit_pos)
    print "Ready to process vision commands.."
    rospy.spin()

if __name__ == "__main__":
    vision_server()
