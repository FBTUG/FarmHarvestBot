#ifndef _ROS_duckietown_msgs_KinematicsParameters_h
#define _ROS_duckietown_msgs_KinematicsParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class KinematicsParameters : public ros::Msg
  {
    public:
      uint32_t parameters_length;
      typedef float _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    KinematicsParameters():
      parameters_length(0), parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameters_length);
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->parameters[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameters_length);
      if(parameters_lengthT > parameters_length)
        this->parameters = (float*)realloc(this->parameters, parameters_lengthT * sizeof(float));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_parameters));
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/KinematicsParameters"; };
    const char * getMD5(){ return "cbca57679564ab84ca723072e3bf6226"; };

  };

}
#endif