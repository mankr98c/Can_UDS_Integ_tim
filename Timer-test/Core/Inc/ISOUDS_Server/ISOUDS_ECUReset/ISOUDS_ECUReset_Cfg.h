/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ECUReset.h
**
** Description  : Include component of ISOUDS_ECUReset.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_ECURESET_CFG_H
#define ISOUDS_ECURESET_CFG_H

/************************************* Inclusion files ********************************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
#define ISOUDS_ECURSTMaxSubFun		3U
#define ISOUDS_ECURSTMaxSAlevel		(1U)
/********************************* Declaration of global types ************************************/
typedef enum
{
	ISOUDS_HARDRESET = 0x01,
	ISUODS_KEYOFFON = 0x02,
	ISOUDS_SOFTRESET = 0x03
}ISOUDS_ContType_e;

typedef struct
{
	ISOUDS_ContType_e Subfun;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_ECURSTMaxSAlevel];
	uint8_t (*SubFunCbk)(void);
}ISOUDS_EcuRstCfg_t;


/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_EcuRstCfg_t ISOUDS_ECURSTCfgTbl[ISOUDS_ECURSTMaxSubFun];
/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_ECURSTMaxSubFun

** Description              : Return the Number of Subfunctions configured for ECU Reset

** Paramete           		: None

** Return value             : retVal : Number of subfunctions Supported

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_ECURSTMaxSubFun(void);

#endif  /* ISOUDS_ECURESET_CFG_H */
