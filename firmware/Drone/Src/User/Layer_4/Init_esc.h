#ifndef __INIT_ESC_H
#define __INIT_ESC_H

#include "main.h"
#include "tim.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define INIT_ESC_COUNT             4U

#define INIT_ESC_ID_1              0U
#define INIT_ESC_ID_2              1U
#define INIT_ESC_ID_3              2U
#define INIT_ESC_ID_4              3U

#define INIT_ESC_PWM_MIN_US        1000U
#define INIT_ESC_PWM_STOP_US       1000U
#define INIT_ESC_PWM_MAX_US        2000U

///// VARIABLES ///////////////////////////////////////////////////////////////

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Init_ESC_Init(void);
extern void Init_ESC_Start(void);
extern void Init_ESC_Stop(void);
extern void Init_ESC_SetPwm(uint8_t esc_id, uint16_t pwm_us);
extern void Init_ESC_SetAll(uint16_t pwm_us);

#endif
