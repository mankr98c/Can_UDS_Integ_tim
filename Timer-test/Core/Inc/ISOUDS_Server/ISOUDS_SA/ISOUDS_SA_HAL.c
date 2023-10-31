/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_SA_HAL.c
**
** Description  : Security Access Service
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_SA.h"
#include "ISOUDS_SA_Cfg.h"
#include "ISOUDS_SA_HAL.h"

#if (SYMC_SECURITY == 1)
#include "fsymc_security.h"
#endif

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

static uint8_t ISOUDS_AttempCntFrmNVM = INDEX_ZERO;
/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : HAL_GenSeedLevel1

** Description              : Generate seed

** Parameter                : None

** Return value             : Seed value
***************************************************************************************************/
void HAL_GenSeedLevel1( uint8_t *SeedGentd)
{
	/*User specific implementation*/
	uint8_t seed[8] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
	uint8_t *PtrToGenSeed  = NULL_PTR;
	uint8_t Idx;

	/* Compute the seed only if ECU lock status is FALSE, otherwise seed = 0 */ 
	if(ISOUDS_FALSE == ISOUDS_GetSASt())  
	{

	}
	else
	{
		/* do nothing */
	}
	
	/* User Defined Code end */
	PtrToGenSeed = (uint8_t *)&seed;

	for (Idx = 0; Idx < ISO_SA_Config[0].SeedLenth; Idx++)
	{
		SeedGentd[Idx] = PtrToGenSeed[Idx];
	}

}

/***************************************************************************************************
** Function                 : HAL_GenKeyLevel1

** Description              : Generate key

** Parameter                : None

** Return value             : Key value
***************************************************************************************************/
uint8_t HAL_GenKeyLevel1(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t RetVal = ISOUDS_TRUE;
	uint8_t Indx;
	/* seed length in bytes */
	uint8_t KeyL1[4] = {0x01,0x02,0x03,0x04};


	/* Add security Logic Here */

	/* The final remainder is the key */


	for(Indx = ISOUDS_ZERO; Indx < Keylength; Indx++)
	{
		if (KeyL1[(Keylength - ISOUDS_ONE) - Indx] != Key[Indx])
		{
			RetVal = ISOUDS_FALSE;
		}
	}

	return RetVal;
}



/***************************************************************************************************
** Function                 : HAL_GenSeedLevel3

** Description              : Generate seed

** Parameter                : None

** Return value             : Seed value
***************************************************************************************************/
void HAL_GenSeedLevel3( uint8_t *SeedGentd)
{
	/*User specific implementation*/
	uint8_t seed[8] = {0, };
	uint8_t *PtrToGenSeed  = NULL_PTR;
	uint8_t Idx;
#if (SYMC_SECURITY == 1)
	SYMC_result_e lRet = SYMC_E_ERROR;
#endif

	/* Compute the seed only if ECU lock status is FALSE, otherwise seed = 0 */
	if(ISOUDS_FALSE == ISOUDS_GetSASt())
	{
#if (SYMC_SECURITY == 1)
		lRet = SYMC_GenerateSeed(seed);
		if (lRet != SYMC_E_OK)
		{
			/* Error! SYMC_GenerateSeed*/
		}
#endif
	}
	else
	{
		/* do nothing */
	}


	/* User Defined Code end */
	PtrToGenSeed = (uint8_t *)&seed;

	for (Idx = 0; Idx < ISO_SA_Config[0].SeedLenth; Idx++)
	{
		SeedGentd[Idx] = PtrToGenSeed[Idx];
	}

}

/***************************************************************************************************
** Function                 : HAL_GenKeyLevel3

** Description              : Generate key

** Parameter                : None

** Return value             : Key value
***************************************************************************************************/
uint8_t HAL_GenKeyLevel3(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t RetVal = ISOUDS_TRUE;

#if (SYMC_SECURITY == 1)
	SYMC_result_e lRet = SYMC_E_ERROR;

	(void)Keylength;
	lRet = SYMC_CompareKey(Key);
	if (lRet != SYMC_E_OK)
	{
		RetVal = ISOUDS_FALSE;
	}
#else
	uint8_t Indx;
	/* seed length in bytes */
	uint8_t KeyL1[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};


	/* Add security Logic Here */

	/* The final remainder is the key */


	for(Indx = ISOUDS_ZERO; Indx < Keylength; Indx++)
	{
		if (KeyL1[(Keylength - ISOUDS_ONE) - Indx] != Key[Indx])
		{
			RetVal = ISOUDS_FALSE;
		}
	}
#endif
	return RetVal;
}

/***************************************************************************************************
** Function                 : HAL_GenSeedLevel5

** Description              : Generate seed

** Parameter                : None

** Return value             : Seed value
***************************************************************************************************/
void HAL_GenSeedLevel5( uint8_t *SeedGentd)
{
	/*User specific implementation*/
	uint8_t seed[8] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
	uint8_t *PtrToGenSeed  = NULL_PTR;
	uint8_t Idx;

	/* Compute the seed only if ECU lock status is FALSE, otherwise seed = 0 */
	if(ISOUDS_FALSE == ISOUDS_GetSASt())
	{

	}
	else
	{
		/* do nothing */
	}


	/* User Defined Code end */
	PtrToGenSeed = (uint8_t *)&seed;

	for (Idx = 0; Idx < ISO_SA_Config[0].SeedLenth; Idx++)
	{
		SeedGentd[Idx] = PtrToGenSeed[Idx];
	}

}

