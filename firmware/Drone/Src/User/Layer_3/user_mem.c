///// INCLUDES ////////////////////////////////////////////////////////////////
#include "headers.h"


///// VARIABLES///////////////////////////////////////////////////////////////
int32_t CUR_VAR_PAGE = 0;

static FLASH_EraseInitTypeDef EraseInitStruct;
uint32_t memError = 0;
uint32_t memSector = 0;

#define FLASH_CLEAR_ERROR_FLAGS() \
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK1 | FLASH_FLAG_ALL_ERRORS_BANK1)

///// FUNCTIONS ///////////////////////////////////////////////////////////////

/*******************************************************************************    
* Function Name  : fun_Init_mem    
* Description    : ??? ???
* Input          : None    
* Output        : None    
* Return        : None    
*******************************************************************************/ 
void fun_Init_mem(void)
{
	flag_PF_mem = 0;

	ReadMem();
	
	ECU_MAIN_STATE = STATE_MAIN_INIT;
}

/*******************************************************************************
* Function Name  : CompareMem
* Description    : ? ??? ?? ??
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

int32_t CompareMem(uint32_t mem1_addr, uint32_t mem2_addr, uint32_t mem_size)
{
	int32_t flag_dif = 0;
	for(int32_t i=0; i<mem_size; i=i+4)
	{	
    if((*((int32_t *)(mem1_addr + i))) != (*((int32_t *)(mem2_addr+i))))
    {
      flag_dif = 1;
      break;
    }
	}
	return flag_dif;
}


/*******************************************************************************
* Function Name  : CopyRamToFlash
* Description    : RAM ???? Flash? ??
* Input          : flash_addr -> ??? Flash ??
*                  ram_addr   -> ?? RAM ??
*                  db_size    -> ??? ??? ??
* Output         : None
* Return         : None
*******************************************************************************/
int32_t CopyRamToFlash(uint32_t flash_addr, uint32_t ram_addr, uint32_t db_size)
{
  uint32_t flash_word[FLASH_NB_32BITWORD_IN_FLASHWORD];
  const uint32_t flash_word_size = FLASH_NB_32BITWORD_IN_FLASHWORD * sizeof(uint32_t);

  if ((db_size == 0U) ||
      ((flash_addr % flash_word_size) != 0U) ||
      (flash_addr < USER_DB_FLASH_STARTADDRESS) ||
      (db_size > (USER_DB_FLASH_LAST_ADDRESS - flash_addr + 1U)) ||
      ((flash_addr + db_size - 1U) > USER_DB_FLASH_LAST_ADDRESS))
  {
    return -1;
  }

	for(uint32_t i=0; i<db_size; i += flash_word_size)
	{
    uint32_t remain_size = db_size - i;
    uint32_t write_size = (remain_size > flash_word_size) ? flash_word_size : remain_size;

    for(uint32_t word_index=0; word_index<FLASH_NB_32BITWORD_IN_FLASHWORD; word_index++)
    {
      flash_word[word_index] = 0xFFFFFFFFU;
    }

    for(uint32_t byte_index=0; byte_index<write_size; byte_index++)
    {
      ((uint8_t *)flash_word)[byte_index] = *((uint8_t *)(ram_addr + i + byte_index));
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD,  flash_addr+i ,  (uint32_t)flash_word) != HAL_OK)
    {
      return -1;                      //error
    }
	}
 	return 1;
}

/*******************************************************************************
* Function Name  : CopyFlashToRam
* Description    : Flash ???? RAM?? ??
* Input          : ram_addr   -> ??? RAM ??
*                  flash_addr -> ?? Flash ??
*                  db_size    -> ??? ??? ??
* Output         : None
* Return         : None
*******************************************************************************/
int32_t CopyFlashToRam(uint32_t ram_addr, uint32_t flash_addr, uint32_t db_size)
{
	for(int32_t i=0; i<db_size; i=i+4)
	{	
			(*((int32_t *)(ram_addr + i))) = (*((int32_t *)(flash_addr+i)));
	}
 	return 1;
}

