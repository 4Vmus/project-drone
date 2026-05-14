#ifndef __IMU_SENSOR_H
#define __IMU_SENSOR_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef struct
{
  float gyro_x;
  float gyro_y;
  float gyro_z;
  float accel_x;
  float accel_y;
  float accel_z;
} IMU_Sensor_Data_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void IMU_Sensor_Init(void);
extern void IMU_Sensor_Update(void);
extern const IMU_Sensor_Data_t *IMU_Sensor_GetData(void);

#endif
