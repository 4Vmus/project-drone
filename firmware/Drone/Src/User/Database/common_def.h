#ifndef __COMMON_DEF_H
#define __COMMON_DEF_H

#include "main.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define CHK_OK                  1U

#define Setbit(x, y)            ((x) |=  (1UL << (y)))
#define Clrbit(x, y)            ((x) &= ~(1UL << (y)))
#define Chkbit(x, y)            ((x) &   (1UL << (y)))
#define Ifbit(x, y)             (((x) >> (y)) & 1UL)
#define Toglbit(x, y)           ((x) ^=  (1UL << (y)))

#endif
