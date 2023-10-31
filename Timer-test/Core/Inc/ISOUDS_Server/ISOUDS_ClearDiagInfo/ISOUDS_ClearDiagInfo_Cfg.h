/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_ClearDiagInfo_Cfg.h
**
** Description  : Include component of ISOUDS_ClearDiagInfo_Cfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_CLRDTCCFG_H
#define ISOUDS_CLRDTCCFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
#define ISOUDS_CLRDIAG_INFO_SEC_SUPP	(0U)
#define ISOUDS_CLRDIAG_INFO_SEC_LEVL	(1U)

#define ISOUDS_CLRDIAG_INFO_MASK_VAL    (0xFFFFFFU)
/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/
/*******************************************************************************
** Function                 : ISOUDS_ClearDTCInfoPreCondCheck
**
** Description              : Checks the pre conditions for Clear DTC information
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_ClearDTCInfoPreCondCheck(void);

/*******************************************************************************
** Function                 : ISOUDS_CLearDTCInfoReq
**
** Description              : Clear DTC Info Request
**
** Parameters 				: DTCNumber : DTC number to be cleared
**
** Return value             : Response Value
*******************************************************************************/
extern uint8_t ISOUDS_CLearDTCInfoReq(uint32_t DTCNumber, uint8_t MemorySelection);

/*******************************************************************************
** Function                 : ISOUDS_CLearDTCInfoReqStat
**
** Description              : Clear DTC Info Request status
**
** Parameters 				: DTCNumber : DTC number to be cleared
**
** Return value             : Response Value
*******************************************************************************/
extern uint8_t ISOUDS_CLearDTCInfoReqStat(void);
#endif /* ISOUDS_COMMCNTRL_CFG_H */
