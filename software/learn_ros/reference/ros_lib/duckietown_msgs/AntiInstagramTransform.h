#ifndef _ROS_duckietown_msgs_AntiInstagramTransform_h
#define _ROS_duckietown_msgs_AntiInstagramTransform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class AntiInstagramTransform : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float s[6];

    AntiInstagramTransform():
      header(),
      s()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->s[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->s[i]));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/AntiInstagramTransform"; };
    const char * getMD5(){ return "d8691e07ae6615fec4d91101863288cf"; };

  };

}
#endif