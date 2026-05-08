#ifndef __ESC_CONTROL_H
#define __ESC_CONTROL_H

#include "main.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define ESC_CONTROL_COUNT             4U

#define ESC_CONTROL_ID_1              0U
#define ESC_CONTROL_ID_2              1U
#define ESC_CONTROL_ID_3              2U
#define ESC_CONTROL_ID_4              3U

#define ESC_CONTROL_PWM_MIN_US        1000U
#define ESC_CONTROL_PWM_STOP_US       1000U
#define ESC_CONTROL_PWM_MAX_US        2000U


///// VARIABLES ///////////////////////////////////////////////////////////////
extern volatile uint16_t ESC_PWM_US[ESC_CONTROL_COUNT];


///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void ESC_Control_Init(void);
extern void ESC_Control_SetPwm(uint8_t esc_id, uint16_t pwm_us);
extern void ESC_Control_SetAll(uint16_t pwm_us);
extern uint16_t ESC_Control_GetPwm(uint8_t esc_id);
extern void ESC_Control_Apply(void);

#endif

