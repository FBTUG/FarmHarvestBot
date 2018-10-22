#ifndef _ROS_duckietown_msgs_ObstacleProjectedDetectionList_h
#define _ROS_duckietown_msgs_ObstacleProjectedDetectionList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "duckietown_msgs/ObstacleProjectedDetection.h"

namespace duckietown_msgs
{

  class ObstacleProjectedDetectionList : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t list_length;
      typedef duckietown_msgs::ObstacleProjectedDetection _list_type;
      _list_type st_list;
      _list_type * list;

    ObstacleProjectedDetectionList():
      header(),
      list_length(0), list(NULL)
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
        this->list = (duckietown_msgs::ObstacleProjectedDetection*)realloc(this->list, list_lengthT * sizeof(duckietown_msgs::ObstacleProjectedDetection));
      list_length = list_lengthT;
      for( uint32_t i = 0; i < list_length; i++){
      offset += this->st_list.deserialize(inbuffer + offset);
        memcpy( &(this->list[i]), &(this->st_list), sizeof(duckietown_msgs::ObstacleProjectedDetection));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/ObstacleProjectedDetectionList"; };
    const char * getMD5(){ return "11b067403fefa6151edc8b44e25edac3"; };

  };

}
#endif