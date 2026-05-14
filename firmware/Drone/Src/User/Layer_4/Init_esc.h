#ifndef __INIT_ESC_H
#define __INIT_ESC_H

#include "main.h"
#include "tim.h"
#include "drone_config.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define INIT_ESC_COUNT             DRONE_MOTOR_COUNT

#define INIT_ESC_ID_1              DRONE_MOTOR_ID_1
#define INIT_ESC_ID_2              DRONE_MOTOR_ID_2
#define INIT_ESC_ID_3              DRONE_MOTOR_ID_3
#define INIT_ESC_ID_4              DRONE_MOTOR_ID_4

#define INIT_ESC_PWM_MIN_US        DRONE_ESC_PWM_MIN_US
#define INIT_ESC_PWM_STOP_US       DRONE_ESC_PWM_STOP_US
#define INIT_ESC_PWM_MAX_US        DRONE_ESC_PWM_MAX_US

///// VARIABLES ///////////////////////////////////////////////////////////////

///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void Init_ESC_Init(void);
extern void Init_ESC_Start(void);
extern void Init_ESC_Stop(void);
extern void Init_ESC_SetPwm(uint8_t esc_id, uint16_t pwm_us);
extern void Init_ESC_SetAll(uint16_t pwm_us);

#endif
