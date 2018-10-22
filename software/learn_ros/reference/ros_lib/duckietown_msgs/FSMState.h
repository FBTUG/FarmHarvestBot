#ifndef _ROS_duckietown_msgs_FSMState_h
#define _ROS_duckietown_msgs_FSMState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class FSMState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _state_type;
      _state_type state;
      enum { LANE_FOLLOWING = "LANE_FOLLOWING" };
      enum { COORDINATION = "COORDINATION" };
      enum { INTERSECTION_CONTROL = "INTERSECTION_CONTROL" };
      enum { JOYSTICK_CONTROL = "JOYSTICK_CONTROL" };
      enum { VEHICLE_AVOIDANCE = "VEHICLE_AVOIDANCE" };
      enum { OBSTACLE_AVOID = "OBSTACLE_AVOID" };

    FSMState():
      header(),
      state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/FSMState"; };
    const char * getMD5(){ return "7358237ec6ffa8d862869f9b95659ac9"; };

  };

}
#endif