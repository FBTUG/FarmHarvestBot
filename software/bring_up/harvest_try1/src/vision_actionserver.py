#!/usr/bin/env python
from harvest_try1.msg import *
import rospy
import actionlib

#FHB action server
class FhbActSrv(object):
    # create messages that are used to publish feedback/result
    _feedback = FhbActFeedback()
    _result = FhbActResult()

    def __init__(self, name):
        self._action_name = name
        self._as = actionlib.SimpleActionServer(self._action_name, FhbActAction, execute_cb=self.execute_cb, auto_start = False)
        self._as.start()
      
    def execute_cb(self, goal):
        # helper variables
        r = rospy.Rate(1)
        success = True
        
        # setup feedback msg
        self._feedback.notice_id = 1
        self._feedback.progrsss=10
        self._feedback.fb_msg=""
        
        # publish info to the console for the user
        rospy.loginfo('%s: Executing...' % (self._action_name))
        
        # start executing the action
        if goal.act_id>=200:
            for i in range(5):
                # check that preempt has not been requested by the client
                if self._as.is_preempt_requested():
                    rospy.loginfo('%s: Preempted' % self._action_name)
                    self._as.set_preempted()
                    success = False
                    break
                self._feedback.progrsss = i*20
                # publish the feedback
                self._as.publish_feedback(self._feedback)
                # this step is not necessary, the sequence is computed at 1 Hz for demonstration purposes
                r.sleep()
          
        if success:
            # reply a result for debug purpose
            self._result.status = 1 # 0-ok, >1 error code
            self._result.error_level =2 # 0-warning, 1-error, 2-fatal error 
            self._result.error_msg ="success"
            rospy.loginfo('%s: Succeeded' % self._action_name)
            self._as.set_succeeded(self._result)
        
if __name__ == '__main__':
    rospy.init_node('fhbact_srv')
    server = FhbActSrv("fhb_act")
    rospy.spin()
    
