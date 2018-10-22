#ifndef _ROS_SERVICE_GetImageCoord_h
#define _ROS_SERVICE_GetImageCoord_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "duckietown_msgs/Vector2D.h"

namespace ground_projection
{

static const char GETIMAGECOORD[] = "ground_projection/GetImageCoord";

  class GetImageCoordRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _gp_type;
      _gp_type gp;

    GetImageCoordRequest():
      gp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->gp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->gp.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETIMAGECOORD; };
    const char * getMD5(){ return "cb06b1906fc6f1f5910a7d2012f835c0"; };

  };

  class GetImageCoordResponse : public ros::Msg
  {
    public:
      typedef duckietown_msgs::Vector2D _normalized_uv_type;
      _normalized_uv_type normalized_uv;

    GetImageCoordResponse():
      normalized_uv()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->normalized_uv.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->normalized_uv.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETIMAGECOORD; };
    const char * getMD5(){ return "7e079b9787496ba75117334836e96c45"; };

  };

  class GetImageCoord {
    public:
    typedef GetImageCoordRequest Request;
    typedef GetImageCoordResponse Response;
  };

}
#endif
