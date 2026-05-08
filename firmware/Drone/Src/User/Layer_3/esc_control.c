///// INCLUDES ////////////////////////////////////////////////////////////////
#include "headers.h"


///// VARIABLES ///////////////////////////////////////////////////////////////
volatile uint16_t ESC_PWM_US[ESC_CONTROL_COUNT];


///// FUNCTIONS ///////////////////////////////////////////////////////////////
static uint16_t ESC_Control_ClampPwm(uint16_t pwm_us)
{
  if (pwm_us < ESC_CONTROL_PWM_MIN_US)
  {
    return ESC_CONTROL_PWM_MIN_US;
  }

  if (pwm_us > ESC_CONTROL_PWM_MAX_US)
  {
    return ESC_CONTROL_PWM_MAX_US;
  }

  return pwm_us;
}

void ESC_Control_Init(void)
{
  ESC_Control_SetAll(ESC_CONTROL_PWM_STOP_US);
}

void ESC_Control_SetPwm(uint8_t esc_id, uint16_t pwm_us)
{
  if (esc_id >= ESC_CONTROL_COUNT)
  {
    return;
  }

  ESC_PWM_US[esc_id] = ESC_Control_ClampPwm(pwm_us);
}

void ESC_Control_SetAll(uint16_t pwm_us)
{
  uint16_t clamped_pwm = ESC_Control_ClampPwm(pwm_us);

  for (uint8_t esc_id = 0U; esc_id < ESC_CONTROL_COUNT; esc_id++)
  {
    ESC_PWM_US[esc_id] = clamped_pwm;
  }
}

uint16_t ESC_Control_GetPwm(uint8_t esc_id)
{
  if (esc_id >= ESC_CONTROL_COUNT)
  {
    return ESC_CONTROL_PWM_STOP_US;
  }

  return ESC_PWM_US[esc_id];
}

void ESC_Control_Apply(void)
{
  for (uint8_t esc_id = 0U; esc_id < ESC_CONTROL_COUNT; esc_id++)
  {
    Init_ESC_SetPwm(esc_id, ESC_PWM_US[esc_id]);
  }
}
