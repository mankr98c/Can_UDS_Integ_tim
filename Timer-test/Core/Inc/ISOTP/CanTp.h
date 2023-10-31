/***************************************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOTP_Cfg.c
** Module name  : Can Transport layer configuration file.
** -------------------------------------------------------------------------------------------------
**
** Description  : Provides configuration of CAN TP layer.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : None
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for CANTP module
**
***************************************************************************************************/
/* To avoid multi-inclusions */
#ifndef ISOTP_H
#define ISOTP_H

/************************************* Inclusion files ********************************************/
#include "CanTp_Cfg.h"

/************************** Declaration of global symbol and constants ****************************/
/****************************** External links of global variables ********************************/

/********************************* Declaration of global macros ***********************************/

#define     ISOTP_FALSE                 0x00U
#define     ISOTP_TRUE                  0x01U

#define     ISOTP_ZERO                  0x00U
#define     ISOTP_ONE                   0x01U
#define     ISOTP_TWO                   0x02U
#define     ISOTP_THREE                 0x03U
#define     ISOTP_FOUR                  0x04U
#define     ISOTP_FIVE                  0x05U
#define     ISOTP_SIX                   0x06U
#define     ISOTP_SEVEN                 0x07U
#define     ISOTP_EIGHT                 0x08U
#define     ISOTP_ENDVALUE              0xFFU

#define     ISOTP_FRAMEMASK             (0xF0U)
#define     ISOTP_SEQMASK               (0x0FU)
#define     ISOTP_TIMERLMT              (0x0AU)

#define     ISOTP_TIMERLMT1             (0x7FU)
#define     ISOTP_TIMERLMT2             (0xF1U)
#define     ISOTP_TIMERLMT3             (0xF9U)

/* Frame Types */
#define     ISOTP_SF                    (0x00U)  /* Single frame */
#define     ISOTP_FF                    (0x10U)  /* First frame */
#define     ISOTP_CF                    (0x20U)  /* Consecutive frame */
#define     ISOTP_FC                    (0x30U)  /* Flow Control frame */

/* Index of ISOTP_iTimeOut[] structure */
#define     ISOTP_TXIDX                 (0x00U)  /* Transmission(sender) timer limits index */
#define     ISOTP_RXIDX                 (0x01U)  /* Reception(receiver) timer limits index */

/* State machine values */
#define     ISOTP_NWLST_IDLE            (0x00U)      /* Idle */
#define     ISOTP_NWLST_RXINPROG        (0x01U)      /* Receive in progress */
#define     ISOTP_NWLST_PROCINPROG      (0x02U)      /* Processing in progress */
#define     ISOTP_NWLST_TXINPROG        (0x03U)      /* Transmission in progress */

/* Flow status : Continue To Send */
#define     ISOTP_FCCTS                 (0x00U)
/* Flow status : WAIT */
#define     ISOTP_FCWT                  (0x01U)
/* Flow status : Overflow */
#define     ISOTP_FCOVFLW               (0x02U)

/* State machine values */
#define     ISOTP_IDLE                  (0x00U)
#define     ISOTP_SFRX                  (0x01U)
#define     ISOTP_SFTX                  (0x02U)
#define     ISOTP_FFRX                  (0x03U)
#define     ISOTP_FCTX                  (0x04U)
#define     ISOTP_FCTXREQ               (0x05U)
#define     ISOTP_CFWAIT                (0x06U)
#define     ISOTP_CFRX                  (0x07U)
#define     ISOTP_FFTX                  (0x08U)
#define     ISOTP_FCWAIT                (0x09U)
#define     ISOTP_CFTXWAIT              (0x0AU)
#define     ISOTP_CFTX                  (0x0BU)

/********************************* Declaration of global types ************************************/
typedef struct
{
    uint32_t tmrA;     /* timer A */
    uint32_t tmrB;     /* timer B */
    uint32_t tmrC;     /* timer C */
}ISOTP_TimeoutT;

typedef enum
{
	ISOTP_STANDARD = 0,
	ISOTP_EXTENDED
}ISOTP_IDFormat_e;

enum
{
    ISOTP_OK = 0,
    ISOTP_TIMEOUT_A,
    ISOTP_TIMEOUT_BS,
    ISOTP_TIMEOUT_CR,
    ISOTP_WRONG_SN,
    ISOTP_INVALID_FS,
    ISOTP_UNEXP_PDU,
    ISOTP_WFT_OVRN,
    ISOTP_BUFFER_OVFLW,
    ISOTP_ERROR
};



typedef struct
{
    uint32_t Msg_ID;
    uint8_t  dlc;
    uint8_t  dataBuff[ISOTP_EIGHT];
}ISOTP_Msg_Type;

typedef struct
{
    uint8_t *dataPtr;                    /* pointer to data */
    uint16_t dataLen;                     /* data buffer */
    uint32_t CanReqID;
    uint32_t CanRespID;
    uint32_t CanReqIDType;
    uint32_t CanRespIDType;
}ISOTP_App_CfgType;

/****************************** External links of global constants ********************************/
extern const ISOTP_TimeoutT ISOTP_iTimeOut[ISOTP_TIMEOUT_TAB];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/
extern void ISOTP_Init (void);
extern void ISOTP_RxMsgCbk(uint32_t tpMsg_ID, uint8_t MesgType, uint8_t tpdlc,const uint8_t *dataBuff);
extern uint8_t ISOTP_TxRequest ( uint16_t dataLen,const uint8_t *dataPtr);
extern void ISOTP_TxCnfCbk (void);
extern uint8_t ISOTP_GetStatus(void);
extern void ISOTP_Main (void);


#endif
