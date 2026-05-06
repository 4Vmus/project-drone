#ifndef __FLASH_IF_H
#define __FLASH_IF_H

#include "main.h"



/* Exported types ------------------------------------------------------------*/
typedef  void (*pFunction)(void);



///// DEFINES /////////////////////////////////////////////////////////////////
/* STM32H723ZG internal flash map: 1MB, 8 sectors, 128KB per sector. */
#define USER_FLASH_STARTADDRESS        ((uint32_t)0x08000000)
#define USER_FLASH_ENDADDRESS          ((uint32_t)0x080FFFFF)
#define USER_FLASH_SECTOR_SIZE         ((uint32_t)0x00020000)
#define USER_FLASH_TOTAL_SECTORS       ((uint32_t)8)
#define FLASH_INVALID_SECTOR           ((uint32_t)0xFFFFFFFF)

/* Sector 0 is reserved for bootloader. */
#define BOOT_CHK_ADDRESS               ((uint32_t)0x0800C000)       //firm msg chk



/* Define the address from where user application will be loaded.
for the Firmware upgrade code */
#define APPLICATION_ADDRESS            ((uint32_t)0x08020000)       //Application start addr




/* Last Page Adress */
/* Sector 7 is reserved for DB, so application update must stop at sector 6. */
#define USER_FLASH_LAST_PAGE_ADDRESS   ((uint32_t)0x080DFFFF)

/* DB reserved area: sector 7. */
#define USER_DB_FLASH_STARTADDRESS     ((uint32_t)0x080E0000)
#define USER_DB_FLASH_LAST_ADDRESS     ((uint32_t)0x080FFFFF)

/* Define the user application size */
#define USER_FLASH_SIZE   (USER_FLASH_LAST_PAGE_ADDRESS - APPLICATION_ADDRESS + 1)

/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Sector 0: bootloader */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08020000) /* Sector 1: application start */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08040000)
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08060000)
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08080000)
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x080A0000)
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x080C0000)
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x080E0000) /* Sector 7: DB */


#define D_I_CACHE_CLEAR             do { __DSB(); __ISB(); } while (0)


///// FUNCTIONS ///////////////////////////////////////////////////////////////
extern void FLASH_If_FlashUnlock(void);
extern FlagStatus FLASH_If_ReadOutProtectionStatus(void);
extern uint32_t FLASH_If_EraseSectors(uint32_t Address);
extern uint32_t FLASH_If_EraseOneSectors(uint32_t Address);
extern uint32_t FLASH_If_Write(uint32_t Address, uint32_t Data);
extern uint32_t FLASH_If_GetSectorNumber(uint32_t Address);


#endif 

