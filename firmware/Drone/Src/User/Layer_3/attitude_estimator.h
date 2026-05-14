#ifndef __ATTITUDE_ESTIMATOR_H
#define __ATTITUDE_ESTIMATOR_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef struct
{
  float roll_deg;
  float pitch_deg;
  float yaw_deg;
} Attitude_Estimator_Data_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Attitude_Estimator_Init(void);
extern void Attitude_Estimator_Update(float dt_sec);
extern const Attitude_Estimator_Data_t *Attitude_Estimator_GetData(void);

#endif
