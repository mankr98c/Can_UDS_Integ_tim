/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByPdID_HAL.c
**
** Description  : Write Data By Identifier Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/

#include "ISOUDS_RdDaByPdID.h"
#include "ISOUDS_RdDaByPdID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/******************************** Function definitions ************************/
/*******************************************************************************
** Function         :READ_PERIODIC_DID_DATA_ID_0

** Description      :Get Periodic Data of F200  .

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t READ_PERIODIC_DID_DATA_ID_0(uint8_t buffer[], uint16_t len)
{
	/* Dummy Code for Testing, change as per application */
	uint8_t idx;
	uint8_t ret_val = ISOUDS_TRUE;

	for(idx = 0; idx < len; idx++)
	{
		buffer[idx] = idx + 10;
		ret_val = ISOUDS_FALSE;
	}

	return ret_val;
	/* End of Dummy Code */
}

/*******************************************************************************
** Function         :READ_PERIODIC_DID_DATA_ID_1

** Description      :Get Periodic Data of F201  .

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t READ_PERIODIC_DID_DATA_ID_1(uint8_t buffer[], uint16_t len)
{
	/* Dummy Code for Testing, change as per application */
	uint8_t idx;
	uint8_t ret_val = ISOUDS_TRUE;

	for(idx = 0; idx < len; idx++)
	{
		buffer[idx] = idx + 20;
		ret_val = ISOUDS_FALSE;
	}

	return ret_val;
	/* End of Dummy Code */
}

/*******************************************************************************
** Function         :READ_PERIODIC_DID_DATA_ID_2

** Description      :Get Periodic Data of F202  .

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t READ_PERIODIC_DID_DATA_ID_2(uint8_t buffer[], uint16_t len)
{
	/* Dummy Code for Testing, change as per application */
	uint8_t idx;
	uint8_t ret_val = ISOUDS_TRUE;

	for(idx = 0; idx < len; idx++)
	{
		buffer[idx] = idx + 30;
		ret_val = ISOUDS_FALSE;
	}

	return ret_val;
	/* End of Dummy Code */
}
/*******************************************************************************
** Function         :READ_PERIODIC_DID_DATA_ID_3

** Description      :Get Periodic Data of F203  .

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t READ_PERIODIC_DID_DATA_ID_3(uint8_t buffer[], uint16_t len)
{
	/* Dummy Code for Testing, change as per application */
	uint8_t idx;
	uint8_t ret_val = ISOUDS_TRUE;

	for(idx = 0; idx < len; idx++)
	{
		buffer[idx] = idx + 40;
		ret_val = ISOUDS_FALSE;
	}

	return ret_val;
	/* End of Dummy Code */
}
/*******************************************************************************
** Function         :READ_PERIODIC_DID_DATA_ID_4

** Description      :Get Periodic Data of F204  .

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t READ_PERIODIC_DID_DATA_ID_4(uint8_t buffer[], uint16_t len)
{
	/* Dummy Code for Testing, change as per application */
	uint8_t idx;
	uint8_t ret_val = ISOUDS_TRUE;

	for(idx = 0; idx < len; idx++)
	{
		buffer[idx] = idx + 50;
		ret_val = ISOUDS_FALSE;
	}

	return ret_val;
	/* End of Dummy Code */
}

#endif
