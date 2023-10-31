/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RtnCntrl_Cfg.h
**
** Description  : Include component of ISOUDS_RtnCntrl_Cfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RTNCNTRL_CFG_H
#define ISOUDS_RTNCNTRL_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_RtnContrlMaxSubFun		(3U)

#define ISOUDS_NUMBER_OF_RTN_PARAM_SUPP	(1)
#define ISOUDS_RtnContrlMaxSAlevel		(1U)
/********************************* Declaration of global types ****************/
typedef struct
{
	uint16_t RtnCntrlID;
	uint8_t SuptdSession;
	uint8_t NumOfRtntypeSup;
	uint8_t RtntypeSupp[ISOUDS_NUMBER_OF_RTN_PARAM_SUPP];
	uint16_t RtnCntrlIDLen;
	uint8_t SecAccssSup;
	uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_RtnContrlMaxSAlevel];
	uint8_t (*SubFunCbk)(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth);
}ISOUDS_RtnCntrlCfg_t;

#define ISOUDS_RTN_CHECK_MEM				0x0200
#define ISOUDS_RTN_ERASE_MEM				0xFF00
#define ISOUDS_RTN_CHECKPROGDEP				0xFF01

#define ISOUDS_RTNFORMATIDENTIFIER				0x44

/****************************** External CANks of global variables ************/
extern ISOUDS_RtnCntrlCfg_t ISOUDS_RtnCntrlCfg_Tbl[ISOUDS_RtnContrlMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_RtnContrlMaxSubFun

** Description              : Return the Number of RID configured for Routine Control

** Paramete           		: None

** Return value             : retVal : Number of RIDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_RtnContrlMaxSubFun(void);

/*******************************************************************************
** Function                 : ISOUDS_RtnControlTypeSuppChk
**
** Description              : Checks if the Routine type is supported or not
**
** Parameters 				: RoutineType  : Routine Type received
**							: RoutineIDIndex : Routine ID index
**
** Return value             : RetVal : Communication type validity
*******************************************************************************/
uint8_t ISOUDS_RtnControlTypeSuppChk(uint8_t RoutineType, uint16_t RoutineIDIndex);

/*******************************************************************************
** Function                 : ISOUDS_RtnCntrlPreCondCheck
**
** Description              : Checks the pre conditions for Routine Control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_RtnCntrlPreCondCheck(void);


#endif /* ISOUDS_COMMCNTRL_CFG_H */
