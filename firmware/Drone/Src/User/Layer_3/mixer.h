#ifndef __MIXER_H
#define __MIXER_H

#include "main.h"
#include "drone_config.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef struct
{
  float throttle;
  float roll;
  float pitch;
  float yaw;
} Mixer_Command_t;

typedef struct
{
  uint16_t motor_us[DRONE_MOTOR_COUNT];
} Mixer_Output_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Mixer_Init(void);
extern void Mixer_Update(const Mixer_Command_t *command);
extern const Mixer_Output_t *Mixer_GetOutput(void);

#endif
