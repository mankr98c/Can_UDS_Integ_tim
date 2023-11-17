/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_SA.c
**
** Description  : Security Access Service
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/


/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_SA_Cfg.h"
#include "ISOUDS_SA_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/
static uint8_t GetSeedLevel1( uint8_t *SeedGentd);
static uint8_t GenerateKeyLevel1(const uint8_t *Key,uint16_t Keylength);
static uint8_t GetSeedLevel3( uint8_t *SeedGentd);
static uint8_t GenerateKeyLevel3(const uint8_t *Key,uint16_t Keylength);
static uint8_t GetSeedLevel5( uint8_t *SeedGentd);
static uint8_t GenerateKeyLevel5(const uint8_t *Key,uint16_t Keylength);
static uint8_t GetSeedLevel7( uint8_t *SeedGentd);
static uint8_t GenerateKeyLevel7(const uint8_t *Key,uint16_t Keylength);
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/
const ISOUDS_SA_Conf_t ISO_SA_Config[ISOUDS_SA_NO_OF_SUP_LEVLS] =
{
#if (SYMC_SECURITY == 1)
		{(uint8_t)UnlockedL2, EXTENDED_SESS,8, 8, &GetSeedLevel3,&GenerateKeyLevel3},
		{(uint8_t)UnlockedL4, EXTENDED_SESS,8, 8, &GetSeedLevel7,&GenerateKeyLevel7}
#else
		{(uint8_t)UnlockedL1, EXTENDED_SESS |PROGRAMMING_SESS ,3, 3, &GetSeedLevel1,&GenerateKeyLevel1},
		{(uint8_t)UnlockedL2, EXTENDED_SESS |PROGRAMMING_SESS ,8, 8, &GetSeedLevel3,&GenerateKeyLevel3},
		{(uint8_t)UnlockedL3, EXTENDED_SESS |PROGRAMMING_SESS ,8, 4, &GetSeedLevel5,&GenerateKeyLevel5},
		{(uint8_t)UnlockedL4, EXTENDED_SESS |PROGRAMMING_SESS ,8, 8, &GetSeedLevel7,&GenerateKeyLevel7}
#endif
};


/* Seed */
uint8_t GenratedSeed[ISOUDS_SASEED_MAXSIZE]  = { 0x00U };
/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_SA_NO_OF_SUP_LEVLS

** Description              : Return the Number of Levels configured for the Security Accesss

** Paramete           		: None

** Return value             : retVal : Number of Levels

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_SA_NO_OF_SUP_LEVLS(void)
{
	return ISOUDS_SA_NO_OF_SUP_LEVLS;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_SASESSIONTIMERMAX

** Description              : Return the Number of Levels configured for the Security Accesss

** Paramete           		: None

** Return value             : retVal : SA Maximum Session timeout

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_Get_SASESSIONTIMERMAX(void)
{
	return ISOUDS_SASESSIONTIMERMAX;
}

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/
/*****************************************************************************************************
 *  Function                 : GetSeedLevel1

** Description              : returns the seed for level 1

** Parameter 			  	: SeedGentd: Pointer to Seed

** Return value             : None
***************************************************************************************************/
static uint8_t GetSeedLevel1( uint8_t *SeedGentd)
{
	uint8_t RetVal = ISOUDS_POSRES;
	
	/* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		HAL_GenSeedLevel1(SeedGentd);
	}
	else
	{
		/* NRC - conditions not correct */
	    RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}

	
	return RetVal;
}
/*****************************************************************************************************
 * Function                 : GenerateKeyLevel1

** Description              : returns the Key for level 1

** Parameter                : Seed: Pointer to Seed
                            : Key : Pointer to Key
** Return value             : None
***************************************************************************************************/
static uint8_t GenerateKeyLevel1(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t Valdkey_stat;
	uint8_t RetVal;
    /* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		Valdkey_stat = HAL_GenKeyLevel1(Key, Keylength);
		
		if (Valdkey_stat == ISOUDS_TRUE)
		{
			RetVal = ISOUDS_POSRES;
		}
		else
		{
			RetVal = ISOUDS_IK;
		}
	}
	else
	{
		/* NRC - conditions not correct */
		RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}
    /* User Defined Code end */
	return RetVal;
}


