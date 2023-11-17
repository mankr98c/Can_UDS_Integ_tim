/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Comn.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Common file of components ISOUDS_Client and UDS_Server
**
** -----------------------------------------------------------------------------
**
** Documentation reference :
**
********************************************************************************
** R E V I S I O N H I S T O R Y
********************************************************************************
** V01.00
** - Baseline for UDS module
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef _ISOUDS_COMN_H_
#define _ISOUDS_COMN_H_

/************************************* Inclusion files ************************/
//#include <stdint.h>
#include <stdint.h>
/************************** Declaration of global symbol and constants ********/
#define ISOUDS_CLIENT		0
#define ISOUDS_SERVER		1
#define ISOUDS_APP_CONFIG	ISOUDS_SERVER

/* Endianness Configuration */
#define ISOUDS_LITTLE_ENDIAN	0x00
#define ISOUDS_BIG_ENDIAN		0x01
#define ISOUDS_ENDIAN_CONFIGURATION ISOUDS_LITTLE_ENDIAN


#define     ISOUDS_DS              (0x01)      /* Default Session */
#define     ISOUDS_PRGS            (0x02)      /* Programming Session */
#define     ISOUDS_EXTDS           (0x03)      /* Extended diagnostic Session */
#define     ISOUDS_SAFETYDIAGSESS  (0x04)      /* Safety System Diagnostic */


#define     ISOUDS_NEGRESPSID      (0x7F)      /* SID for Negative response */

#define		ISOUDS_POSRES			(0x00)

#define		ISOUDS_SUPPRES_POS_RESP	(0x80)

/* Negative response codes (ISO 14229) */
#define     ISOUDS_SNSIAS          (0x7F)      /* Service Not Supported In
												  Active Session */
#define     ISOUDS_SNS             (0x11)      /* Service Not Supported */
#define     ISOUDS_SFNS            (0x12)      /* Sub Function Not Supported */
#define     ISOUDS_IMLOIF          (0x13)      /* Incorrect Message Length Or Invalid Format */
#define     ISOUDS_RTL	           (0x14)      /* Response too Long */

#define		ISOUDS_AR			   (0x34)		/* Authentication Required */

#define     ISOUDS_ENOA			   (0x36)      /* Exceeded Number Of Attempts */

#define 	ISOUDS_RTDNE		   (0x37)      /* Required Time Delay Not
												  Expired */
#define     ISOUDS_RCRRP           (0x78)      /* Request Correctly Received -
												  Response Pending */
#define     ISOUDS_ROOR            (0x31)      /* Request Out of Range */
#define     ISOUDS_CNC             (0x22)      /* Conditions Not Correct */
#define     ISOUDS_GPF             (0x72)      /* General Programming Failure */
#define     ISOUDS_SAD             (0x33)      /* Security Access Denied */
#define     ISOUDS_UDNA            (0x70)      /* Upload/Download not
												  accepted */
#define     ISOUDS_RSE             (0x24)      /* Request Sequence Error */
#define     ISOUDS_WBSC            (0x73)      /* Wrong Block Sequence
												  Counter */
#define     ISOUDS_TDS             (0x71)      /* Transfer Data Suspended */
#define     ISOUDS_IK              (0x35)      /* Invalid Key */
#define     ISOUDS_SFNSACTSESS	   (0x7EU)     /* sub Function Not Supported In
												  ActiveSession */
#define		ISOUDS_ENGRUNNING	    (0x83U)		/* Engine is running */
#define		ISOUDS_VEHSPEDTOOHIGH   (0x88U)		/* Vehicle Speed too High */

/* State machine values */
#define     ISOUDS_IDLE            (0x00)      /* Idle */
#define     ISOUDS_RXPEND          (0x01)      /* Receive Pending */
#define     ISOUDS_RXMSG           (0x02)      /* Message received */
#define     ISOUDS_RESP            (0x03)      /* Positive response */
#define     ISOUDS_RESPNEG         (0x04)      /* Negative response */
#define     ISOUDS_RESPPEND        (0x05)      /* Response pending */
#define     ISOUDS_TXRESPPEND      (0x06)      /* Transmit response pending */
#define     ISOUDS_TXPEND          (0x07)      /* Transmission confirmation
												  Pending */