/*******************************************************************************
* Function Name  : CalcChecksum
* Description    : ??? ??? ??? ??
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t CalcChecksum(uint32_t mem1_addr, uint32_t mem_size)
{
	int32_t i;
	uint16_t tmp;
	uint16_t rst = 0;
  
  for(i=0; i<mem_size; i=i+4)
  {
    tmp = *(( int32_t  *)(mem1_addr+i));
    rst += tmp;				
  }	
  return rst;
}

/*******************************************************************************
* Function Name  : ReadMem
* Description    : Flash -> RAM ??
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ReadMem(void)
{
  int32_t read_chksum_var = 0 ;
	uint32_t DataAddr;
  uint8_t flag_write_mem = 0;
        
  CONST_CHKSUM = 0;

  DataAddr = FLASH_ADDR_CONST + DB_SIZE_CONST-12;
  MEM_SW_VERSION = (*(__IO int32_t *)(DataAddr)); 	
                
/*
    // ?? ??? ??? ?? ??
	DataAddr = FLASH_ADDR_VAR + DB_SIZE_SAVE_VAR - 8;
	MEM_VAR_INIT_FLAG = (*(__IO int32_t *)(DataAddr));

    if(MEM_VAR_INIT_FLAG == 0x5555) // ??
	{
        // ?? ??? checksum ??
		VAR_CHKSUM = (uint32_t)CalcChecksum(FLASH_ADDR_VAR, DB_SIZE_SAVE_VAR - 4);

		DataAddr = FLASH_ADDR_VAR + DB_SIZE_SAVE_VAR - 4;
		read_chksum_var = (*(__IO int32_t *)(DataAddr));

        if(VAR_CHKSUM == read_chksum_var) // ?? ????? RAM?? ??
		{
			CopyFlashToRam(RAM_ADDR_VAR + DB_SIZE_VAR, FLASH_ADDR_VAR, DB_SIZE_SAVE_VAR);
		}
		else
		{
			Setbit(flag_PF_mem, ID_PF_VAR_READ);
		}
	}
	else
	{
		Setbit(flag_PF_mem, ID_PF_MEM_FIRST);
	}
*/

    // ?? ??? ??? ?? ??
  DataAddr = FLASH_ADDR_CONST + DB_SIZE_CONST-8;
  MEM_CONST_INIT_FLAG = (*(__IO int32_t *)(DataAddr)); 	
  
  
  if(MEM_CONST_INIT_FLAG == 0x5555) // ??
  {
    // ?? ??? checksum ??
    CONST_CHKSUM = (uint32_t)CalcChecksum(FLASH_ADDR_CONST, DB_SIZE_CONST-4);
    
    DataAddr = FLASH_ADDR_CONST + DB_SIZE_CONST -4;
    read_chksum_var = (*(__IO int32_t *)(DataAddr)); 					
    
    if(CONST_CHKSUM == read_chksum_var)  // ?? ????? RAM?? ??
    {
      CopyFlashToRam(RAM_ADDR_CONST, FLASH_ADDR_CONST, DB_SIZE_CONST);
    }
    else
    {
      Setbit(flag_PF_mem, ID_PF_CONST_READ);    // ??? ?? ??
    }
  }
  else
  {
    Setbit(flag_PF_mem, ID_PF_MEM_FIRST);    // ?? ??? ??
  }
        
        
  
  // ??? ?? ?? ??
  flag_mem_access = MEM_NORMAL;
  
  if(Chkbit(flag_PF_mem, ID_PF_CONST_READ) != CHK_CLEAR)
  {
    Init_Const();
    Clrbit(flag_PF_mem, ID_PF_CONST_READ);
		
    flag_write_mem = 1;
  }
  
  if(Chkbit(flag_PF_mem, ID_PF_VAR_READ) != CHK_CLEAR)
  {
    Init_Var();	
    Clrbit(flag_PF_mem, ID_PF_VAR_READ);
		
    flag_write_mem = 1;
  }
  
  if(Chkbit(flag_PF_mem, ID_PF_MEM_FIRST) != CHK_CLEAR)            // ?? ?? ? ?? ?? ?? ? ???
  {	
    Init_Var();
    Init_Const();	

    Clrbit(flag_PF_mem, ID_PF_MEM_FIRST);
		
		flag_write_mem = 1;
  }
  
  //if(MEM_SW_VERSION != FIX_SW_VERSION)                    // ??? ?? ?? ? ?? ?? ?? ???
  //{
  //  Init_NewDB();
  //  
  //  MEM_SW_VERSION = FIX_SW_VERSION;

  //  
  //  flag_write_mem = 1;
  //}
      
  if(flag_write_mem == 1)
  {
    WriteMem();
  }
}

/*******************************************************************************
* Function Name  : WriteMem
* Description    : RAM -> Flash ??
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void WriteMem(void)
{
	int32_t flash_init_err = 0;
        
	FLASH_WRITE_CNT++; 
  
  MEM_CONST_INIT_FLAG = 0x5555;	
              
  HAL_FLASH_Unlock();
  
  // UART2 ?? ? ?? ??? PGA, PGS ?? Flash ?? ??? ??
  /**************************************************************************************************/
  FLASH_CLEAR_ERROR_FLAGS();
  /**************************************************************************************/ 
  
  D_I_CACHE_CLEAR;  
         
	//erase
	memSector = FLASH_If_GetSectorNumber(FLASH_ADDR_VAR);   
  if (memSector == FLASH_INVALID_SECTOR)
  {
    HAL_FLASH_Lock();
    return;
  }

  EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.Banks = FLASH_BANK_1;
  EraseInitStruct.Sector = memSector;
  EraseInitStruct.NbSectors = 1;
  EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
                
  if(HAL_FLASHEx_Erase(&EraseInitStruct, &memError) != HAL_OK)
  {
    //Setbit(flag_all_err, ERR_MEM);  
    // Flash erase ??
  }
  else
  {
    /*
    VAR_CHKSUM = (uint32_t)CalcChecksum(RAM_ADDR_VAR+DB_SIZE_VAR, DB_SIZE_SAVE_VAR-4);
    flash_init_err = CopyRamToFlash(FLASH_ADDR_VAR, RAM_ADDR_VAR+DB_SIZE_VAR, DB_SIZE_SAVE_VAR);
    //------------end mem var write---------------------------------------------------------------------
    */
		    
    CONST_CHKSUM = (uint32_t)CalcChecksum(RAM_ADDR_CONST, DB_SIZE_CONST-4);
    flash_init_err = CopyRamToFlash(FLASH_ADDR_CONST, RAM_ADDR_CONST, DB_SIZE_CONST);	
    //----------end const write-------------------------------------------------
  }
		
  HAL_FLASH_Lock();
      
  if(flash_init_err == -1)
  {
    //Setbit(flag_all_err, ERR_MEM);
    // Flash write ??
  }
}




