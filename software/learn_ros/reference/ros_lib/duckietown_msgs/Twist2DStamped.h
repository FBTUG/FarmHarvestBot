#ifndef _ROS_duckietown_msgs_Twist2DStamped_h
#define _ROS_duckietown_msgs_Twist2DStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class Twist2DStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _v_type;
      _v_type v;
      typedef float _omega_type;
      _omega_type omega;

    Twist2DStamped():
      header(),
      v(0),
      omega(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      union {
        float real;
        uint32_t base;
      } u_omega;
      u_omega.real = this->omega;
      *(outbuffer + offset + 0) = (u_omega.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_omega.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_omega.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_omega.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->omega);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
      union {
        float real;
        uint32_t base;
      } u_omega;
      u_omega.base = 0;
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_omega.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->omega = u_omega.real;
      offset += sizeof(this->omega);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Twist2DStamped"; };
    const char * getMD5(){ return "3fc0942a3082e78d7ded4a58ea1e2d0c"; };

  };

}
#endif