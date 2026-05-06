#ifndef __USER_HEADERS_H
#define __USER_HEADERS_H

#include "main.h"
#include "tim.h"



#define CHK_OK                  1U
#define STATE_MAIN_INIT         0U





#include "database.h"

//Layer 4
#include "flash_if.h"

//Layer 3
#include "user_mem.h"
#include "SETTIMER.h"
//Layer 2
#include "LTIME.h"


static inline void Setbit(uint32_t flag, uint32_t bit)
{
  flag_PF_mem = flag | (1UL << bit);
}

static inline void Clrbit(uint32_t flag, uint32_t bit)
{
  flag_PF_mem = flag & ~(1UL << bit);
}

static inline uint32_t Chkbit(uint32_t flag, uint32_t bit)
{
  return ((flag & (1UL << bit)) != 0U) ? CHK_OK : 0U;
}



#endif /* __USER_HEADERS_H */
