/**
  * FILE system_MDR1986VE1T.h
  */

/** @addtogroup __CMSIS CMSIS
  * @{
  */

/** @defgroup MDR1986VE1T
 *  @{
 */

/** @defgroup __MDR1986VE1T_System_CMC MDR1986VE1T System CMC
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_MDR1986VE1T_H
#define __SYSTEM_MDR1986VE1T_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>     /* standard types definitions */

/** @addtogroup __MDR1986VE1T_System_Exported_Variables MDR1986VE1T System Exported Variables
  * @{
  */

extern uint32_t SystemCoreClock;    /*!< System Clock Frequency (Core Clock) default value */

/** @} */ /* End of group __MDR1986VE1T_System_Exported_Variables */

/** @addtogroup __MDR1986VE1T_System_Exported_Functions MDR1986VE1T System Exported Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/** @} */ /* End of group __MDR1986VE1T_System_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_MDR1986VE1T_H */

/** @} */ /* End of group __MDR1986VE1T */

/** @} */ /* End of group MDR1986VE1T */

/** @} */ /* End of group __CMSIS */

/*
*
* END OF FILE system_MDR1986VE1T.h */