#define 	ISOUDS_TRUE             (1U)
#define 	ISOUDS_FALSE            (0U)

#define 	NULL_PTR 				((void *)0)

/* Indexing */
#define INDEX_ZERO				(uint8_t)0
#define INDEX_ONE				(uint8_t)1
#define INDEX_TWO				(uint8_t)2
#define INDEX_THREE				(uint8_t)3
#define INDEX_FOUR				(uint8_t)4
#define INDEX_FIVE				(uint8_t)5
#define INDEX_SIX				(uint8_t)6
#define INDEX_SEVEN				(uint8_t)7
#define INDEX_EIGHT				(uint8_t)8
#define INDEX_NINE				(uint8_t)9
#define INDEX_TEN				(uint8_t)10
#define INDEX_ELEVEN			(uint8_t)11
#define INDEX_TWELVE			(uint8_t)12
#define INDEX_THIRTEEN			(uint8_t)13
#define INDEX_FOURTEEN			(uint8_t)14

#define 	ISOUDS_NEG_RESPLEN		(uint16_t)3
#define 	ISOUDS_POS_RESP			(uint8_t)0x40
#define     ISOUDS_FOUR             (uint8_t)4
#define     ISOUDS_THREE            (uint8_t)3
#define     ISOUDS_TWO              (uint8_t)2
#define     ISOUDS_FIVE				(uint8_t)5
#define     ISOUDS_ONE              (uint8_t)1
#define     ISOUDS_ZERO             (uint8_t)0
#define     ISOUDS_HUNDRED          (uint8_t)100
#define     ISOUDS_TENTHOUSAND      (uint16_t)10000
#define     ISOUDS_MSBval			(0xFF00u)
#define     ISOUDS_LSBval			(0x00FFu)
#define     ISOUDS_SUPPRESSBIT		(0x80)

typedef enum
{
   UnlockedL1 =0x01,
   UnlockedL2 =0x03,
   UnlockedL3 =0x05,
   UnlockedL4 =0x07
}ISOUDS_SASuppLevel;


/* Session Selection(SS) Configuration */
/*----------------------------------------------------------------------------*/
/*          E P D R                    EXTDS    = Extended Diagnostic Session */
/*          X R S E                    PRGS     = Programming Session */
/*          T G   S                    DS       = Default Session */
/*          D S   V                    RESV     = Reserved */
/*          S                          */
/*----------------------------------------------------------------------------*/

#define  EXTENDED_SESS						(uint8_t)(1<<ISOUDS_EXTENDED)
#define  PROGRAMMING_SESS					(uint8_t)(1<<ISOUDS_PROGRAMMING)
#define  DEFAULT_SESS						(uint8_t)(1<<ISOUDS_DEFAULT)
#define  SAFETY_SESS 						(uint8_t)(1<<ISOUDS_SAFETY)

typedef enum
{
	ISOUDS_STANDARD_ID = 0,
	ISOUDS_EXTENDED_ID
}ISOUDS_IDFormat_e;

typedef enum
{
	ISOUDS_FUNCTIONALREQ = 1,
	ISOUDS_PHYSICALREQ = 2,
	ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL = 3
}ISOUDS_AddrType;

typedef struct
{
    uint8_t  srvSt;          /* UDS service state */
    uint8_t  srvId;          /* UDS service id */
    uint8_t  srvNegResp;     /* Negative response code of the service */
    uint8_t  srvFrame;       /* Service request received in single or multiple
						      frame */
    uint16_t srvLen;         /* length */
    ISOUDS_AddrType ReqType;
}ISOUDS_ConfType;

typedef struct {
	/*CAN msg Id*/
	uint32_t RequestID;		/* For Server: It is Request ID, For Client It is Response ID */
	uint32_t ResponseID;	/* For Server: It is Response ID, For Client It is Request ID */
	uint8_t RequestIDType;
	uint8_t ResponseIDType;
}ISOUDS_DiagRxMsgId_st;

#endif  /* _ISOUDS_COMN_H_ */
