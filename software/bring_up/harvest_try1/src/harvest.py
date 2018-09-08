#!/usr/bin/env python
import rospy
from harvest_try1.msg import FruitCnt
from harvest_try1.srv import *

import time
fruit_cnt=0


def harvest_package_init():
    
    rospy.set_param('/mode', 'debug')
def vision_client(x, y):
    rospy.wait_for_service('fruit_pos')
    try:
        fruit_pos1 = rospy.ServiceProxy('fruit_pos', fruit_pos)
        resp1 = fruit_pos1(x, y)
        return resp1.pos_idx
    except rospy.ServiceException, e:
        rospy.loginfo( "Service call failed: %s"%e)
        
def vision_sub_callback(data):
    global fruit_cnt
    fruit_cnt = data.fruit_cnt
    rospy.loginfo("I heard fruit_cnt=%i", fruit_cnt)
    

def vision_sub():
    #rospy.init_node('vision_sub')  
    rospy.Subscriber('vision_fruit_cnt', FruitCnt, vision_sub_callback)

def car_client(x, y):
    rospy.wait_for_service('car_move')
    try:
        car_move1 = rospy.ServiceProxy('car_move', CarMove)
        resp = car_move1(x, y)
        return resp
    except rospy.ServiceException, e:
        print "Car Service call failed: %s"%e
        
def task():
    global fruit_cnt
    vision_sub()
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        if fruit_cnt==1:
            rospy.loginfo("fruit found!")
            fruit_pos_idx = vision_client(0,0)
            rospy.loginfo("ask vision to find the position of fruit, position index result=%i" %( fruit_pos_idx))
            rospy.loginfo("ask robot to pick that one!")
            time.sleep(2.5)
        else:
            resp = car_client(10,0)
            rospy.loginfo("car move to diff_x = %s, diff_y= %s, cur_x=%s, cur_y=%s" %(10,0,resp.cur_x,resp.cur_y))
            
        rate.sleep()    
    
if __name__ == '__main__':
    try:
        harvest_package_init()
        
        
        rospy.init_node('harvest')
        mode = rospy.get_param("/mode")
        rospy.loginfo("current running mode=%s" %(mode))
        task()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

