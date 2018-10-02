#!/usr/bin/env python
import rospy
import rosnode
import cmd
import time

VERSION = "0.0.1"
CMD_VERSION = "0.1"
rcli = None

#ros_debug CLI
class RosDebugCli(cmd.Cmd):
    """ros_debug CLI"""

    def __init__(self):
        cmd.Cmd.__init__(self)
        self.prompt = 'CLI>'

############ cli maintain ####################
    def do_quit(self, line):
        """quit"""

        return True
############ commands  ####################
    def do_test(self,line):
        """Current test function"""
        nodes = rosnode.get_node_names()
        rospy.loginfo("node list:%s" %(nodes))

    def do_dump(self,line):
        """Dump information"""
        nodes = rosnode.get_node_names()
        rospy.loginfo("node list:%s" %(nodes))
    
    def do_version(self,line):
        """Report software version"""
        output = "V" + VERSION
        print(output)
    

def main():
    global rcli
    try:
        rospy.init_node('debug_ros')

        rospy.loginfo("----- debug_ros V%s" %(str(VERSION)))
        
        rcli = RosDebugCli()
        rcli.cmdloop()
        
        #rospy.spin()
    except rospy.ROSInterruptException:
        pass        

if __name__ == '__main__':
    main()