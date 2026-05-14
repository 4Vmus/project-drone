#ifndef __FAILSAFE_H
#define __FAILSAFE_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef enum
{
  FAILSAFE_STATUS_OK = 0,
  FAILSAFE_STATUS_ACTIVE
} Failsafe_Status_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Failsafe_Init(void);
extern void Failsafe_Update(void);
extern Failsafe_Status_t Failsafe_GetStatus(void);

#endif