/***************************************************************************************************
** Function                 : HAL_GenKeyLevel5

** Description              : Generate key

** Parameter                : None

** Return value             : Key value
***************************************************************************************************/
uint8_t HAL_GenKeyLevel5(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t RetVal = ISOUDS_TRUE;
	uint8_t Indx;
	/* seed length in bytes */
	uint8_t KeyL1[4] = {0x01,0x02,0x03,0x04};


	/* Add security Logic Here */

	/* The final remainder is the key */


	for(Indx = ISOUDS_ZERO; Indx < Keylength; Indx++)
	{
		if (KeyL1[(Keylength - ISOUDS_ONE) - Indx] != Key[Indx])
		{
			RetVal = ISOUDS_FALSE;
		}
	}

	return RetVal;
}



/***************************************************************************************************
** Function                 : HAL_GenSeedLevel7

** Description              : Generate seed

** Parameter                : None

** Return value             : Seed value
***************************************************************************************************/
void HAL_GenSeedLevel7( uint8_t *SeedGentd)
{
	/*User specific implementation*/
	uint8_t seed[8] ={0, };
	uint8_t *PtrToGenSeed  = NULL_PTR;
	uint8_t Idx;
#if (SYMC_SECURITY == 1)
	SYMC_result_e lRet = SYMC_E_ERROR;
#endif

	/* Compute the seed only if ECU lock status is FALSE, otherwise seed = 0 */
	if(ISOUDS_FALSE == ISOUDS_GetSASt())
	{
#if (SYMC_SECURITY == 1)
		lRet = SYMC_GenerateSeed(seed);
		if (lRet != SYMC_E_OK)
		{
			/* Error! SYMC_GenerateSeed*/
		}
#endif
	}
	else
	{
		/* do nothing */
	}


	/* User Defined Code end */
	PtrToGenSeed = (uint8_t *)&seed;

	for (Idx = 0; Idx < ISO_SA_Config[0].SeedLenth; Idx++)
	{
		SeedGentd[Idx] = PtrToGenSeed[Idx];
	}

}

/***************************************************************************************************
** Function                 : HAL_GenKeyLevel7

** Description              : Generate key

** Parameter                : None

** Return value             : Key value
***************************************************************************************************/
uint8_t HAL_GenKeyLevel7(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t RetVal = ISOUDS_TRUE;

#if (SYMC_SECURITY == 1)
	SYMC_result_e lRet = SYMC_E_ERROR;

	(void)Keylength;
	lRet = SYMC_CompareKey(Key);
	if (lRet != SYMC_E_OK)
	{
		RetVal = ISOUDS_FALSE;
	}
#else
	uint8_t Indx;
	/* seed length in bytes */
	uint8_t KeyL1[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};


	/* Add security Logic Here */

	/* The final remainder is the key */


	for(Indx = ISOUDS_ZERO; Indx < Keylength; Indx++)
	{
		if (KeyL1[(Keylength - ISOUDS_ONE) - Indx] != Key[Indx])
		{
			RetVal = ISOUDS_FALSE;
		}
	}
#endif
	return RetVal; 
}


/*******************************************************************************
** Function name: ISOUDS_GetSAAttempCount
** Description: Return the Security Access attempt count
** Parameter index :  None
** Return value: Attemp count
** Remarks:  None
*******************************************************************************/
uint8_t ISOUDS_GetSAAttempCount(void)
{
#if 0
	/* Return Value */
	uint32_t RespVal = EE_OK;
	/* Read from EEPROM */
	RespVal = readEeprom(ISOUDS_SAATTEMPCNT_ID,(uint32_t)&ISOUDS_AttempCntFrmNVM);
	if(EE_OK == RespVal)
	{
		/* Do nothing */
	}
	else
	{
		/* Do nothing */
	}
#endif
	/* Add logic to read from NVM */
	return ISOUDS_AttempCntFrmNVM;
}

/*******************************************************************************
** Function name: ISOUDS_SetSAAttempCount
** Description: Write the attemp count
** Parameter index :  Attemp count
** Return value: None
** Remarks:  None
*******************************************************************************/
void ISOUDS_SetSAAttempCount(uint8_t ISOUDS_SACNT)
{
#if 0
	/* Return Value */
	uint32_t RespVal = EE_OK;
	/* Add logic to write from NVM */
	ISOUDS_AttempCntFrmNVM = ISOUDS_SACNT;
	/* Write to EEPROM */
	RespVal = writeEeprom(ISOUDS_SAATTEMPCNT_ID,ISOUDS_ONE,(uint32_t)&ISOUDS_AttempCntFrmNVM);

	if(EE_OK == RespVal)
	{
		/* Do nothing */
	}
	else
	{
		/* Do nothing */
	}
#endif
}
#endif
