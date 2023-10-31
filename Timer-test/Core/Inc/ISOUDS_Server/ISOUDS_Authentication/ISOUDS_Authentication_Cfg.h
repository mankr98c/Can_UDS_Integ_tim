/*******************************************************************************
** Copyright (c) 2020 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Athentication.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Authentication Service Header File
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
#ifndef ISOUDS_AUTHENTICATION_H
#define ISOUDS_AUTHENTICATION_H

/************************************* Inclusion files ************************/

#include "ISOUDS_Server.h"
/************************** Declaration of global symbol and constants ********/


#define AUTHE_PKICERTI				(1U)
#define AUTHE_CAHLLERESP			(2U)

#define ISOUDS_AUTHECONCEPT 		AUTHE_CAHLLERESP



#define AUTHENTCATN_ACR				AUTHECONFIC_ACR_ASYMTRIC
#define AUTHECONFIC_ACR_ASYMTRIC	(1U)
#define AUTHECONFIC_ACR_SYMTRIC		(2U)

#define ISOUDS_AUTHENTMAXSUBFUN		(9U)
#define LENALGOINDICATOR			(16U)

/* Maximum attempts count  */
#define ISOUDS_AUTHMAXATTEMTCOUNT       ((uint8_t)2)
/* Authentication Timer(in msec) Till ECU will
be in Authenticated state */
#define ISOUDS_AUTHENTIMERMAX			(50000)

/* Ephermal Key Length Configuration */
#define LENEPHMPUBKEYSERVER				(3U)
/* Proof of Ownership Length Configuration */
#define LENPROOFOFOWNERSHIP				(3U)
/* Session Key Info Length Configuration */
#define LENSESSIONKEYINFO				(3U)
/* Algorithm Indicator Length Configuration */
#define LENALGOINDICTR					(16U)
/* Challenge Server Length Configuration */
#define LENCHALLSERVER					(3U)
/* Certificate Server Length Configuration */
#define LENCERTIFICTESERVER				(3U)
/* Additional Parameter Length Configuration */
#define LENNEEDEDADDPARAM				(3U)


#define REQUESTACCEPTED								0x00
#define GENERALREJECT								0x01
#define AUTHENCONFIG_ACAPCE							0x02
#define AUTHETCONFIG_ACACRAC						0x03
#define AUTHETCONFIG_ACACRSC						0x04
#define DEAUTHENTICATIONCOMPLETE					0x10
#define CERTIVERIFIEDOWNERSHIPVERIFICTNNECESARY		0x11
#define OWNERVERIFIEDAUTHETICNCOMPLET				0x12
#define CERTIFICATEVERIFIED							0x13


#define ISOUDS_AUTHENREQ							(0x34)


#define NO_0 		0U	
#define NO_1 		1U	
#define NO_2 		2U	
#define NO_3 		3U	
#define NO_4 		4U	
#define NO_5 		5U	
#define NO_6 		6U
#define NO_8 		8U	


/********************************* Declaration of global types ****************/

typedef enum
{
	ISOUDS_DEAUTHENTICATE = 0u,
	ISOUDS_VERIFYCERTIFICATEUNIDIR = 1u,
	ISOUDS_VERIFYCERTIFICATEBIDIR = 2u,
	ISOUDS_PROOFOFOWNERSHIP = 3u,
	ISOUDS_TRANSMITCERTIFICATE = 4u,
	ISOUDS_REQCHALLANGEFORAUTHENT = 5u,
	ISOUDS_VERIFYPROOFOWNERUNIDIR = 6u,
	ISOUDS_VERIFYPROOFOWNERBIDIR = 7u,
	ISOUDS_AUTHENTICATIONCONFIG = 8u,
	ISOUDS_MAX,
	
}ISOUDS_AuthenticationSubType_e;

typedef struct
{
	ISOUDS_AuthenticationSubType_e Subfun;
	uint8_t SuptdSession;
	/*uint8_t SecAccssSup;
	uint8_t SecAccssLevl;*/
	uint8_t (*SubFunCbk)(uint8_t *Data);
}ISOUDS_AuthentSubCfg_t;

/****************************** External links of global variables ************/

