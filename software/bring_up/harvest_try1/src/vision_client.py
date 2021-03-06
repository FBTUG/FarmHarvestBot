#!/usr/bin/env python

import sys
import rospy
from harvest_try1.srv import *

def vision_client(x, y):
    rospy.wait_for_service('fruit_pos')
    try:
        fruit_pos1 = rospy.ServiceProxy('fruit_pos', fruit_pos)
        resp1 = fruit_pos1(x, y)
        return resp1.pos_idx
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print usage()
        sys.exit(1)
    print "Requesting %s+%s"%(x, y)
    print "%s + %s = %s"%(x, y, vision_client(x, y))
