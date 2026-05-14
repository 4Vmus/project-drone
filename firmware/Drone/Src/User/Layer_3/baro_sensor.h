#ifndef __BARO_SENSOR_H
#define __BARO_SENSOR_H

#include "main.h"

///// TYPES ///////////////////////////////////////////////////////////////////
typedef struct
{
  float pressure_pa;
  float temperature_c;
  float altitude_m;
} Baro_Sensor_Data_t;

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Baro_Sensor_Init(void);
extern void Baro_Sensor_Update(void);
extern const Baro_Sensor_Data_t *Baro_Sensor_GetData(void);

#endif
