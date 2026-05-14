#ifndef __ESC_CONTROL_H
#define __ESC_CONTROL_H

#include "main.h"
#include "drone_config.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define ESC_CONTROL_COUNT             DRONE_MOTOR_COUNT

#define ESC_CONTROL_ID_1              DRONE_MOTOR_ID_1
#define ESC_CONTROL_ID_2              DRONE_MOTOR_ID_2
#define ESC_CONTROL_ID_3              DRONE_MOTOR_ID_3
#define ESC_CONTROL_ID_4              DRONE_MOTOR_ID_4

#define ESC_CONTROL_PWM_MIN_US        DRONE_ESC_PWM_MIN_US
#define ESC_CONTROL_PWM_STOP_US       DRONE_ESC_PWM_STOP_US
#define ESC_CONTROL_PWM_MAX_US        DRONE_ESC_PWM_MAX_US


///// VARIABLES ///////////////////////////////////////////////////////////////
extern volatile uint16_t ESC_PWM_US[ESC_CONTROL_COUNT];


///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void ESC_Control_Init(void);
extern void ESC_Control_SetPwm(uint8_t esc_id, uint16_t pwm_us);
extern void ESC_Control_SetAll(uint16_t pwm_us);
extern uint16_t ESC_Control_GetPwm(uint8_t esc_id);
extern void ESC_Control_Apply(void);

#endif
