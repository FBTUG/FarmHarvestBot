#ifndef _ROS_duckietown_msgs_AntiInstagramHealth_h
#define _ROS_duckietown_msgs_AntiInstagramHealth_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class AntiInstagramHealth : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _J1_type;
      _J1_type J1;
      typedef float _J2_type;
      _J2_type J2;
      typedef float _J3_type;
      _J3_type J3;

    AntiInstagramHealth():
      header(),
      J1(0),
      J2(0),
      J3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_J1;
      u_J1.real = this->J1;
      *(outbuffer + offset + 0) = (u_J1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_J1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_J1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_J1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->J1);
      union {
        float real;
        uint32_t base;
      } u_J2;
      u_J2.real = this->J2;
      *(outbuffer + offset + 0) = (u_J2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_J2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_J2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_J2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->J2);
      union {
        float real;
        uint32_t base;
      } u_J3;
      u_J3.real = this->J3;
      *(outbuffer + offset + 0) = (u_J3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_J3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_J3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_J3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->J3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_J1;
      u_J1.base = 0;
      u_J1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_J1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_J1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_J1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->J1 = u_J1.real;
      offset += sizeof(this->J1);
      union {
        float real;
        uint32_t base;
      } u_J2;
      u_J2.base = 0;
      u_J2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_J2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_J2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_J2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->J2 = u_J2.real;
      offset += sizeof(this->J2);
      union {
        float real;
        uint32_t base;
      } u_J3;
      u_J3.base = 0;
      u_J3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_J3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_J3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_J3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->J3 = u_J3.real;
      offset += sizeof(this->J3);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/AntiInstagramHealth"; };
    const char * getMD5(){ return "3a6e17ea173536e892b4dde76e515fb4"; };

  };

}
#endif