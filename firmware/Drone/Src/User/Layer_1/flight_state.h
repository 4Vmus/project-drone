#ifndef __FLIGHT_STATE_H
#define __FLIGHT_STATE_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef enum
{
  FLIGHT_STATE_BOOT = 0,
  FLIGHT_STATE_INIT,
  FLIGHT_STATE_DISARMED,
  FLIGHT_STATE_ARMED,
  FLIGHT_STATE_FAILSAFE
} Flight_State_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Flight_State_Init(void);
extern void Flight_State_Update(void);
extern void Flight_State_Set(Flight_State_t state);
extern Flight_State_t Flight_State_Get(void);

#endif
