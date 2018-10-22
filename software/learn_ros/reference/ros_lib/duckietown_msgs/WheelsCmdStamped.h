#ifndef _ROS_duckietown_msgs_WheelsCmdStamped_h
#define _ROS_duckietown_msgs_WheelsCmdStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class WheelsCmdStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _vel_left_type;
      _vel_left_type vel_left;
      typedef float _vel_right_type;
      _vel_right_type vel_right;

    WheelsCmdStamped():
      header(),
      vel_left(0),
      vel_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "duckietown_msgs/WheelsCmdStamped"; };
    const char * getMD5(){ return "edbf8d24194d839b1982a6a991b552c6"; };

  };

}
#endif