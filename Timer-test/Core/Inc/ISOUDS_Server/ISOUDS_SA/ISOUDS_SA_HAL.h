/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_SA_HAL.h
**
** Description  : Include file of component ISOUDS_SA_HAL.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_SA_HAL_H
#define ISOUDS_SA_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
#define TOPBIT 				0x8000U 
#define POLYNOM_1 			0x8408U 
#define POLYNOM_2 			0x8025U 
#define BITMASK 			0x0080U 
#define INITIAL_REMINDER 	0xFFFEU 
#define MSG_LEN 			4U 

/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function declarations *****************************************/
extern void HAL_GenSeedLevel1( uint8_t *SeedGentd);
extern uint8_t HAL_GenKeyLevel1(const uint8_t *Key,uint16_t Keylength);
extern void HAL_GenSeedLevel3( uint8_t *SeedGentd);
extern uint8_t HAL_GenKeyLevel3(const uint8_t *Key,uint16_t Keylength);
extern void HAL_GenSeedLevel5( uint8_t *SeedGentd);
extern uint8_t HAL_GenKeyLevel5(const uint8_t *Key,uint16_t Keylength);
extern void HAL_GenSeedLevel7( uint8_t *SeedGentd);
extern uint8_t HAL_GenKeyLevel7(const uint8_t *Key,uint16_t Keylength);


/*******************************************************************************
** Function name: ISOUDS_GetSAAttempCount
** Description: Return the Security Access attempt count
** Parameter index :  None
** Return value: Attemp count
** Remarks:  None
*******************************************************************************/
extern uint8_t ISOUDS_GetSAAttempCount(void);

/*******************************************************************************
** Function name: ISOUDS_SetSAAttempCount
** Description: Write the attemp count
** Parameter index :  Attemp count
** Return value: None
** Remarks:  None
*******************************************************************************/
extern void ISOUDS_SetSAAttempCount(uint8_t ISOUDS_SACNT);
#endif  /* ISOUDS_SA_HAL_H */
