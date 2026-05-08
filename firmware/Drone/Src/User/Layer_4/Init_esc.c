///// INCLUDES ////////////////////////////////////////////////////////////////
#include "Init_esc.h"


///// VARIABLES ///////////////////////////////////////////////////////////////
static const uint32_t INIT_ESC_TIM_CHANNEL[INIT_ESC_COUNT] =
{
  TIM_CHANNEL_1,
  TIM_CHANNEL_2,
  TIM_CHANNEL_3,
  TIM_CHANNEL_4
};


///// FUNCTIONS ///////////////////////////////////////////////////////////////
static uint16_t Init_ESC_ClampPwm(uint16_t pwm_us)
{
  if (pwm_us < INIT_ESC_PWM_MIN_US)
  {
    return INIT_ESC_PWM_MIN_US;
  }

  if (pwm_us > INIT_ESC_PWM_MAX_US)
  {
    return INIT_ESC_PWM_MAX_US;
  }

  return pwm_us;
}

void Init_ESC_Init(void)
{
  Init_ESC_SetAll(INIT_ESC_PWM_STOP_US);
  Init_ESC_Start();
}

void Init_ESC_Start(void)
{
  for (uint8_t esc_id = 0U; esc_id < INIT_ESC_COUNT; esc_id++)
  {
    (void)HAL_TIM_PWM_Start(&htim1, INIT_ESC_TIM_CHANNEL[esc_id]);
  }
}

void Init_ESC_Stop(void)
{
  Init_ESC_SetAll(INIT_ESC_PWM_STOP_US);

  for (uint8_t esc_id = 0U; esc_id < INIT_ESC_COUNT; esc_id++)
  {
    (void)HAL_TIM_PWM_Stop(&htim1, INIT_ESC_TIM_CHANNEL[esc_id]);
  }
}

void Init_ESC_SetPwm(uint8_t esc_id, uint16_t pwm_us)
{
  if (esc_id >= INIT_ESC_COUNT)
  {
    return;
  }

  __HAL_TIM_SET_COMPARE(&htim1, INIT_ESC_TIM_CHANNEL[esc_id], Init_ESC_ClampPwm(pwm_us));
}

void Init_ESC_SetAll(uint16_t pwm_us)
{
  uint16_t clamped_pwm = Init_ESC_ClampPwm(pwm_us);

  for (uint8_t esc_id = 0U; esc_id < INIT_ESC_COUNT; esc_id++)
  {
    __HAL_TIM_SET_COMPARE(&htim1, INIT_ESC_TIM_CHANNEL[esc_id], clamped_pwm);
  }
}
