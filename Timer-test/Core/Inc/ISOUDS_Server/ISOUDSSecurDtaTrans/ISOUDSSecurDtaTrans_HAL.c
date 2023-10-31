/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDSSecurDtaTrans_HAL.c
**
** Description  : Tester Present Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDSSecurDtaTrans.h"
#include "ISOUDSSecurDtaTrans_HAL.h"
#include "ISOUDSSecurDtaTrans_Cfg.h"
#include "ISOUDS_Server_Cfg.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/


/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/**************************** Internal functions declarations *****************/

/******************************** Function definitions ************************/
#if (ISOUDS_SECDATATRANS_ENABLE == TRUE)
/*******************************************************************************
** Function                 : SecureDtaTrans_Encode

** Description              : Encode the Data

** Parameter Length	 			: number of Bytes

** Parameter PtrTodataBuff      : Pointer to Data Buffer

** Return value             : TRUE or FALSE
*******************************************************************************/
void ISOUDS_SecureDtaTrans_Encode(uint16_t Length,uint8_t *PtrTodataBuff)
{
	/* for iteration */
	uint8_t loop;

	uint8_t Temp[2];

	/* Copy the SID to destination Buffer */
	Temp[ZERO] = ISOUDS_SRESIDSECURDTATRANS;

	if (NULL_PTR != PtrTodataBuff)
	{   
		/* Encrypt the Data */
		for(loop = ZERO; loop < Length ; loop++)
		{
			Temp[ZERO + 1] = PtrTodataBuff[loop] ^ SecureData;

			PtrTodataBuff[loop] = Temp[ZERO];

			Temp[ZERO] = Temp[ZERO + 1];
		}

	}
	else
	{
		/* Do Nothing */
	}
}
#endif

#endif
