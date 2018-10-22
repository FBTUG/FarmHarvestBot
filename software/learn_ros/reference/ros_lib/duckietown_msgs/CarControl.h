#ifndef _ROS_duckietown_msgs_CarControl_h
#define _ROS_duckietown_msgs_CarControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class CarControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _steering_type;
      _steering_type steering;
      typedef bool _need_steering_type;
      _need_steering_type need_steering;

    CarControl():
      header(),
      speed(0),
      steering(0),
      need_steering(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_steering;
      u_steering.real = this->steering;
      *(outbuffer + offset + 0) = (u_steering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering);
      union {
        bool real;
        uint8_t base;
      } u_need_steering;
      u_need_steering.real = this->need_steering;
      *(outbuffer + offset + 0) = (u_need_steering.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->need_steering);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_steering;
      u_steering.base = 0;
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering = u_steering.real;
      offset += sizeof(this->steering);
      union {
        bool real;
        uint8_t base;
      } u_need_steering;
      u_need_steering.base = 0;
      u_need_steering.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->need_steering = u_need_steering.real;
      offset += sizeof(this->need_steering);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/CarControl"; };
    const char * getMD5(){ return "a5bdd39ba7df1e21f0742b74ac614c71"; };

  };

}
#endif