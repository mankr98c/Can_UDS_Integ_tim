/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_SA.h
**
** Description  : Include file of component ISOUDS_SA.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_SA_CFG_H
#define ISOUDS_SA_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/
typedef struct
{
	uint8_t Level;
	uint8_t SuppSession;
	uint8_t SeedLenth;
	uint8_t KeyLenth;
	uint8_t (*GenerateSeed)(uint8_t *SeedGentd);
	uint8_t (*GenerateKey)(const uint8_t *Key,uint16_t Key_Len);
}ISOUDS_SA_Conf_t;

/********************************* Declaration of global macros ***********************************/
#if (SYMC_SECURITY == 1)
#define ISOUDS_SA_NO_OF_SUP_LEVLS		2
#else
#define ISOUDS_SA_NO_OF_SUP_LEVLS		4
#endif

/* Session timer max value-after this time current security session will expire */
#define ISOUDS_SASESSIONTIMERMAX    (uint32_t)(60000 * 60)/* 60 minutes for Firmware Download*/

/* maximum time waiting for key */
#define ISOUDS_SAWAITKEYMAX            (5000)/* 5s */

/* Maximum attempts count for wrong key Take 1 here */
#define ISOUDS_MAXATTEMTCOUNT        ((uint8_t)3)

/* Exceed Attempt Count Delay Timer */
#define ISOUDS_ATTEMPCNTDELAYTIMER	  (10000u)/* 10Sec */
/* Lock time Secuirty Access. */
#define ISOUDS_SALOCKPERIOD             (uint32_t)(10000)/* 10s */

#define ISOUDS_SA_POWRON_DELY_EN		ISOUDS_TRUE
#define ISOUDS_SAPOWERON_DELAY	        (10000)

/* ECU Seed Offset */
#define SEED_OFFSET 0x0000E5A1

/* Seed SIZE */
#define     ISOUDS_SASEED_MAXSIZE           (8)

/*EEPROM ID to store the security attempt count*/
#define		ISOUDS_SAATTEMPCNT_ID			(0x0002)

/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/
extern const ISOUDS_SA_Conf_t ISO_SA_Config[ISOUDS_SA_NO_OF_SUP_LEVLS];
extern uint8_t GenratedSeed[ISOUDS_SASEED_MAXSIZE];
/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_SA_NO_OF_SUP_LEVLS

** Description              : Return the Number of Levels configured for the Security Accesss

** Paramete           		: None

** Return value             : retVal : Number of Levels

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_SA_NO_OF_SUP_LEVLS(void);

/***************************************************************************************************
** Function                 : ISOUDS_Get_SASESSIONTIMERMAX

** Description              : Return the Number of Levels configured for the Security Accesss

** Paramete           		: None

** Return value             : retVal : SA Maximum Session timeout

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_Get_SASESSIONTIMERMAX(void);

#endif  /* ISOUDS_SA_H */
