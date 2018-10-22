#ifndef _ROS_duckietown_msgs_WheelsCmd_h
#define _ROS_duckietown_msgs_WheelsCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class WheelsCmd : public ros::Msg
  {
    public:
      typedef float _vel_left_type;
      _vel_left_type vel_left;
      typedef float _vel_right_type;
      _vel_right_type vel_right;

    WheelsCmd():
      vel_left(0),
      vel_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_vel_left;
      u_vel_left.real = this->vel_left;
      *(outbuffer + offset + 0) = (u_vel_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_left);
      union {
        float real;
        uint32_t base;
      } u_vel_right;
      u_vel_right.real = this->vel_right;
      *(outbuffer + offset + 0) = (u_vel_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_vel_left;
      u_vel_left.base = 0;
      u_vel_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_left = u_vel_left.real;
      offset += sizeof(this->vel_left);
      union {
        float real;
        uint32_t base;
      } u_vel_right;
      u_vel_right.base = 0;
      u_vel_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel_right = u_vel_right.real;
      offset += sizeof(this->vel_right);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/WheelsCmd"; };
    const char * getMD5(){ return "95189a38cb8112e26fa8ced2d5359a0c"; };

  };

}
#endif