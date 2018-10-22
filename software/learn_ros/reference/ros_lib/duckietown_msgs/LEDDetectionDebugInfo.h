#ifndef _ROS_duckietown_msgs_LEDDetectionDebugInfo_h
#define _ROS_duckietown_msgs_LEDDetectionDebugInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CompressedImage.h"
#include "duckietown_msgs/Vector2D.h"
#include "duckietown_msgs/LEDDetectionArray.h"

namespace duckietown_msgs
{

  class LEDDetectionDebugInfo : public ros::Msg
  {
    public:
      typedef uint8_t _state_type;
      _state_type state;
      typedef float _capture_progress_type;
      _capture_progress_type capture_progress;
      uint32_t cell_size[2];
      float crop_rect_norm[4];
      typedef sensor_msgs::CompressedImage _variance_map_type;
      _variance_map_type variance_map;
      uint32_t candidates_length;
      typedef duckietown_msgs::Vector2D _candidates_type;
      _candidates_type st_candidates;
      _candidates_type * candidates;
      typedef duckietown_msgs::LEDDetectionArray _led_all_unfiltered_type;
      _led_all_unfiltered_type led_all_unfiltered;

    LEDDetectionDebugInfo():
      state(0),
      capture_progress(0),
      cell_size(),
      crop_rect_norm(),
      variance_map(),
      candidates_length(0), candidates(NULL),
      led_all_unfiltered()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_capture_progress;
      u_capture_progress.real = this->capture_progress;
      *(outbuffer + offset + 0) = (u_capture_progress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_capture_progress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_capture_progress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_capture_progress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->capture_progress);
      for( uint32_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->cell_size[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_size[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cell_size[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cell_size[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_size[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_crop_rect_normi;
      u_crop_rect_normi.real = this->crop_rect_norm[i];
      *(outbuffer + offset + 0) = (u_crop_rect_normi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_crop_rect_normi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_crop_rect_normi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_crop_rect_normi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->crop_rect_norm[i]);
      }
      offset += this->variance_map.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->candidates_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->candidates_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->candidates_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->candidates_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->candidates_length);
      for( uint32_t i = 0; i < candidates_length; i++){
      offset += this->candidates[i].serialize(outbuffer + offset);
      }
      offset += this->led_all_unfiltered.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_capture_progress;
      u_capture_progress.base = 0;
      u_capture_progress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_capture_progress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_capture_progress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_capture_progress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->capture_progress = u_capture_progress.real;
      offset += sizeof(this->capture_progress);
      for( uint32_t i = 0; i < 2; i++){
      this->cell_size[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->cell_size[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cell_size[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cell_size[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cell_size[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_crop_rect_normi;
      u_crop_rect_normi.base = 0;
      u_crop_rect_normi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_crop_rect_normi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_crop_rect_normi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_crop_rect_normi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->crop_rect_norm[i] = u_crop_rect_normi.real;
      offset += sizeof(this->crop_rect_norm[i]);
      }
      offset += this->variance_map.deserialize(inbuffer + offset);
      uint32_t candidates_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      candidates_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->candidates_length);
      if(candidates_lengthT > candidates_length)
        this->candidates = (duckietown_msgs::Vector2D*)realloc(this->candidates, candidates_lengthT * sizeof(duckietown_msgs::Vector2D));
      candidates_length = candidates_lengthT;
      for( uint32_t i = 0; i < candidates_length; i++){
      offset += this->st_candidates.deserialize(inbuffer + offset);
        memcpy( &(this->candidates[i]), &(this->st_candidates), sizeof(duckietown_msgs::Vector2D));
      }
      offset += this->led_all_unfiltered.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/LEDDetectionDebugInfo"; };
    const char * getMD5(){ return "be212adc91f6527a99fc828df2018200"; };

  };

}
#endif