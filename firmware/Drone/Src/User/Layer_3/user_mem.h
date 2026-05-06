
#ifndef _USER_MEM_H_
#define _USER_MEM_H_

#include "main.h"
#include "flash_if.h"

///// DEFINE //////////////////////////////////////////////////////////////////
#define FLASH_ADDR_VAR      ((uint32_t)0x080E0000)
#define FLASH_ADDR_CONST		((uint32_t)0x080E1000)


#define	MEM_NORMAL				  0x00
#define MEM_WRITE				    0x01
#define MEM_READ				    0x02
#define MEM_INIT				    0x04
#define MEM_INIT_VAR				0x08


#define ID_PF_MEM_INIT				    0
#define ID_PF_VAR_READ				    1
#define ID_PF_CONST_READ			    2
#define ID_PF_CONST_READ_DATA			3
#define ID_PF_CONST_READ_INIT			4
#define ID_PF_CONST_READ_CHKSUM   5
#define ID_PF_CLONE_VAR_READ			6
#define ID_PF_CLONE_CONST_READ    7
#define ID_PF_MEM_FIRST           8


#define MAX_SAVE_DATA		10

///// VARIABLES///////////////////////////////////////////////////////////////

///// FUNCTION ///////////////////////////////////////////////////////////////
void fun_Init_mem(void);
void Task_Mem(void);
void ReadMem(void);
void WriteMem(void);

#endif
