#ifndef _ROS_duckietown_msgs_KinematicsWeights_h
#define _ROS_duckietown_msgs_KinematicsWeights_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class KinematicsWeights : public ros::Msg
  {
    public:
      uint32_t weights_length;
      typedef float _weights_type;
      _weights_type st_weights;
      _weights_type * weights;

    KinematicsWeights():
      weights_length(0), weights(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->weights_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->weights_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->weights_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->weights_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weights_length);
      for( uint32_t i = 0; i < weights_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->weights[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t weights_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      weights_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->weights_length);
      if(weights_lengthT > weights_length)
        this->weights = (float*)realloc(this->weights, weights_lengthT * sizeof(float));
      weights_length = weights_lengthT;
      for( uint32_t i = 0; i < weights_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_weights));
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/KinematicsWeights"; };
    const char * getMD5(){ return "6904a09d2a677bf07bc600ffaa092ae8"; };

  };

}
#endif