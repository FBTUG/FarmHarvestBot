#ifndef _ROS_SERVICE_SetValue_h
#define _ROS_SERVICE_SetValue_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

static const char SETVALUE[] = "duckietown_msgs/SetValue";

  class SetValueRequest : public ros::Msg
  {
    public:
      typedef float _value_type;
      _value_type value;

    SetValueRequest():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return SETVALUE; };
    const char * getMD5(){ return "0aca93dcf6d857f0e5a0dc6be1eaa9fb"; };

  };

  class SetValueResponse : public ros::Msg
  {
    public:

    SetValueResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETVALUE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetValue {
    public:
    typedef SetValueRequest Request;
    typedef SetValueResponse Response;
  };

}
#endif