extern ISOUDS_AuthentSubCfg_t ISOUDS_AuthentSubCfg[ISOUDS_AUTHENTMAXSUBFUN];

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                             **
*******************************************************************************/

/********************************** Function definitions **********************/
/*******************************************************************************
** Function                 : ISOUDS_DeAuthenticate_Cbk
**
** Description              : Deauthenticate the Service
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_DeAuthenticate_Cbk( uint8_t *Data);


/*******************************************************************************
** Function                 : ISOUDS_VerifyCertificateUniDir_cbk
**
** Description              : Verify the Certificate
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_VerifyCertiUniDir_cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_VerifyCertificateBiDir_Cbk
**
** Description              : Verify the Certificate
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_VerifyCertiBiDir_Cbk( uint8_t *Data);


/*******************************************************************************
** Function                 : ISOUDS_ProofOfOwnership_Cbk
**
** Description              : Send the Proof of Ownership
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_ProofOfOwnership_Cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_TransmitCertificate_Cbk
**
** Description              : send Transmit Certificate
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_TransmitCertificate_Cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_RequestChallangeforAuthent_Cbk
**
** Description              : Request challange for authentication
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_RequestChallangeforAuthent_Cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_VerifyProofofOwnerUniDir_Cbk
**
** Description              : Verify the Proof of ownership
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_VerifyProofofOwnerUniDir_Cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_VerifyProofofOwnerBiDir_Cbk
**
** Description              : Verify the Proof of ownership
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_VerifyProofofOwnerBiDir_Cbk( uint8_t *Data);

/*******************************************************************************
** Function                 : ISOUDS_AuthenticationConfig_Cbk
**
** Description              : Authentication Configuration
**
** Parameters 				: Data Pointer
** Return value             : None
*******************************************************************************/

extern uint8_t ISOUDS_AuthenticationConfig_Cbk( uint8_t *Data);



/*******************************************************************************
** Function                 : ISOUDS_RespDeauthenticate_API
**
** Description              : Authentication Configuration
**
** Parameters 				: dataBuff: data buffer
**            				
**							: Pointer to response Length
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_RespDeauthenticate_API(uint8_t *dataBuff, uint32_t *RespLen);

/*******************************************************************************
** Function                 : ISOUDS_RespVeriCertiDir_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_RespVeriCertiUniDir_API(uint8_t dataBuff[], uint32_t *RespLen);

extern void ISOUDS_RespVeriCertiBiDir_API(uint8_t dataBuff[], uint32_t *RespLen);
/*******************************************************************************
** Function                 : ISOUDS_SendRespwithSessKey_API
**
** Description              : Authentication Configuration
**
** Parameters 				: dataBuff: data buffer
**            				
**							: Pointer to response Length
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_SendRespwithSessKey_API(uint8_t dataBuff[], uint32_t *RespLen);
											
/*******************************************************************************
** Function                 : ISOUDS_RespTransCerti_API
**
** Description              : Authentication Configuration
**
** Parameters 				: dataBuff: data buffer
**            				
**							: Pointer to response Length
**
** Return value             : None
*******************************************************************************/
extern uint8_t ISOUDS_RespTransCerti_API(uint8_t dataBuff[], uint32_t *RespLen);

/*******************************************************************************
** Function                 : ISOUDS_SndChaServerwithAlgoInd_API
**
** Description              : Authentication Configuration
**
** Parameters 				: dataBuff: data buffer
**            				
**							: Pointer to response Length
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_SndChaServerwithAlgoInd_API(uint8_t dataBuff[], uint32_t *RespLen);

/*******************************************************************************
** Function                 : ISOUDS_SendProofofOwner_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_SendProofofOwnerUniDir_API(uint8_t dataBuff[], uint32_t *RespLen);

extern void ISOUDS_SendProofofOwnerBiDir_API(uint8_t dataBuff[], uint32_t *RespLen);

/*******************************************************************************
** Function                 : ISOUDS_RespAuthenConfig_API
**
** Description              : Authentication Configuration
**
** Parameters 				: dataBuff: data buffer
**            				
**							: Pointer to response Length
**
** Return value             : None
*******************************************************************************/
extern uint8_t ISOUDS_RespAuthenConfig_API(uint8_t dataBuff[], uint32_t *RespLen);




#endif
