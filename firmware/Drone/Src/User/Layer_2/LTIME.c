///// INCLUDES ////////////////////////////////////////////////////////////////
#include "headers.h"


///// DEFINE //////////////////////////////////////////////////////////////////


///// VARIABLES ///////////////////////////////////////////////////////////////


/*******************************************************************************    
* Function Name  : Time_1mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_1mSEC_Action(void)
{
  
	if(bT1mSec == 1)
	{  
//Code Start ----------------------------------------------------------------

		SetTimer_Finish_Time();

		bT1mSec = 0;

//Code End -----------------------------------------------------------------
	}

}




/*******************************************************************************    
* Function Name  : Time_10mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_10mSEC_Action(void)
{
	SetTimer(TID_BASE_10mSEC,	TID_10mSEC,	Time_10mSEC_Action);

//Code Start ----------------------------------------------------------------
  
  
        
//Code End -----------------------------------------------------------------

}



 unsigned char LED_Toggle_Cnt;
/*******************************************************************************    
* Function Name  : Time_50mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_50mSEC_Action(void)
{
  SetTimer(TID_BASE_50mSEC,	TID_50mSEC,	Time_50mSEC_Action);
//Code Start ----------------------------------------------------------------
  

  

  // CH1 is JSON-only. Modbus CH1 scheduler disabled.
  

//Code End -----------------------------------------------------------------
}


/*******************************************************************************    
* Function Name  : Time_100mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_100mSEC_Action(void)
{
  
  SetTimer(TID_BASE_100mSEC,	TID_100mSEC,	Time_100mSEC_Action);

  
//Code Start ----------------------------------------------------------------


//Code End -----------------------------------------------------------------
}

/*******************************************************************************    
* Function Name  : Time_200mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_200mSEC_Action(void)
{
  SetTimer(TID_BASE_200mSEC,	TID_200mSEC,	Time_200mSEC_Action);

//Code Start ----------------------------------------------------------------
  
  if(flag_mem_access == MEM_WRITE)
  {
    WriteMem();
    
    flag_mem_access = MEM_NORMAL;
  }
  if(flag_mem_access == MEM_READ)
  {
    ReadMem();
      
    flag_mem_access = MEM_NORMAL;
  }
  else if(flag_mem_access == MEM_INIT)
  {	
    Init_Const();
    Init_Var();
    
    WriteMem();
    
    flag_mem_access = MEM_NORMAL;
  }
  // CH1 is JSON-only. Periodic Modbus read disabled.
  
//Code End -----------------------------------------------------------------
}



unsigned int Test_Msg=0xAA;
/*******************************************************************************    
* Function Name  : Time_500mSEC_Action
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void Time_500mSEC_Action(void)
{
  SetTimer(TID_BASE_500mSEC,	TID_500mSEC,	Time_500mSEC_Action);

//Code Start ----------------------------------------------------------------
   
  // CH1 is JSON-only. Periodic Modbus write disabled.
 
  
  //Firmware Upgrade MODE P/W 7830
	
  
//Code End -----------------------------------------------------------------
}


void Time_1000mSEC_Action(void)
{
  SetTimer(TID_BASE_1SEC,	TID_1SEC,	Time_1000mSEC_Action);

  
//Code Start ----------------------------------------------------------------
	sys_on_time++;
	
	
	
//Code End -----------------------------------------------------------------
}









