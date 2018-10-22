#ifndef _ROS_duckietown_msgs_TagInfo_h
#define _ROS_duckietown_msgs_TagInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class TagInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _id_type;
      _id_type id;
      typedef uint8_t _tag_type_type;
      _tag_type_type tag_type;
      typedef const char* _street_name_type;
      _street_name_type street_name;
      typedef uint8_t _traffic_sign_type_type;
      _traffic_sign_type_type traffic_sign_type;
      typedef const char* _vehicle_name_type;
      _vehicle_name_type vehicle_name;
      typedef float _location_type;
      _location_type location;
      enum { S_NAME = 0 };
      enum { SIGN = 1 };
      enum { LIGHT = 2 };
      enum { LOCALIZE = 3 };
      enum { VEHICLE = 4 };
      enum { STOP = 5 };
      enum { YIELD = 6 };
      enum { NO_RIGHT_TURN = 7 };
      enum { NO_LEFT_TURN = 8 };
      enum { ONEWAY_RIGHT = 9 };
      enum { ONEWAY_LEFT = 10 };
      enum { FOUR_WAY = 11 };
      enum { RIGHT_T_INTERSECT = 12 };
      enum { LEFT_T_INTERSECT = 13 };
      enum { T_INTERSECTION = 14 };
      enum { DO_NOT_ENTER = 15 };
      enum { PEDESTRIAN = 16 };
      enum { T_LIGHT_AHEAD = 17 };
      enum { DUCK_CROSSING = 18 };

    TagInfo():
      header(),
      id(0),
      tag_type(0),
      street_name(""),
      traffic_sign_type(0),
      vehicle_name(""),
      location(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->tag_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tag_type);
      uint32_t length_street_name = strlen(this->street_name);
      varToArr(outbuffer + offset, length_street_name);
      offset += 4;
      memcpy(outbuffer + offset, this->street_name, length_street_name);
      offset += length_street_name;
      *(outbuffer + offset + 0) = (this->traffic_sign_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->traffic_sign_type);
      uint32_t length_vehicle_name = strlen(this->vehicle_name);
      varToArr(outbuffer + offset, length_vehicle_name);
      offset += 4;
      memcpy(outbuffer + offset, this->vehicle_name, length_vehicle_name);
      offset += length_vehicle_name;
      union {
        float real;
        uint32_t base;
      } u_location;
      u_location.real = this->location;
      *(outbuffer + offset + 0) = (u_location.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_location.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_location.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_location.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      this->tag_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->tag_type);
      uint32_t length_street_name;
      arrToVar(length_street_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_street_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_street_name-1]=0;
      this->street_name = (char *)(inbuffer + offset-1);
      offset += length_street_name;
      this->traffic_sign_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->traffic_sign_type);
      uint32_t length_vehicle_name;
      arrToVar(length_vehicle_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_vehicle_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_vehicle_name-1]=0;
      this->vehicle_name = (char *)(inbuffer + offset-1);
      offset += length_vehicle_name;
      union {
        float real;
        uint32_t base;
      } u_location;
      u_location.base = 0;
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->location = u_location.real;
      offset += sizeof(this->location);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/TagInfo"; };
    const char * getMD5(){ return "1a498b8e4c39d9cac00bfc0db23fe7f0"; };

  };

}
#endif