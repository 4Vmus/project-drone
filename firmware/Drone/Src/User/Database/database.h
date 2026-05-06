
#ifndef _DATABASE_H_
#define _DATABASE_H_


///// DEFINE //////////////////////////////////////////////////////////////////

#define	RAM_BASE			    D1_DTCMRAM_BASE
#define	RAM_ADDR_VAR		  	(RAM_BASE + 0x000000U)
#define	RAM_ADDR_CONST		(RAM_BASE + 0x001000U)


#define	DB_SIZE_VAR			    (4096U)
#define	DB_SIZE_CONST		    (4096U)





//-------------file---------------------------------------------------------
extern int32_t sys_on_time;
extern int32_t bT1mSec;
extern uint32_t flag_PF_mem;
extern uint32_t flag_mem_access;
extern uint32_t ECU_MAIN_STATE;


extern uint32_t Task_Chk_Cnt[10];






//--------------------------------------------------------------------------------------------
extern uint32_t FLASH_WRITE_CNT;



extern int32_t MEM_HW_VERSION;
extern int32_t MEM_SW_VERSION;
extern int32_t MEM_CONST_INIT_FLAG;
extern int32_t CONST_CHKSUM;


extern void Init_Const(void);
extern void Init_Var(void);

#endif

