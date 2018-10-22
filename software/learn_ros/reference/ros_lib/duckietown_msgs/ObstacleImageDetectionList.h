#ifndef _ROS_duckietown_msgs_ObstacleImageDetectionList_h
#define _ROS_duckietown_msgs_ObstacleImageDetectionList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "duckietown_msgs/ObstacleImageDetection.h"

namespace duckietown_msgs
{

  class ObstacleImageDetectionList : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t list_length;
      typedef duckietown_msgs::ObstacleImageDetection _list_type;
      _list_type st_list;
      _list_type * list;
      typedef float _imwidth_type;
      _imwidth_type imwidth;
      typedef float _imheight_type;
      _imheight_type imheight;

    ObstacleImageDetectionList():
      header(),
      list_length(0), list(NULL),
      imwidth(0),
      imheight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->list_length);
      for( uint32_t i = 0; i < list_length; i++){
      offset += this->list[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_imwidth;
      u_imwidth.real = this->imwidth;
      *(outbuffer + offset + 0) = (u_imwidth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imwidth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imwidth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imwidth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imwidth);
      union {
        float real;
        uint32_t base;
      } u_imheight;
      u_imheight.real = this->imheight;
      *(outbuffer + offset + 0) = (u_imheight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imheight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imheight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imheight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imheight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->list_length);
      if(list_lengthT > list_length)
        this->list = (duckietown_msgs::ObstacleImageDetection*)realloc(this->list, list_lengthT * sizeof(duckietown_msgs::ObstacleImageDetection));
      list_length = list_lengthT;
      for( uint32_t i = 0; i < list_length; i++){
      offset += this->st_list.deserialize(inbuffer + offset);
        memcpy( &(this->list[i]), &(this->st_list), sizeof(duckietown_msgs::ObstacleImageDetection));
      }
      union {
        float real;
        uint32_t base;
      } u_imwidth;
      u_imwidth.base = 0;
      u_imwidth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imwidth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imwidth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imwidth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imwidth = u_imwidth.real;
      offset += sizeof(this->imwidth);
      union {
        float real;
        uint32_t base;
      } u_imheight;
      u_imheight.base = 0;
      u_imheight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imheight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imheight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imheight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imheight = u_imheight.real;
      offset += sizeof(this->imheight);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/ObstacleImageDetectionList"; };
    const char * getMD5(){ return "bb443595d23936bacf0f853c0dbaa48c"; };

  };

}
#endif