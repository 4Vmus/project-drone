#ifndef __DRONE_CONFIG_H
#define __DRONE_CONFIG_H

#include "main.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define DRONE_MOTOR_COUNT                 4U

#define DRONE_MOTOR_ID_1                  0U
#define DRONE_MOTOR_ID_2                  1U
#define DRONE_MOTOR_ID_3                  2U
#define DRONE_MOTOR_ID_4                  3U

#define DRONE_ESC_PWM_MIN_US              1000U
#define DRONE_ESC_PWM_STOP_US             1000U
#define DRONE_ESC_PWM_MAX_US              2000U

#define DRONE_CONTROL_LOOP_HZ             1000U

#endif
