///// INCLUDES ////////////////////////////////////////////////////////////////
#include "failsafe.h"


///// VARIABLES ///////////////////////////////////////////////////////////////
static Failsafe_Status_t failsafe_status = FAILSAFE_STATUS_OK;


///// FUNCTIONS ///////////////////////////////////////////////////////////////
void Failsafe_Init(void)
{
  failsafe_status = FAILSAFE_STATUS_OK;
}

void Failsafe_Update(void)
{
}

Failsafe_Status_t Failsafe_GetStatus(void)
{
  return failsafe_status;
}
