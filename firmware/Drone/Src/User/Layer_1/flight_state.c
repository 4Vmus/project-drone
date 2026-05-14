///// INCLUDES ////////////////////////////////////////////////////////////////
#include "flight_state.h"


///// VARIABLES ///////////////////////////////////////////////////////////////
static Flight_State_t flight_state = FLIGHT_STATE_BOOT;


///// FUNCTIONS ///////////////////////////////////////////////////////////////
void Flight_State_Init(void)
{
  flight_state = FLIGHT_STATE_INIT;
}

void Flight_State_Update(void)
{
}

void Flight_State_Set(Flight_State_t state)
{
  flight_state = state;
}

Flight_State_t Flight_State_Get(void)
{
  return flight_state;
}
