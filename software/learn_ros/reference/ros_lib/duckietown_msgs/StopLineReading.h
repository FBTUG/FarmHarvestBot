#ifndef _ROS_duckietown_msgs_StopLineReading_h
#define _ROS_duckietown_msgs_StopLineReading_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace duckietown_msgs
{

  class StopLineReading : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _stop_line_detected_type;
      _stop_line_detected_type stop_line_detected;
      typedef bool _at_stop_line_type;
      _at_stop_line_type at_stop_line;
      typedef geometry_msgs::Point _stop_line_point_type;
      _stop_line_point_type stop_line_point;

    StopLineReading():
      header(),
      stop_line_detected(0),
      at_stop_line(0),
      stop_line_point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_stop_line_detected;
      u_stop_line_detected.real = this->stop_line_detected;
      *(outbuffer + offset + 0) = (u_stop_line_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stop_line_detected);
      union {
        bool real;
        uint8_t base;
      } u_at_stop_line;
      u_at_stop_line.real = this->at_stop_line;
      *(outbuffer + offset + 0) = (u_at_stop_line.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->at_stop_line);
      offset += this->stop_line_point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_stop_line_detected;
      u_stop_line_detected.base = 0;
      u_stop_line_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stop_line_detected = u_stop_line_detected.real;
      offset += sizeof(this->stop_line_detected);
      union {
        bool real;
        uint8_t base;
      } u_at_stop_line;
      u_at_stop_line.base = 0;
      u_at_stop_line.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->at_stop_line = u_at_stop_line.real;
      offset += sizeof(this->at_stop_line);
      offset += this->stop_line_point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/StopLineReading"; };
    const char * getMD5(){ return "735fe9e9ff1e4d7460bbf69ab2720ae0"; };

  };

}
#endif