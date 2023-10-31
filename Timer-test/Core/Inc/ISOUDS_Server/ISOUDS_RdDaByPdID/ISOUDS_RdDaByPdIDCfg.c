/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByPdIDCfg.c
**
** Description  : Read Data Identifier configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_RdDaByPdIDCfg.h"
#include "ISOUDS_RdDaByPdID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/
const ISOUDS_RdPdDidType ISOUDS_RdPdDidDaConfTab[ISOUDS_RDPDDIDDACONFTABSIZE] =
{

	{
        (uint16_t)ISOUDS_RDPD_ID_0,
        (uint8_t)ISOUDS_RDPDID0_DATA_LEN,
        /* MISRA RULE 11.4 VIOLATION: cast from pointer to uint8_t* pointer to
		   facilitate reading -
           - of individual bytes from the address locations */
        NULL,
        &READ_PERIODIC_DID_DATA_ID_0,
        (uint8_t)(EXTENDED_SESS),
		ISOUDS_FALSE,
		 0,
		{UnlockedL1},
    },

	{
        (uint16_t)ISOUDS_RDPD_ID_1,
        (uint8_t)ISOUDS_RDPDID1_DATA_LEN,
        /* MISRA RULE 11.4 VIOLATION: cast from pointer to uint8_t* pointer to
		   facilitate reading -
           - of individual bytes from the address locations */
        NULL,
        &READ_PERIODIC_DID_DATA_ID_1,
        (uint8_t)(EXTENDED_SESS),
		ISOUDS_FALSE,
		 0,
		{UnlockedL1}
    },

	{
        (uint16_t)ISOUDS_RDPD_ID_2,
        (uint8_t)ISOUDS_RDPDID2_DATA_LEN,
        /* MISRA RULE 11.4 VIOLATION: cast from pointer to uint8_t* pointer to
		   facilitate reading -
           - of individual bytes from the address locations */
        NULL,
        &READ_PERIODIC_DID_DATA_ID_2,
        (uint8_t)(EXTENDED_SESS),
		ISOUDS_FALSE,
		 0,
		{UnlockedL1}
    },

	{
        (uint16_t)ISOUDS_RDPD_ID_3,
        (uint8_t)ISOUDS_RDPDID3_DATA_LEN,
        /* MISRA RULE 11.4 VIOLATION: cast from pointer to uint8_t* pointer to
		   facilitate reading -
           - of individual bytes from the address locations */
		NULL,
        &READ_PERIODIC_DID_DATA_ID_3,
        (uint8_t)(EXTENDED_SESS),
		ISOUDS_TRUE,
		 0,
		{UnlockedL1}
    },

	{
        (uint16_t)ISOUDS_RDPD_ID_4,
        (uint8_t)ISOUDS_RDPDID4_DATA_LEN,
        /* MISRA RULE 11.4 VIOLATION: cast from pointer to uint8_t* pointer to
		   facilitate reading -
           - of individual bytes from the address locations */
        NULL,
        &READ_PERIODIC_DID_DATA_ID_4,
        (uint8_t)(EXTENDED_SESS),
		ISOUDS_TRUE,
		 0,
		{UnlockedL1}
    }
};

/***************************************************************************************************
** Function                 : ISOUDS_Get_RDPDDIDDACONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Read DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_RDPDDIDDACONFTABSIZE(void)
{
	return ISOUDS_RDPDDIDDACONFTABSIZE;
}
/*******************************************************************************/

#endif
