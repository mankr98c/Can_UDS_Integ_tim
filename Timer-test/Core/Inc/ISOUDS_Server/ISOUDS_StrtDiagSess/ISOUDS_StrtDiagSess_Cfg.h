/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_StrtDiagSess.h
**
** Description  : Include file for component ISOUDS_StrtDiagSess.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_STRTDIAGSESSCFG_H
#define ISOUDS_STRTDIAGSESSCFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_SA.h"
/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
#define ISOUDS_StrtDiagSessCfgMaxSubFun		(4U)
#define ISOUDS_StrtDiagSessMaxSAlevel		(1U)
/********************************* Declaration of global types ************************************/
typedef enum
{
	ISOUDS_DEFAULT = 0x01,
	ISOUDS_PROGRAMMING = 0x02,
	ISOUDS_EXTENDED = 0x03,
	ISOUDS_SAFETY = 0x04
}ISOUDS_StrtDiagSessType_e;

typedef struct
{
	uint8_t SubfunctionVal;
	uint8_t SubfunMapVal;
}ISOUDS_SessSubfunMap;

typedef struct
{
	uint8_t Subfun;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_StrtDiagSessMaxSAlevel];
	uint8_t (*SubFunCbk)(ISOUDS_ConfType *ISOUDSConfPtr);
}ISOUDS_StrtDiagSessCfg_t;


/****************************** External CANks of global variables ********************************/
extern ISOUDS_StrtDiagSessCfg_t ISOUDS_StrtDiagSessCfg_Tbl[ISOUDS_StrtDiagSessCfgMaxSubFun];
/****************************** External CANks of global constants ********************************/
extern const ISOUDS_SessSubfunMap ISOUDS_SessSubfunMap_Tbl[ISOUDS_StrtDiagSessCfgMaxSubFun];
/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t ISOUDS_Get_StrtDiagSessCfgMaxSub(void);

#endif  /* ISOUDS_STRTDIAGSESSCFG_H */
