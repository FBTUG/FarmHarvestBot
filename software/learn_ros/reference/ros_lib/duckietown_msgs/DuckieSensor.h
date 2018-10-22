#ifndef _ROS_duckietown_msgs_DuckieSensor_h
#define _ROS_duckietown_msgs_DuckieSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class DuckieSensor : public ros::Msg
  {
    public:
      typedef uint16_t _value_type;
      _value_type value;
      typedef float _fvalue_type;
      _fvalue_type fvalue;
      typedef bool _is_analog_type;
      _is_analog_type is_analog;
      typedef const char* _name_type;
      _name_type name;

    DuckieSensor():
      value(0),
      fvalue(0),
      is_analog(0),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      union {
        float real;
        uint32_t base;
      } u_fvalue;
      u_fvalue.real = this->fvalue;
      *(outbuffer + offset + 0) = (u_fvalue.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fvalue.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fvalue.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fvalue.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fvalue);
      union {
        bool real;
        uint8_t base;
      } u_is_analog;
      u_is_analog.real = this->is_analog;
      *(outbuffer + offset + 0) = (u_is_analog.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_analog);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
      union {
        float real;
        uint32_t base;
      } u_fvalue;
      u_fvalue.base = 0;
      u_fvalue.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fvalue.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fvalue.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fvalue.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fvalue = u_fvalue.real;
      offset += sizeof(this->fvalue);
      union {
        bool real;
        uint8_t base;
      } u_is_analog;
      u_is_analog.base = 0;
      u_is_analog.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_analog = u_is_analog.real;
      offset += sizeof(this->is_analog);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/DuckieSensor"; };
    const char * getMD5(){ return "3337f0684bf5f2b309fb6921917219f7"; };

  };

}
#endif