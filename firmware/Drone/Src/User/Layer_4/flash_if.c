///// INCLUDES ////////////////////////////////////////////////////////////////
#include "headers.h"




///// DEFINE //////////////////////////////////////////////////////////////////
#define FLASH_CLEAR_ERROR_FLAGS() \
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK1 | FLASH_FLAG_ALL_ERRORS_BANK1)

static uint32_t FLASH_If_GetSectorEndAddress(uint32_t sector)
{
  return USER_FLASH_STARTADDRESS + ((sector + 1U) * USER_FLASH_SECTOR_SIZE) - 1U;
}






///// VARIABLES ///////////////////////////////////////////////////////////////
uint32_t FirstSector = 0;
uint32_t NbOfSectors = 0;
uint32_t SectorError = 0;
uint32_t OB_RDP_LEVEL;

FLASH_OBProgramInitTypeDef  FLASH_OBProgramInitStruct;
FLASH_EraseInitTypeDef      FLASH_EraseInitStruct;

/*******************************************************************************    
* Function Name  : FLASH_If_FlashUnlock
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
void FLASH_If_FlashUnlock(void)
{
  HAL_FLASH_Unlock();
}

/*******************************************************************************    
* Function Name  : FLASH_If_ReadOutProtectionStatus
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
FlagStatus FLASH_If_ReadOutProtectionStatus(void)
{
  FlagStatus readoutstatus = RESET;

  FLASH_OBProgramInitStruct.RDPLevel = OB_RDP_LEVEL;

  HAL_FLASHEx_OBGetConfig(&FLASH_OBProgramInitStruct);

  if (OB_RDP_LEVEL == SET)
  {
    readoutstatus = SET;
  }
  else
  {
    readoutstatus = RESET;
  }

  return readoutstatus;
}

/*******************************************************************************    
* Function Name  : FLASH_If_EraseSectors
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
uint32_t FLASH_If_EraseSectors(uint32_t Address)
{
  /* Erase the user Flash area (area defined by APPLICATION_ADDRESS and
   * USER_FLASH_LAST_PAGE_ADDRESS) *** */
    HAL_FLASH_Unlock();
    FLASH_CLEAR_ERROR_FLAGS();
    
  if ((Address >= APPLICATION_ADDRESS) && (Address <= (uint32_t) USER_FLASH_LAST_PAGE_ADDRESS))
  {
    /* Get the 1st sector to erase */
    FirstSector = FLASH_If_GetSectorNumber(Address);
    if (FirstSector == FLASH_INVALID_SECTOR)
    {
      HAL_FLASH_Lock();
      return (1);
    }

    /* Get the number of sector to erase from 1st sector */
    NbOfSectors =  FLASH_If_GetSectorNumber(USER_FLASH_LAST_PAGE_ADDRESS) - FirstSector + 1;

    FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    FLASH_EraseInitStruct.Banks = FLASH_BANK_1;
    FLASH_EraseInitStruct.Sector = FirstSector;
    FLASH_EraseInitStruct.NbSectors = NbOfSectors;
    FLASH_EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    if (HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &SectorError) != HAL_OK)
    {
      HAL_FLASH_Lock();
      return (1);
    }
  }
  else
  {
    HAL_FLASH_Lock();
    return (1);
  }

  HAL_FLASH_Lock();
  return (0);
}

/*******************************************************************************    
* Function Name  : FLASH_If_EraseOneSectors
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
uint32_t FLASH_If_EraseOneSectors(uint32_t Address)
{
  /* Erase the user Flash area (area defined by APPLICATION_ADDRESS and
   * USER_FLASH_LAST_PAGE_ADDRESS) *** */
    HAL_FLASH_Unlock();
    FLASH_CLEAR_ERROR_FLAGS();
    
  if ((Address >= APPLICATION_ADDRESS) && (Address <= (uint32_t) USER_FLASH_LAST_PAGE_ADDRESS))
  {
    /* Get the 1st sector to erase */
    FirstSector = FLASH_If_GetSectorNumber(Address);
    if (FirstSector == FLASH_INVALID_SECTOR)
    {
      HAL_FLASH_Lock();
      return (1);
    }

    /* Get the number of sector to erase from 1st sector */
    NbOfSectors =  1;

    FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    FLASH_EraseInitStruct.Banks = FLASH_BANK_1;
    FLASH_EraseInitStruct.Sector = FirstSector;
    FLASH_EraseInitStruct.NbSectors = NbOfSectors;
    FLASH_EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    if (HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &SectorError) != HAL_OK)
    {
      HAL_FLASH_Lock();
      return (1);
    }
  }
  else
  {
    HAL_FLASH_Lock();
    return (1);
  }

  HAL_FLASH_Lock();
  return (0);
}

/*******************************************************************************    
* Function Name  : FLASH_If_Write
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
uint32_t FLASH_If_Write(uint32_t Address, uint32_t Data)
{
  uint32_t flashWord[FLASH_NB_32BITWORD_IN_FLASHWORD];

  if ((Address < APPLICATION_ADDRESS) ||
      (Address > (uint32_t)USER_FLASH_LAST_PAGE_ADDRESS) ||
      ((Address % (FLASH_NB_32BITWORD_IN_FLASHWORD * sizeof(uint32_t))) != 0U))
  {
    return (1);
  }

  for (uint32_t i = 0; i < FLASH_NB_32BITWORD_IN_FLASHWORD; i++)
  {
    flashWord[i] = 0xFFFFFFFFU;
  }
  flashWord[0] = Data;

  HAL_FLASH_Unlock();
  FLASH_CLEAR_ERROR_FLAGS();
  D_I_CACHE_CLEAR;

  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, Address, (uint32_t)flashWord) != HAL_OK)
  {
    HAL_FLASH_Lock();
    return (1);
  }

  HAL_FLASH_Lock();
  return (0);
}

/*******************************************************************************    
* Function Name  : FLASH_If_GetSectorNumber
* Description    : None
* Input          : None    
* Output         : None    
* Return         : None    
*******************************************************************************/  
uint32_t FLASH_If_GetSectorNumber(uint32_t Address)
{
  uint32_t sector;

  if ((Address < USER_FLASH_STARTADDRESS) || (Address > USER_FLASH_ENDADDRESS))
  {
    return FLASH_INVALID_SECTOR;
  }

  sector = (Address - USER_FLASH_STARTADDRESS) / USER_FLASH_SECTOR_SIZE;
  if ((sector >= USER_FLASH_TOTAL_SECTORS) || (Address > FLASH_If_GetSectorEndAddress(sector)))
  {
    return FLASH_INVALID_SECTOR;
  }

  return sector;
}