/*****************************************************************************************************
 *  Function                 : GetSeedLevel3

** Description              : returns the seed for level 3

** Parameter 			  	: SeedGentd: Pointer to Seed

** Return value             : None
***************************************************************************************************/
static uint8_t GetSeedLevel3( uint8_t *SeedGentd)
{
	uint8_t RetVal = ISOUDS_POSRES;

	/* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		HAL_GenSeedLevel3(SeedGentd);
	}
	else
	{
		/* NRC - conditions not correct */
	    RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}


	return RetVal;
}
/*****************************************************************************************************
 * Function                 : GenerateKeyLevel3

** Description              : returns the Key for level 3

** Parameter                : Seed: Pointer to Seed
                            : Key : Pointer to Key
** Return value             : None
***************************************************************************************************/
static uint8_t GenerateKeyLevel3(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t Valdkey_stat;
	uint8_t RetVal;
    /* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		Valdkey_stat = HAL_GenKeyLevel3(Key, Keylength);

		if (Valdkey_stat == ISOUDS_TRUE)
		{
			RetVal = ISOUDS_POSRES;
		}
		else
		{
			RetVal = ISOUDS_IK;
		}
	}
	else
	{
		/* NRC - conditions not correct */
		RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}
    /* User Defined Code end */
	return RetVal;
}


/*****************************************************************************************************
 *  Function                 : GetSeedLevel5

** Description              : returns the seed for level 5

** Parameter 			  	: SeedGentd: Pointer to Seed

** Return value             : None
***************************************************************************************************/
static uint8_t GetSeedLevel5( uint8_t *SeedGentd)
{
	uint8_t RetVal = ISOUDS_POSRES;

	/* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		HAL_GenSeedLevel5(SeedGentd);
	}
	else
	{
		/* NRC - conditions not correct */
	    RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}


	return RetVal;
}
/*****************************************************************************************************
 * Function                 : GenerateKeyLevel5

** Description              : returns the Key for level 5

** Parameter                : Seed: Pointer to Seed
                            : Key : Pointer to Key
** Return value             : None
***************************************************************************************************/
static uint8_t GenerateKeyLevel5(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t Valdkey_stat;
	uint8_t RetVal;
    /* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		Valdkey_stat = HAL_GenKeyLevel5(Key, Keylength);

		if (Valdkey_stat == ISOUDS_TRUE)
		{
			RetVal = ISOUDS_POSRES;
		}
		else
		{
			RetVal = ISOUDS_IK;
		}
	}
	else
	{
		/* NRC - conditions not correct */
		RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}
    /* User Defined Code end */
	return RetVal;
}

/*****************************************************************************************************
 *  Function                 : GetSeedLevel7

** Description              : returns the seed for level 7

** Parameter 			  	: SeedGentd: Pointer to Seed

** Return value             : None
***************************************************************************************************/
static uint8_t GetSeedLevel7( uint8_t *SeedGentd)
{
	uint8_t RetVal = ISOUDS_POSRES;

	/* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		HAL_GenSeedLevel7(SeedGentd);
	}
	else
	{
		/* NRC - conditions not correct */
	    RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}


	return RetVal;
}
/*****************************************************************************************************
 * Function                 : GenerateKeyLevel7

** Description              : returns the Key for level 7

** Parameter                : Seed: Pointer to Seed
                            : Key : Pointer to Key
** Return value             : None
***************************************************************************************************/
static uint8_t GenerateKeyLevel7(const uint8_t *Key,uint16_t Keylength)
{
	uint8_t Valdkey_stat;
	uint8_t RetVal;
    /* USer DEfined Code Start */
	if (ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check())
	{
		Valdkey_stat = HAL_GenKeyLevel7(Key, Keylength);

		if (Valdkey_stat == ISOUDS_TRUE)
		{
			RetVal = ISOUDS_POSRES;
		}
		else
		{
			RetVal = ISOUDS_IK;
		}
	}
	else
	{
		/* NRC - conditions not correct */
		RetVal = ISOUDS_VEHSPEDTOOHIGH;
	}
    /* User Defined Code end */
	return RetVal;
}


#endif
