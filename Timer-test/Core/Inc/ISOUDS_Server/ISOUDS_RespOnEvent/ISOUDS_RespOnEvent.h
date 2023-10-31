/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RespOnEvent.h
**
** Description  : Response on event service
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RESPONEVENT_H
#define ISOUDS_RESPONEVENT_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_RespOnEvent_Cfg.h"
/************************** Declaration of global symbol and constants ****************************/
/* SID of ECU Reset service */
#define     ISOUDS_SIDRESPONEVENT				(0x86U)
#define     ISOUDS_SIDRESPONEVENT_POSRESP		(0xC6U)

#define	ISOUDS_STOPRESPONSEONEVENT			0x00
#define	ISOUDS_ONDTCSTATUSCHANGE			0x01
#define	ISOUDS_ONTIMERINTERRUPT				0x02
#define	ISOUDS_ONCHANGEOFDATAIDENTIFIER		0x03
#define	ISOUDS_REPORTACTIVATEDEVENTS		0x04
#define	ISOUDS_STARTRESPONSEONEVENT			0x05
#define	ISOUDS_CLEARRESPONSEONEVENT			0x06
#define	ISOUDS_ONCOMPARISONOFVALUES			0x07
#define	ISOUDS_REPMOSTRSNTDTCONSTATCHNG		0x08
#define	ISOUDS_REPDTCRECINFOONDTCSTTCHNG	0x09

#define REPORTMOSTRECENTTESTFAILEDDTC		0x0D
#define REPORTMOSTRECENTCONFIRMEDDTC		0x0E

#define ISOUDS_INFINITE_WINDOW				0x2

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_RespOnEvent(ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
#endif  /* ISOUDS_ECURESET_H */
