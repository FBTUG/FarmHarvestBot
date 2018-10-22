#ifndef _ROS_duckietown_msgs_LEDInterpreter_h
#define _ROS_duckietown_msgs_LEDInterpreter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class LEDInterpreter : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _vehicle_type;
      _vehicle_type vehicle;
      typedef bool _trafficlight_type;
      _trafficlight_type trafficlight;

    LEDInterpreter():
      header(),
      vehicle(0),
      trafficlight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_vehicle;
      u_vehicle.real = this->vehicle;
      *(outbuffer + offset + 0) = (u_vehicle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle);
      union {
        bool real;
        uint8_t base;
      } u_trafficlight;
      u_trafficlight.real = this->trafficlight;
      *(outbuffer + offset + 0) = (u_trafficlight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trafficlight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_vehicle;
      u_vehicle.base = 0;
      u_vehicle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle = u_vehicle.real;
      offset += sizeof(this->vehicle);
      union {
        bool real;
        uint8_t base;
      } u_trafficlight;
      u_trafficlight.base = 0;
      u_trafficlight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trafficlight = u_trafficlight.real;
      offset += sizeof(this->trafficlight);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/LEDInterpreter"; };
    const char * getMD5(){ return "100d6a2c19dff0c3d52b5c327f7ecae9"; };

  };

}
#endif