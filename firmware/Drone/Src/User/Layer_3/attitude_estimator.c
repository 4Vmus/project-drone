///// INCLUDES ////////////////////////////////////////////////////////////////
#include "attitude_estimator.h"


///// VARIABLES ///////////////////////////////////////////////////////////////
static Attitude_Estimator_Data_t attitude_estimator_data;


///// FUNCTIONS ///////////////////////////////////////////////////////////////
void Attitude_Estimator_Init(void)
{
}

void Attitude_Estimator_Update(float dt_sec)
{
  (void)dt_sec;
}

const Attitude_Estimator_Data_t *Attitude_Estimator_GetData(void)
{
  return &attitude_estimator_data;
}
