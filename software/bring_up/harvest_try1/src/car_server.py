#!/usr/bin/env python

from harvest_try1.srv import *
import rospy
car_x=0
car_y=0
def handle_car_move(req):
    rospy.loginfo("car_server get request! [input %s , %s ]"%(req.diff_x, req.diff_y))
    global car_x
    global car_y
    car_x += req.diff_x
    car_y += req.diff_y
    #resp  = [car_x,car_y]
    return CarMoveResponse(car_x,car_y)

def car_server():
    rospy.init_node('car_server')
    s = rospy.Service('car_move', CarMove, handle_car_move)
    rospy.loginfo( "Ready to process car commands..")
    rospy.spin()

if __name__ == "__main__":
    car_server()
