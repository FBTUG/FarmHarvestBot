#ifndef _ROS_duckietown_msgs_LanePose_h
#define _ROS_duckietown_msgs_LanePose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class LanePose : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _d_type;
      _d_type d;
      typedef float _sigma_d_type;
      _sigma_d_type sigma_d;
      typedef float _phi_type;
      _phi_type phi;
      typedef float _sigma_phi_type;
      _sigma_phi_type sigma_phi;
      typedef int32_t _status_type;
      _status_type status;
      typedef bool _in_lane_type;
      _in_lane_type in_lane;
      enum { NORMAL = 0 };
      enum { ERROR = 1 };

    LanePose():
      header(),
      d(0),
      sigma_d(0),
      phi(0),
      sigma_phi(0),
      status(0),
      in_lane(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_d;
      u_d.real = this->d;
      *(outbuffer + offset + 0) = (u_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d);
      union {
        float real;
        uint32_t base;
      } u_sigma_d;
      u_sigma_d.real = this->sigma_d;
      *(outbuffer + offset + 0) = (u_sigma_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sigma_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sigma_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sigma_d.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sigma_d);
      union {
        float real;
        uint32_t base;
      } u_phi;
      u_phi.real = this->phi;
      *(outbuffer + offset + 0) = (u_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phi);
      union {
        float real;
        uint32_t base;
      } u_sigma_phi;
      u_sigma_phi.real = this->sigma_phi;
      *(outbuffer + offset + 0) = (u_sigma_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sigma_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sigma_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sigma_phi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sigma_phi);
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_in_lane;
      u_in_lane.real = this->in_lane;
      *(outbuffer + offset + 0) = (u_in_lane.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_lane);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_d;
      u_d.base = 0;
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d = u_d.real;
      offset += sizeof(this->d);
      union {
        float real;
        uint32_t base;
      } u_sigma_d;
      u_sigma_d.base = 0;
      u_sigma_d.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sigma_d.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sigma_d.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sigma_d.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sigma_d = u_sigma_d.real;
      offset += sizeof(this->sigma_d);
      union {
        float real;
        uint32_t base;
      } u_phi;
      u_phi.base = 0;
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->phi = u_phi.real;
      offset += sizeof(this->phi);
      union {
        float real;
        uint32_t base;
      } u_sigma_phi;
      u_sigma_phi.base = 0;
      u_sigma_phi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sigma_phi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sigma_phi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sigma_phi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sigma_phi = u_sigma_phi.real;
      offset += sizeof(this->sigma_phi);
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->status = u_status.real;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_in_lane;
      u_in_lane.base = 0;
      u_in_lane.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_lane = u_in_lane.real;
      offset += sizeof(this->in_lane);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/LanePose"; };
    const char * getMD5(){ return "248b875aed9afcb389413014f9465bf7"; };

  };

}
#endif