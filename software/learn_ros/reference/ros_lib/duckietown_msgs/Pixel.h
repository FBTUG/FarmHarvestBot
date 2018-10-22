#ifndef _ROS_duckietown_msgs_Pixel_h
#define _ROS_duckietown_msgs_Pixel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class Pixel : public ros::Msg
  {
    public:
      typedef int32_t _u_type;
      _u_type u;
      typedef int32_t _v_type;
      _v_type v;

    Pixel():
      u(0),
      v(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        int32_t real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Pixel"; };
    const char * getMD5(){ return "f06a7e8dd345ffb826d71a489782114b"; };

  };

}
#endif