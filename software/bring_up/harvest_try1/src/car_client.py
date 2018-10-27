#!/usr/bin/env python

import sys
import rospy
from harvest_try1.srv import *

def car_client(x, y):
    rospy.wait_for_service('car_move')
    try:
        car_move1 = rospy.ServiceProxy('car_move', CarMove)
        resp1 = car_move1(x, y)
        return resp1.cur_x, resp1.cur_y
    except rospy.ServiceException, e:
        print "Car Service call failed: %s"%e

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) >= 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        
        print usage()
        #print "length of argv=%i" % len(sys.argv)
        #print "argv 0=%s,1=%s,2=%s,3=%s,4=%s" %(sys.argv[0],sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4])
        sys.exit(1)
    print "Requesting Car diff_x=%s, diff_y=%s"%(x, y)
    cur_x, cur_y = car_client(x, y)
    print "after move, cur_x=%s, cur_y = %s"%(cur_x,cur_y)
