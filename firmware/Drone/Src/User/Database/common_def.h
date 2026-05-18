#ifndef __COMMON_DEF_H
#define __COMMON_DEF_H

#include "main.h"

///// DEFINES /////////////////////////////////////////////////////////////////
#define CHK_CLEAR               0U

#define Setbit(x, y)            ((x) |=  (1UL << (y)))
#define Clrbit(x, y)            ((x) &= ~(1UL << (y)))
#define Chkbit(x, y)            ((x) &   (1UL << (y)))
#define Toglbit(x, y)           ((x) ^=  (1UL << (y)))

#endif
