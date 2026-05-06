#include "headers.h"

__root __no_init int32_t sys_on_time @ (RAM_ADDR_VAR + 0U);
__root __no_init int32_t bT1mSec @ (RAM_ADDR_VAR + 4U);
__root __no_init uint32_t flag_PF_mem @ (RAM_ADDR_VAR + 8U);
__root __no_init uint32_t flag_mem_access @ (RAM_ADDR_VAR + 12U);
__root __no_init uint32_t ECU_MAIN_STATE @ (RAM_ADDR_VAR + 16U);
__root __no_init uint32_t Task_Chk_Cnt[10] @ (RAM_ADDR_VAR + 96U);

__root __no_init uint32_t FLASH_WRITE_CNT @ (RAM_ADDR_CONST + 0U);

__root __no_init int32_t MEM_HW_VERSION @ (RAM_ADDR_CONST + DB_SIZE_CONST - 16U);
__root __no_init int32_t MEM_SW_VERSION @ (RAM_ADDR_CONST + DB_SIZE_CONST - 12U);
__root __no_init int32_t MEM_CONST_INIT_FLAG @ (RAM_ADDR_CONST + DB_SIZE_CONST - 8U);
__root __no_init int32_t CONST_CHKSUM @ (RAM_ADDR_CONST + DB_SIZE_CONST - 4U);

void Init_Const(void)
{
  for (uint32_t i = 0; i < (DB_SIZE_CONST / sizeof(uint32_t)); i++)
  {
    *((uint32_t *)(RAM_ADDR_CONST + (i * sizeof(uint32_t)))) = 0U;
  }
	
	FLASH_WRITE_CNT = 0;
	
	MEM_HW_VERSION = 0x010001;
	MEM_SW_VERSION = 0x010001;

  MEM_CONST_INIT_FLAG = 0x5555;
  CONST_CHKSUM = 0;
}

void Init_Var(void)
{
	sys_on_time = 0;
	bT1mSec = 0;
	flag_PF_mem = 0;
	flag_mem_access = 0;
	ECU_MAIN_STATE = 0;
	
	for(int i = 0; i < 10; i++)
	{
		Task_Chk_Cnt[i] = 0;
	}
	
	
	
	
	
}
