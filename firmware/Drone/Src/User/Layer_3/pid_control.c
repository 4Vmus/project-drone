///// INCLUDES ////////////////////////////////////////////////////////////////
#include "pid_control.h"


///// FUNCTIONS ///////////////////////////////////////////////////////////////
void PID_Control_Init(PID_Control_t *pid)
{
  if (pid == 0)
  {
    return;
  }

  pid->integrator = 0.0f;
  pid->previous_error = 0.0f;
}

float PID_Control_Update(PID_Control_t *pid, float target, float measured, float dt_sec)
{
  float error;
  float derivative;
  float output;

  if ((pid == 0) || (dt_sec <= 0.0f))
  {
    return 0.0f;
  }

  error = target - measured;
  pid->integrator += error * dt_sec;
  derivative = (error - pid->previous_error) / dt_sec;
  pid->previous_error = error;

  output = (pid->kp * error) + (pid->ki * pid->integrator) + (pid->kd * derivative);

  if (output < pid->output_min)
  {
    output = pid->output_min;
  }
  else if (output > pid->output_max)
  {
    output = pid->output_max;
  }

  return output;
}
