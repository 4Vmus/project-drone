#ifndef __PID_CONTROL_H
#define __PID_CONTROL_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef struct
{
  float kp;
  float ki;
  float kd;
  float integrator;
  float previous_error;
  float output_min;
  float output_max;
} PID_Control_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void PID_Control_Init(PID_Control_t *pid);
extern float PID_Control_Update(PID_Control_t *pid, float target, float measured, float dt_sec);

#endif
