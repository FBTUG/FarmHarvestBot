#ifndef _ROS_duckietown_msgs_Vsample_h
#define _ROS_duckietown_msgs_Vsample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class Vsample : public ros::Msg
  {
    public:
      typedef float _d_L_type;
      _d_L_type d_L;
      typedef float _d_R_type;
      _d_R_type d_R;
      typedef float _dt_type;
      _dt_type dt;
      typedef float _theta_angle_pose_delta_type;
      _theta_angle_pose_delta_type theta_angle_pose_delta;
      typedef float _x_axis_pose_delta_type;
      _x_axis_pose_delta_type x_axis_pose_delta;
      typedef float _y_axis_pose_delta_type;
      _y_axis_pose_delta_type y_axis_pose_delta;

    Vsample():
      d_L(0),
      d_R(0),
      dt(0),
      theta_angle_pose_delta(0),
      x_axis_pose_delta(0),
      y_axis_pose_delta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_d_L;
      u_d_L.real = this->d_L;
      *(outbuffer + offset + 0) = (u_d_L.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d_L.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d_L.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d_L.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d_L);
      union {
        float real;
        uint32_t base;
      } u_d_R;
      u_d_R.real = this->d_R;
      *(outbuffer + offset + 0) = (u_d_R.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d_R.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d_R.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d_R.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d_R);
      union {
        float real;
        uint32_t base;
      } u_dt;
      u_dt.real = this->dt;
      *(outbuffer + offset + 0) = (u_dt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dt);
      union {
        float real;
        uint32_t base;
      } u_theta_angle_pose_delta;
      u_theta_angle_pose_delta.real = this->theta_angle_pose_delta;
      *(outbuffer + offset + 0) = (u_theta_angle_pose_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_angle_pose_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_angle_pose_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_angle_pose_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_angle_pose_delta);
      union {
        float real;
        uint32_t base;
      } u_x_axis_pose_delta;
      u_x_axis_pose_delta.real = this->x_axis_pose_delta;
      *(outbuffer + offset + 0) = (u_x_axis_pose_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_axis_pose_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_axis_pose_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_axis_pose_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_axis_pose_delta);
      union {
        float real;
        uint32_t base;
      } u_y_axis_pose_delta;
      u_y_axis_pose_delta.real = this->y_axis_pose_delta;
      *(outbuffer + offset + 0) = (u_y_axis_pose_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_axis_pose_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_axis_pose_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_axis_pose_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_axis_pose_delta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_d_L;
      u_d_L.base = 0;
      u_d_L.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d_L.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d_L.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d_L.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d_L = u_d_L.real;
      offset += sizeof(this->d_L);
      union {
        float real;
        uint32_t base;
      } u_d_R;
      u_d_R.base = 0;
      u_d_R.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d_R.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d_R.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d_R.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->d_R = u_d_R.real;
      offset += sizeof(this->d_R);
      union {
        float real;
        uint32_t base;
      } u_dt;
      u_dt.base = 0;
      u_dt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dt = u_dt.real;
      offset += sizeof(this->dt);
      union {
        float real;
        uint32_t base;
      } u_theta_angle_pose_delta;
      u_theta_angle_pose_delta.base = 0;
      u_theta_angle_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta_angle_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta_angle_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta_angle_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta_angle_pose_delta = u_theta_angle_pose_delta.real;
      offset += sizeof(this->theta_angle_pose_delta);
      union {
        float real;
        uint32_t base;
      } u_x_axis_pose_delta;
      u_x_axis_pose_delta.base = 0;
      u_x_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_axis_pose_delta = u_x_axis_pose_delta.real;
      offset += sizeof(this->x_axis_pose_delta);
      union {
        float real;
        uint32_t base;
      } u_y_axis_pose_delta;
      u_y_axis_pose_delta.base = 0;
      u_y_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_axis_pose_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_axis_pose_delta = u_y_axis_pose_delta.real;
      offset += sizeof(this->y_axis_pose_delta);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Vsample"; };
    const char * getMD5(){ return "636e6e791af118be8338c8ab7fbd00e7"; };

  };

}
#endif