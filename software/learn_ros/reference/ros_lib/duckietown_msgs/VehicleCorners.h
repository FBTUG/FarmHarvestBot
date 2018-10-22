#ifndef _ROS_duckietown_msgs_VehicleCorners_h
#define _ROS_duckietown_msgs_VehicleCorners_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"
#include "std_msgs/Bool.h"

namespace duckietown_msgs
{

  class VehicleCorners : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t corners_length;
      typedef geometry_msgs::Point32 _corners_type;
      _corners_type st_corners;
      _corners_type * corners;
      typedef std_msgs::Bool _detection_type;
      _detection_type detection;
      typedef int32_t _H_type;
      _H_type H;
      typedef int32_t _W_type;
      _W_type W;

    VehicleCorners():
      header(),
      corners_length(0), corners(NULL),
      detection(),
      H(0),
      W(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->corners_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->corners_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->corners_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->corners_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->corners_length);
      for( uint32_t i = 0; i < corners_length; i++){
      offset += this->corners[i].serialize(outbuffer + offset);
      }
      offset += this->detection.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_H;
      u_H.real = this->H;
      *(outbuffer + offset + 0) = (u_H.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_H.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_H.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_H.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->H);
      union {
        int32_t real;
        uint32_t base;
      } u_W;
      u_W.real = this->W;
      *(outbuffer + offset + 0) = (u_W.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_W.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_W.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_W.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->W);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t corners_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      corners_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      corners_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      corners_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->corners_length);
      if(corners_lengthT > corners_length)
        this->corners = (geometry_msgs::Point32*)realloc(this->corners, corners_lengthT * sizeof(geometry_msgs::Point32));
      corners_length = corners_lengthT;
      for( uint32_t i = 0; i < corners_length; i++){
      offset += this->st_corners.deserialize(inbuffer + offset);
        memcpy( &(this->corners[i]), &(this->st_corners), sizeof(geometry_msgs::Point32));
      }
      offset += this->detection.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_H;
      u_H.base = 0;
      u_H.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_H.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_H.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_H.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->H = u_H.real;
      offset += sizeof(this->H);
      union {
        int32_t real;
        uint32_t base;
      } u_W;
      u_W.base = 0;
      u_W.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_W.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_W.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_W.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->W = u_W.real;
      offset += sizeof(this->W);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/VehicleCorners"; };
    const char * getMD5(){ return "f601f02846ab710f0645608b8ce77e71"; };

  };

}
#endif