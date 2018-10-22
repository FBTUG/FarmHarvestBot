#ifndef _ROS_duckietown_msgs_CoordinationClearance_h
#define _ROS_duckietown_msgs_CoordinationClearance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class CoordinationClearance : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _status_type;
      _status_type status;
      enum { NA = -1 };
      enum { WAIT = 0 };
      enum { GO = 1 };

    CoordinationClearance():
      header(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/CoordinationClearance"; };
    const char * getMD5(){ return "863863237538fdb5f0d38c0c62b294db"; };

  };

}
#endif