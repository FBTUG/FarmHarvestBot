#ifndef _ROS_duckietown_msgs_Rect_h
#define _ROS_duckietown_msgs_Rect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class Rect : public ros::Msg
  {
    public:
      typedef int32_t _x_type;
      _x_type x;
      typedef int32_t _y_type;
      _y_type y;
      typedef int32_t _w_type;
      _w_type w;
      typedef int32_t _h_type;
      _h_type h;

    Rect():
      x(0),
      y(0),
      w(0),
      h(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_w;
      u_w.real = this->w;
      *(outbuffer + offset + 0) = (u_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_w.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->w);
      union {
        int32_t real;
        uint32_t base;
      } u_h;
      u_h.real = this->h;
      *(outbuffer + offset + 0) = (u_h.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_h.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_h.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_h.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->h);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_w;
      u_w.base = 0;
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->w = u_w.real;
      offset += sizeof(this->w);
      union {
        int32_t real;
        uint32_t base;
      } u_h;
      u_h.base = 0;
      u_h.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_h.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_h.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_h.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->h = u_h.real;
      offset += sizeof(this->h);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Rect"; };
    const char * getMD5(){ return "4a7147213b29db1bb19b0427bbb901ac"; };

  };

}
#endif