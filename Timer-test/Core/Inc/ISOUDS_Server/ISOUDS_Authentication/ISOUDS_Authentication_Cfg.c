/*******************************************************************************
** Copyright (c) 2020 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Athentication.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Authentication Service
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

/**************************************** Inclusion files *********************/

#include "ISOUDS_Server.h"
#include "ISOUDS_Authentication_Cfg.h"
#include "ISOUDS_Authentication_HAL.h"

#if ((ISOUDS_APP_CONFIG == ISOUDS_SERVER) || (ISOUDS_APP_CONFIG == ISOUDS_BOTH_CLIENT_SERVER))
/********************** Declaration of local symbol and constants *************/


/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/
/******************************* Declaration of local variables ***************/




ISOUDS_AuthentSubCfg_t ISOUDS_AuthentSubCfg[ISOUDS_AUTHENTMAXSUBFUN] =	{
																			{
																				ISOUDS_DEAUTHENTICATE,
																				EXTENDED_SESS | PROGRAMMING_SESS |DEFAULT_SESS ,
																				&ISOUDS_DeAuthenticate_Cbk
																			},
																			{
																				ISOUDS_VERIFYCERTIFICATEUNIDIR,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_VerifyCertiUniDir_cbk
																			},
																			{
																				ISOUDS_VERIFYCERTIFICATEBIDIR,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_VerifyCertiBiDir_Cbk
																			},
																			{
																				ISOUDS_PROOFOFOWNERSHIP,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_ProofOfOwnership_Cbk
																			},
																			
																			{
																				ISOUDS_TRANSMITCERTIFICATE,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_TransmitCertificate_Cbk
																			},
																			{
																				ISOUDS_REQCHALLANGEFORAUTHENT,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_RequestChallangeforAuthent_Cbk,
																				
																			},
																			{
																				ISOUDS_VERIFYPROOFOWNERUNIDIR,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_VerifyProofofOwnerUniDir_Cbk
																			},
																			{
																				ISOUDS_VERIFYPROOFOWNERBIDIR,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_VerifyProofofOwnerBiDir_Cbk
																			},
																			{
																				ISOUDS_AUTHENTICATIONCONFIG,
																				EXTENDED_SESS | PROGRAMMING_SESS | DEFAULT_SESS,
																				&ISOUDS_AuthenticationConfig_Cbk
																			}
																			
																		};

/******************************* Declaration of local constants ***************/


/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                             **
*******************************************************************************/

/**************************** Internal functions declarations *****************/


/******************************** Function definitions ************************/
/*******************************************************************************
** Function                 : ISOUDS_DeAuthenticate_Cbk
**
** Description              : De-authenticate the Service
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_DeAuthenticate_Cbk( uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat;

	(void)Data;
	/* Call the Hal layer */
	RespStat = HAL_DeAuthentication_Cbk();
	
	/* Return the value */
	return RespStat;
}


/*******************************************************************************
** Function                 : ISOUDS_VerifyCertiUniDir_cbk
**
** Description              : Verify the Certificate
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_VerifyCertiUniDir_cbk( uint8_t *Data)
{

	/* Response State */
	uint8_t RespStat = NO_0;
	/* Communication Configuration  value */
	uint8_t CommConfig;
	/* Length of client Certificate*/
	uint16_t LenCrtificateClient;
	/* Length of Challenge client */
	uint16_t LenChallengeClient;
	/* Index to first byte of Length Challenge client */
	uint16_t Index1stByteChallngClientLen;
	/* Index to first byte of Length Challenge client */
	uint16_t Index2ndByteChallngClientLen;
	/* Index to first byte of  Challenge client */
	uint16_t Index1stByteChallngClient;

	/*retrieve the communication configuration value */
	CommConfig = Data[NO_0];
	/* Length of client Certificate*/
	LenCrtificateClient = ((Data[NO_1]<<NO_8) | Data[NO_2]);
	/* Extract the index for Length of Challenge client */
	Index1stByteChallngClientLen = (NO_2+LenCrtificateClient+NO_1);
	/* Extract the index for Length of Challenge client */
	Index2ndByteChallngClientLen = (NO_2+LenCrtificateClient+NO_2);
	/* Length of Challenge client */
	LenChallengeClient = ((Data[Index1stByteChallngClientLen] << NO_8) | (Data[Index2ndByteChallngClientLen]));
	/* Index to first byte of  Challenge client */
	Index1stByteChallngClient = (Index2ndByteChallngClientLen + NO_1);


	/* Call HAL CallBack Function */
	RespStat = HAL_VerifyCertiUniDir_Cbk(CommConfig, LenCrtificateClient, &Data[NO_3],
											LenChallengeClient,&Data[Index1stByteChallngClient]);
	/* Return the response */										
	return RespStat;
		
}

/*******************************************************************************
** Function                 : ISOUDS_VerifyCertiBiDir_Cbk
**
** Description              : Verify the Certificate
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_VerifyCertiBiDir_Cbk( uint8_t *Data)
{

	/* Response State */
	uint8_t RespStat = NO_0;
	/* Communication Configuration  value */
	uint8_t CommConfig = NO_0;
	/* Length of client Certificate*/
	uint16_t LenCrtificateClient;
	/* Length of Challenge client */
	uint16_t LenChallengeClient;
	/* Index to first byte of Length Challenge client */
	uint16_t Index1stByteChallngClientLen;
	/* Index to first byte of Length Challenge client */
	uint16_t Index2ndByteChallngClientLen;
	/* Index to first byte of  Challenge client */
	uint16_t Index1stByteChallngClient;

	/*retrieve the communication configuration value */
	CommConfig = Data[NO_0];
	/* Length of client Certificate*/
	LenCrtificateClient = ((Data[NO_1]<<NO_8) | Data[NO_2]);
	/* Index to first byte of Length Challenge client */
	Index1stByteChallngClientLen = (NO_2+LenCrtificateClient+NO_1);
	/* Index to first byte of Length Challenge client */
	Index2ndByteChallngClientLen = (NO_2+LenCrtificateClient+NO_2);
	/* Length of Challenge client */
	LenChallengeClient = ((Data[Index1stByteChallngClientLen] << NO_8) | (Data[Index2ndByteChallngClientLen]));
	/* Index to first byte of  Challenge client */
	Index1stByteChallngClient = (Index2ndByteChallngClientLen + NO_1);
	/* Call HAL CallBack Function */
	RespStat = HAL_VerifyCertiBiDir_cbk(CommConfig, LenCrtificateClient, &Data[NO_3],
													LenChallengeClient,&Data[Index1stByteChallngClient]);
	
	/* Return the response */								
	return RespStat;
	
}


/*******************************************************************************
** Function                 : ISOUDS_ProofOfOwnership_Cbk
**
** Description              : Proof of Ownership Client
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_ProofOfOwnership_Cbk( uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat = NO_0;

	/* Length Of Proof of ownership */
	uint16_t LenProofofOwner;
	/* Length of Ephemeral Public Key client */
	uint16_t LenEphmrlPubKeyClient;
	/* Index of 1st byte of Length of Ephemeral Public Key Client */
	uint16_t Indx1stbyteLenEphrmalPubkeyClnt;
	/* Index of 2nd byte of Length of Ephemeral Public Key Client */
	uint16_t Indx2ndbyteLenEphrmalPubkeyClnt;
	/* Index of 1st bytes of Ephemeral Public Key */
	uint16_t  Index1stbyteEpharmalPubKeyClnt;

	/* Length Of Proof of ownership */
	 LenProofofOwner = ((Data[NO_0]<<NO_8) | Data[NO_1]);
	/* Index of 1st byte of Length of Ephemeral Public Key Client */
	 Indx1stbyteLenEphrmalPubkeyClnt = (NO_1+LenProofofOwner+NO_1);
	/* Index of 2nd byte of Length of Ephemeral Public Key Client */
	 Indx2ndbyteLenEphrmalPubkeyClnt = (NO_1+LenProofofOwner+NO_2);
	/* Length of Ephemeral Public Key client */
	 LenEphmrlPubKeyClient = ((Data[Indx1stbyteLenEphrmalPubkeyClnt] << NO_8) | (Data[Indx2ndbyteLenEphrmalPubkeyClnt]));
	/* Index of 1st bytes of Ephemeral Public Key */
	Index1stbyteEpharmalPubKeyClnt = (Indx2ndbyteLenEphrmalPubkeyClnt + NO_1);

	
	/* Call HAL CallBack Function */
	RespStat = HAL_ProofOfOwnership_Cbk(LenProofofOwner , &Data[NO_2],
										LenEphmrlPubKeyClient, &Data[Index1stbyteEpharmalPubKeyClnt]);
	
	/* Return the response */
	return RespStat;
	
}

/*******************************************************************************
** Function                 : ISOUDS_TransmitCertificate_Cbk
**
** Description              : send Transmit Certificate
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_TransmitCertificate_Cbk( uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat = NO_0;
	/* retrieve certificate evaluation ID */
	uint16_t CertiEvalnID;
	/* Length of Certificate data */
	uint16_t LenofCertiData;
	/* retrieve certificate evaluation ID */
	 CertiEvalnID = ((Data[NO_0]<<NO_8) | Data[NO_1]);
	/* Length of Certificate data */
	 LenofCertiData = ((Data[NO_2]<<NO_8) | Data[NO_3]);

	/* Call HAL CallBack Function */
	RespStat = HAL_TransmitCertificate_Cbk(CertiEvalnID , LenofCertiData, &Data[NO_4]);
										
	/* Return the response */
	return RespStat;
	
}

/*******************************************************************************
** Function                 : ISOUDS_RequestChallangeforAuthent_Cbk
**
** Description              : Request challange for authentication
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_RequestChallangeforAuthent_Cbk( uint8_t *Data)
{

	/* Response State */
	uint8_t RespStat = NO_0;
	/* Communication Configuration  value */
	uint8_t CommConfig = NO_0;

	/* Retrieve the communication Configuration */
	CommConfig = Data[NO_0];
	
	/* Call HAL CallBack Function */
	RespStat = HAL_RequestChallangeforAuthent_Cbk(CommConfig,LENALGOINDICATOR, &Data[NO_1]);
	
	/* Return the response */
	return RespStat;
	
}

/*******************************************************************************
** Function                 : ISOUDS_VerifyProofofOwnerUniDir_Cbk
**
** Description              : Verify the Proof of ownership
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_VerifyProofofOwnerUniDir_Cbk( uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat;

	/* Length of proof of Ownership */
	uint16_t LenProofofOwnerClnt;
	/* Length of Challange Client */
	uint16_t LenChallangeClient;
	/* Length of Additional Parameter */
	uint16_t LenAddParam;

	/* Index of 2nd byte of Length of proof of ownership */
	uint16_t Indx2ndbytLenProofOnwer;
	/* Index of 1st byte of Length of Challenge Client */
	uint16_t Indx1stbytLenChallengClint;
	/* Index of 2nd byte of Length of Challenge Client  */
	uint16_t Indx2ndbytLenChallengClint;
	/* Index of 1st byte of Length of Additional Parameter */
	uint16_t Indx1stbytLenAdditnlParam;
	/* Index of 2nd byte of Length of Additional Parameter */
	uint16_t Indx2ndbytLenAdditnlParam;
	/* Index of 1st byte of Proof of ownership Client */
	uint16_t Indx1ndbytProofOfownerClint;
	/* Index of 1st byte of  Challenge Client */
	uint16_t Indx1ndbytChallngClint;
	/* Index of 1st byte of  Additional Parameter */
	uint16_t Indx1stbytAdditnlParam;


	/* Index of 2nd byte of Length of proof of ownership */
	Indx2ndbytLenProofOnwer = (LENALGOINDICATOR + NO_1);
	/* Length of proof of Ownership */
	LenProofofOwnerClnt = ((Data[LENALGOINDICATOR ] << NO_8) | Data[Indx2ndbytLenProofOnwer]);
	/* Index of 1st byte of Proof of ownership Client */
	Indx1ndbytProofOfownerClint = (Indx2ndbytLenProofOnwer + NO_1);

	/* Index of 1st byte of Length of Challenge Client */
	Indx1stbytLenChallengClint = (LENALGOINDICATOR + NO_2 + LenProofofOwnerClnt);
	/* Index of 2nd byte of Length of Challenge Client  */
	Indx2ndbytLenChallengClint = (LENALGOINDICATOR + NO_2 + LenProofofOwnerClnt + NO_1);
	/* Length of Challenge Client */
	LenChallangeClient = ((Data[Indx1stbytLenChallengClint ] << NO_8) |
								 (Data[Indx2ndbytLenChallengClint]));

	Indx1ndbytChallngClint = (Indx2ndbytLenChallengClint + NO_1);

	/* Index of 1st byte of Length of Additional Parameter */
	Indx1stbytLenAdditnlParam = (LENALGOINDICATOR + NO_4 + LenProofofOwnerClnt + LenChallangeClient);
	/* Index of 2nd byte of Length of Additional Parameter */
	Indx2ndbytLenAdditnlParam = (LENALGOINDICATOR + NO_4 + LenProofofOwnerClnt  + LenChallangeClient + NO_1);
	/* Length of Additional Parameter */
	LenAddParam = ((Data[Indx1stbytLenAdditnlParam ] << NO_8) |
						 (Data[Indx2ndbytLenAdditnlParam]));
	/* Index of 2nd byte of Length of proof of ownership */
	Indx1stbytAdditnlParam = (Indx2ndbytLenAdditnlParam + NO_1);
	

	/* Call HAL CallBack Fucntion */
	RespStat = HAL_VerifyProofofOwnerUniDir_Cbk(LENALGOINDICATOR,&Data[NO_0],LenProofofOwnerClnt,
												&Data[Indx1ndbytProofOfownerClint],LenChallangeClient,
												&Data[Indx1ndbytChallngClint],LenAddParam,
												&Data[Indx1stbytAdditnlParam]);
										
	
	/* Return the response */
	return RespStat;
	
}

/*******************************************************************************
** Function                 : ISOUDS_VerifyProofofOwnerBiDir_Cbk
**
** Description              : Verify the Proof of ownership
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_VerifyProofofOwnerBiDir_Cbk( uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of proof of Ownership */
	uint16_t LenProofofOwnerClnt;
	/* Length of Challange Client */
	uint16_t LenChallangeClient;
	/* Length of Additional Parameter */
	uint16_t LenAddParam;

	/* Index of 2nd byte of Length of proof of ownership */
	uint16_t Indx2ndbytLenProofOnwer;
	/* Index of 1st byte of Length of Challenge Client */
	uint16_t Indx1stbytLenChallengClint;
	/* Index of 2nd byte of Length of Challenge Client  */
	uint16_t Indx2ndbytLenChallengClint;
	/* Index of 1st byte of Length of Additional Parameter */
	uint16_t Indx1stbytLenAdditnlParam;
	/* Index of 2nd byte of Length of Additional Parameter */
	uint16_t Indx2ndbytLenAdditnlParam;
	/* Index of 1st byte of Proof of ownership Client */
	uint16_t Indx1ndbytProofOfownerClint;
	/* Index of 1st byte of  Challenge Client */
	uint16_t Indx1ndbytChallngClint;
	/* Index of 1st byte of  Additional Parameter */
	uint16_t Indx1stbytAdditnlParam;


	/* Index of 2nd byte of Length of proof of ownership */
	Indx2ndbytLenProofOnwer = (LENALGOINDICATOR + NO_1);
	/* Length of proof of Ownership */
	LenProofofOwnerClnt = ((Data[LENALGOINDICATOR ] << NO_8) | Data[Indx2ndbytLenProofOnwer]);
	/* Index of 1st byte of Proof of ownership Client */
	Indx1ndbytProofOfownerClint = (Indx2ndbytLenProofOnwer + NO_1);

	/* Index of 1st byte of Length of Challenge Client */
	Indx1stbytLenChallengClint = (LENALGOINDICATOR + NO_2 + LenProofofOwnerClnt);
	/* Index of 2nd byte of Length of Challenge Client  */
	Indx2ndbytLenChallengClint = (LENALGOINDICATOR + NO_2 + LenProofofOwnerClnt + NO_1);
	/* Length of Challenge Client */
	LenChallangeClient = ((Data[Indx1stbytLenChallengClint ] << NO_8) |
								 (Data[Indx2ndbytLenChallengClint]));

	Indx1ndbytChallngClint = (Indx2ndbytLenChallengClint + NO_1);

	/* Index of 1st byte of Length of Additional Parameter */
	Indx1stbytLenAdditnlParam = (LENALGOINDICATOR + NO_4 + LenProofofOwnerClnt + LenChallangeClient);
	/* Index of 2nd byte of Length of Additional Parameter */
	Indx2ndbytLenAdditnlParam = (LENALGOINDICATOR + NO_4 + LenProofofOwnerClnt  + LenChallangeClient + NO_1);
	/* Length of Additional Parameter */
	LenAddParam = ((Data[Indx1stbytLenAdditnlParam ] << NO_8) |
						 (Data[Indx2ndbytLenAdditnlParam]));
	/* Index of 2nd byte of Length of proof of ownership */
	Indx1stbytAdditnlParam = (Indx2ndbytLenAdditnlParam + NO_1);

	
	/* Call HAL CallBack Fucntion */
	RespStat = HAL_VerifyProofofOwnerBiDir_Cbk(LENALGOINDICATOR,&Data[NO_0],LenProofofOwnerClnt,
												&Data[Indx1ndbytProofOfownerClint],LenChallangeClient,
												&Data[Indx1ndbytChallngClint],LenAddParam,
												&Data[Indx1stbytAdditnlParam]);
										
	/* Return the response */
	return RespStat;
	
}

/*******************************************************************************
** Function                 : ISOUDS_AuthenticationConfig_Cbk
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: Data Pointer: Pointer to data buffer
**
** Return value             : Status : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/

uint8_t ISOUDS_AuthenticationConfig_Cbk(uint8_t *Data)
{
	/* Response State */
	uint8_t RespStat;

	(void)Data;
	/* Call HAL CallBack Fucntion */
	RespStat = HAL_AuthenticationConfig_Cbk();
	/* Return the response */
	return RespStat;
	
}


/*******************************************************************************
** Function                 : ISOUDS_RespDeauthenticate_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
void ISOUDS_RespDeauthenticate_API(uint8_t *dataBuff, uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	
	/* Call HAL Layer API */
	RespStat = HAL_RespDeauthenticate_API(dataBuff);
	*RespLen = NO_1;
	/* Check the response Value */
	if(ISOUDS_POSRES == RespStat)
	{
		/* Save the return vlaue */
		dataBuff[NO_0] = DEAUTHENTICATIONCOMPLETE;
	}
	else
	{
		/* Save the return vlaue */
		dataBuff[NO_0] = ISOUDS_DEAUTHENFAILED;
	}

}

/*******************************************************************************
** Function                 : ISOUDS_RespVeriCertiUniDir_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
void ISOUDS_RespVeriCertiUniDir_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of Challenge server */
	uint16_t LenChallServer;
	/* length of Ephemeral public key Server */
	uint16_t LenEphPubKeyServer;

	/* Index of 1st byte of Length of Ephemeral Public Key  */
	uint16_t Indx1stbyteLenEphemerlPubKey;
	/* Index of 2nd byte of Length of Ephemeral Public Key  */
	uint16_t Indx2ndbyteLenEphemerlPubKey;

	/* Index of 1st byte of Ephemeral Public Key  */
	uint16_t Indx1stbytEphemralPubKey;

	/* Length of Challenge server */
	LenChallServer = LENCHALLSERVER;
	/* length of Ephemeral public key Server */
	LenEphPubKeyServer = LENEPHMPUBKEYSERVER;

	Indx1stbyteLenEphemerlPubKey = (NO_2 + LenChallServer + NO_1);
	Indx2ndbyteLenEphemerlPubKey = (NO_2 + LenChallServer + NO_2);
	/* Index of 1st byte of Ephemeral Public Key  */
	Indx1stbytEphemralPubKey = (NO_4 + LenChallServer +NO_1 );


		/* Call HAL Layer API */
		RespStat = HAL_SendChallServerUiniDir_API(LenChallServer,&dataBuff[NO_3],
										LenEphPubKeyServer,&dataBuff[Indx1stbytEphemralPubKey]);
		/* Check the response Value */
		if(ISOUDS_POSRES == RespStat)
		{

			/* Save the return Value */
			dataBuff[NO_0] = CERTIVERIFIEDOWNERSHIPVERIFICTNNECESARY;
			/* Save the MSB of Length of Challenge server */
			dataBuff[NO_1] = ((LenChallServer & 0xFF00)>> NO_8 );
			/* Save the LSB of Length of Challenge server */
			dataBuff[NO_2] = (LenChallServer & 0xFF);

			/* Save the MSB of Length of Ephemeral Public Key server */
			dataBuff[(Indx1stbyteLenEphemerlPubKey)] = ((LenEphPubKeyServer & 0xFF00)>> NO_8 );
			/* Save the LSB of Length of Ephemeral Public Key server */
			dataBuff[(Indx2ndbyteLenEphemerlPubKey)] = (LenEphPubKeyServer & 0xFF);

			*RespLen = (Indx1stbytEphemralPubKey + LenEphPubKeyServer);
		}
		else
		{
			/* Do Nothing */
		}
}

void ISOUDS_RespVeriCertiBiDir_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of Challenge server */
	uint16_t LenChallServer;
	/* length of certificate Server */
	uint16_t LenCertiServer;
	/* Length of Proof of Ownership */
	uint16_t LenProoFofOwner;
	/* length of Ephemeral public key Server */
	uint16_t LenEphPubKeyServer;

	/* Index of 1st byte of Length of Certificate Server */
	uint16_t Indx1stbyteLenCertiServer;
	/* Index of 2nd byte of Length of Certificate Server  */
	uint16_t Indx2ndbyteLenCertiServer;

	/* Index of 1st byte of Length of Proof of Ownership */
	uint16_t Indx1stbyteLenProofOfOwner;
	/* Index of 2nd byte of Length of Proof of Ownership */
	uint16_t Indx2ndbyteLenProofOfOwner;

	/* Index of 1st byte of Length of Ephemeral Public Key  */
	uint16_t Indx1stbyteLenEphemerlPubKey;
	/* Index of 2nd byte of Length of Ephemeral Public Key  */
	uint16_t Indx2ndbyteLenEphemerlPubKey;

	/* Index of 1st byte of Certificate Server  */
	uint16_t Indx1stbytCertiServer;
	/* Index of 1st byte of Proof Of Ownership  */
	uint16_t Indx1stbytProofOfOwner;
	/* Index of 1st byte of Ephemeral Public Key  */
	uint16_t Indx1stbytEphemralPubKey;

	/* Length of Challenge server */
	LenChallServer = LENCHALLSERVER;
	/* length of certificate Server */
	LenCertiServer = LENCERTIFICTESERVER;
	/* Length of Proof of Ownership */
	 LenProoFofOwner = LENPROOFOFOWNERSHIP;
	/* length of Ephemeral public key Server */
	LenEphPubKeyServer = LENEPHMPUBKEYSERVER;

	Indx1stbyteLenCertiServer = (NO_2 + LenChallServer + NO_1);
	Indx2ndbyteLenCertiServer = (NO_2 + LenChallServer + NO_2);

	Indx1stbytCertiServer = (Indx2ndbyteLenCertiServer + NO_1 );
	Indx1stbyteLenProofOfOwner = (NO_4 + LenChallServer + LenCertiServer + NO_1);
	Indx2ndbyteLenProofOfOwner = (NO_4 + LenChallServer + LenCertiServer + NO_2);

	Indx1stbytProofOfOwner = (Indx2ndbyteLenProofOfOwner + NO_1 );
	Indx1stbyteLenEphemerlPubKey = (NO_6 + LenChallServer + LenCertiServer + LenProoFofOwner + NO_1);
	Indx2ndbyteLenEphemerlPubKey = (NO_6 + LenChallServer + LenCertiServer + LenProoFofOwner + NO_2);
	/* Index of 1st byte of Ephemeral Public Key  */
	Indx1stbytEphemralPubKey = (Indx2ndbyteLenEphemerlPubKey + NO_1 );



	/* Call HAL LAyer API */
	RespStat = HAL_SendChallServerBiDir_API(LenChallServer,&dataBuff[NO_3],LenCertiServer,
											&dataBuff[Indx1stbytCertiServer],LenProoFofOwner,
											&dataBuff[Indx1stbytProofOfOwner],LenEphPubKeyServer,
											&dataBuff[Indx1stbytEphemralPubKey]);

	/* Check the response */
	if(ISOUDS_POSRES == RespStat)
	{

		/* Save the return Vlaue */
		dataBuff[NO_0] = CERTIVERIFIEDOWNERSHIPVERIFICTNNECESARY;
		/* Save the MSB of Length of Challange server */
		dataBuff[NO_1] = ((LenChallServer & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Challange server */
		dataBuff[NO_2] = (LenChallServer & 0xFF);

		/* Save the MSB of Length of Certificate server */
		dataBuff[Indx1stbyteLenCertiServer] = ((LenCertiServer & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Certificate server */
		dataBuff[Indx2ndbyteLenCertiServer] = (LenCertiServer & 0xFF);

		/* Save the MSB of Length of proof of Ownership */
		dataBuff[Indx1stbyteLenProofOfOwner] = ((LenProoFofOwner & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of proof of Ownership */
		dataBuff[Indx2ndbyteLenProofOfOwner] = (LenProoFofOwner & 0xFF);
		/* Save the proof Of Ownership */

		/* Save the MSB of Length of Eph Public Key Server */
		dataBuff[Indx1stbyteLenEphemerlPubKey] = ((LenEphPubKeyServer & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Eph Public Key Server */
		dataBuff[Indx2ndbyteLenEphemerlPubKey] = (LenEphPubKeyServer & 0xFF);
		/* Save the Eph Public Key Server */


		/* Response Length */
		*RespLen = (Indx1stbytEphemralPubKey + LenEphPubKeyServer) ;
	}
	else
	{
		/* Do Nothing */
	}
		
}



/*******************************************************************************
** Function                 : ISOUDS_SendRespwithSessKey_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
void ISOUDS_SendRespwithSessKey_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of Session Key Info */
	uint16_t LenofSessKeyInfo;

	/* Length of Session Key Info */
	LenofSessKeyInfo = LENSESSIONKEYINFO;

	
	/* Call the HAL Layer API */
	RespStat = HAL_SendRespwithSessKey_API(LenofSessKeyInfo,&dataBuff[NO_3]);
	/* Check the response */
	if(ISOUDS_POSRES == RespStat)
	{

		/* Save the return Value */
		dataBuff[NO_0] = OWNERVERIFIEDAUTHETICNCOMPLET;
		/* Save the MSB of Length of Session key */
		dataBuff[NO_1] = ((LenofSessKeyInfo & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Session key */
		dataBuff[NO_2] = (LenofSessKeyInfo & 0xFF);
		
		*RespLen = (NO_3 + LenofSessKeyInfo);
	}
	
	else
	{
		/* Do Nothing */
		
	}
	
}

/*******************************************************************************
** Function                 : ISOUDS_RespTransCerti_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
uint8_t ISOUDS_RespTransCerti_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	
	/* Call HAL Layer API */
	RespStat = HAL_RespTransCerti_API(dataBuff);
	*RespLen = NO_1;
	/* Save the return Value */
	dataBuff[NO_0] = CERTIFICATEVERIFIED;
	
	return RespStat;
}

/*******************************************************************************
** Function                 : ISOUDS_SndChaServerwithAlgoInd_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
void ISOUDS_SndChaServerwithAlgoInd_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* length of Challenge Server */
	uint16_t LenChallServer;
	/* Length of additional Parameter */
	uint16_t LenofNeededAddParam;
	/* Index of 1st bytes of Length of Challenge server */
	uint16_t Indx1stbytLenChallngeServer;
	/* Index of 2nd bytes of Length of Challenge server */
	uint16_t Indx2ndbytLenChallngeServer;
	/* Index of 1st bytes of Length of Additional Parameter */
	uint16_t Indx1stbytLenAdditionalParam;
	/* Index of 2nd bytes of Length of Additional Parameter  */
	uint16_t Indx2ndbytLenAdditionalParam;
	/* Index of 1st bytes of Challenge Server  */
	uint16_t Indx1stbytChallengeServer;
	/* Index of 1st bytes of Additional Parameter  */
	uint16_t Indx1stbytAdditionalParam;

	/* length of Challenge Server */
	LenChallServer = LENCHALLSERVER;
	/* Length of additional Parameter */
	LenofNeededAddParam = LENNEEDEDADDPARAM;

	Indx1stbytLenChallngeServer = (LENALGOINDICTR +NO_1) ;
	Indx2ndbytLenChallngeServer = (LENALGOINDICTR + NO_2);

	Indx1stbytChallengeServer = (Indx2ndbytLenChallngeServer + NO_1);

	Indx1stbytLenAdditionalParam = (LENALGOINDICTR + NO_2 + LenChallServer + NO_1);
	Indx2ndbytLenAdditionalParam = (LENALGOINDICTR + NO_2 + LenChallServer + NO_2);

	Indx1stbytAdditionalParam = (Indx2ndbytLenAdditionalParam +NO_1 );

	/* Call the HAL Layer API */
	RespStat = HAL_SndChaServerwithAlgoInd_API(LENALGOINDICTR,&dataBuff[NO_1],LenChallServer,
											&dataBuff[Indx1stbytChallengeServer],
									LenofNeededAddParam,&dataBuff[Indx1stbytAdditionalParam]);
	
	/* Check the response */
	if(ISOUDS_POSRES == RespStat)
	{

		/* Save the return Value */
		dataBuff[NO_0] = REQUESTACCEPTED;

		/* Save the MSB of Length of Challenge Server */
		dataBuff[ Indx1stbytLenChallngeServer] = ((LenChallServer & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Challenge Server */
		dataBuff[ Indx2ndbytLenChallngeServer] = (LenChallServer & 0xFF);

		/* Save the MSB of Length of Additional Parameter */
		dataBuff[ Indx1stbytLenAdditionalParam] = ((LenofNeededAddParam & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Additional Parameter */
		dataBuff[ Indx2ndbytLenAdditionalParam] = (LenofNeededAddParam & 0xFF);
		/* Save the Additional parameter */


		*RespLen = (Indx1stbytAdditionalParam + LenofNeededAddParam);
	}
	else
	{
		/* Do Nothing*/
	}
	
}


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
void ISOUDS_SendProofofOwnerUniDir_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of Session Key Info */
	uint16_t LenSessKeyInfo;
	/* Index of 1st byte of Length of Session Key Info */
	uint16_t Indx1stbytLenSessionKeyInfo;
	/* Index of 2nd byte of Length Session Key Info */
	uint16_t Indx2stbytLenSessionKeyInfo;
	/* Index of 1st byte of Session Key Info */
	uint16_t Indx1stbytSessionKeyInfo;

	/* Length of Session Key Info */
	LenSessKeyInfo = LENSESSIONKEYINFO;

	Indx1stbytLenSessionKeyInfo = (LENALGOINDICTR + NO_1);

	Indx2stbytLenSessionKeyInfo = (LENALGOINDICTR + NO_2);

	Indx1stbytSessionKeyInfo = (LENALGOINDICTR + NO_3);

	/* call the HAL Layer API */
	RespStat = HAL_SndProofOwnerUniDir_API(LENALGOINDICTR,&dataBuff[NO_1],LenSessKeyInfo,
										&dataBuff[Indx1stbytSessionKeyInfo]);
	/* Check the response */
	if(ISOUDS_POSRES == RespStat)
	{

		/* Save the return Value */
		dataBuff[NO_0] = OWNERVERIFIEDAUTHETICNCOMPLET;

		/* Save the MSB of Length of Session key */
		dataBuff[Indx1stbytLenSessionKeyInfo] = ((LenSessKeyInfo & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Session key */
		dataBuff[ Indx2stbytLenSessionKeyInfo] = (LenSessKeyInfo & 0xFF);


		*RespLen = (Indx1stbytSessionKeyInfo +LenSessKeyInfo) ;
	}
	else
	{
		/* Do nothing */
	}
		
}
/*******************************************************************************
** Function                 : ISOUDS_SendProofofOwnerBiDir_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function
**
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
void ISOUDS_SendProofofOwnerBiDir_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	/* Length of Proof of Ownership */
	uint16_t LenProoFofOwner;
	/* Length of Session Key Info */
	uint16_t LenSessKeyInfo;
	/* Index of 1st byte of Length of Proof of Ownership Server */
	uint16_t Indx1stbytLenProofOwnerServer;
	/* Index of 2nd byte of Length Proof of Ownership Server */
	uint16_t Indx2stbytLenProofOwnerServer;
	/* Index of 1st byte of Proof of Ownership Server */
	uint16_t Indx1stbytProofOwnerServer;
	/* Index of 1st byte of Length of Session Key Info */
	uint16_t Indx1stbytLenSessionKeyInfo;
	/* Index of 2nd byte of Length Session Key Info */
	uint16_t Indx2stbytLenSessionKeyInfo;
	/* Index of 1st byte of Session Key Info */
	uint16_t Indx1stbytSessionKeyInfo;

	/* Length of Proof of Ownership */
	LenProoFofOwner = LENPROOFOFOWNERSHIP;

	/* Length of Session Key Info */
	LenSessKeyInfo = LENSESSIONKEYINFO;
	Indx1stbytLenProofOwnerServer = (LENALGOINDICTR + NO_1);
	Indx2stbytLenProofOwnerServer = (LENALGOINDICTR + NO_2);
	Indx1stbytProofOwnerServer = (Indx2stbytLenProofOwnerServer + NO_1 );

	Indx1stbytLenSessionKeyInfo = (LENALGOINDICTR + NO_2 + LenProoFofOwner + NO_1);
	Indx2stbytLenSessionKeyInfo = (LENALGOINDICTR + NO_2 + LenProoFofOwner + NO_2);

	Indx1stbytSessionKeyInfo = (Indx2stbytLenSessionKeyInfo + NO_1);
	/* Call HAL Layer API */
	RespStat = HAL_SndProofOwnerBiDir_API(LENALGOINDICTR,&dataBuff[NO_1],LenProoFofOwner,
										&dataBuff[Indx1stbytProofOwnerServer],
										LenSessKeyInfo,&dataBuff[Indx1stbytSessionKeyInfo]);

	/* Chaeck the resposne */
	if(ISOUDS_POSRES == RespStat)
	{

		/* Save the return Value */
		dataBuff[NO_0] = OWNERVERIFIEDAUTHETICNCOMPLET;

		/* Save the MSB of Length of Proof of Ownership */
		dataBuff[Indx1stbytLenProofOwnerServer] = ((LenProoFofOwner & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Proof of Ownership */
		dataBuff[Indx2stbytLenProofOwnerServer] = (LenProoFofOwner & 0xFF);

		/* Save the MSB of Length of Session key Info */
		dataBuff[Indx1stbytLenSessionKeyInfo] = ((LenSessKeyInfo & 0xFF00)>> NO_8 );
		/* Save the LSB of Length of Session key Info */
		dataBuff[Indx2stbytLenSessionKeyInfo] = (LenSessKeyInfo & 0xFF);

		*RespLen = (Indx1stbytSessionKeyInfo + LenSessKeyInfo);
	}
	else
	{
		/* Do Nothing */
	}

}

/*******************************************************************************
** Function                 : ISOUDS_RespAuthenConfig_API
**
** Description              : Authentication Configuration
**
** Parameters 				: SubFun : Sub Function 
**            				
**							: dataBuff: data buffer
**
** Return value             : None
*******************************************************************************/
uint8_t ISOUDS_RespAuthenConfig_API(uint8_t dataBuff[], uint32_t *RespLen)
{
	/* Response State */
	uint8_t RespStat;
	
	/* Call HAL Layer API */
	RespStat = HAL_RespAuthenConfig_API(&dataBuff[0],RespLen);

#if (ISOUDS_AUTHECONCEPT == AUTHE_PKICERTI)
{
	/* Save the return Value */
	dataBuff[NO_0] = AUTHENCONFIG_ACAPCE;
}
#else
{
	#if(AUTHECONFIC_ACR_ASYMTRIC == AUTHENTCATN_ACR)
	/* Save the return Value */
		dataBuff[NO_0] = AUTHETCONFIG_ACACRAC;
	#else
	/* Save the return Value */
		dataBuff[NO_0] = AUTHETCONFIG_ACACRSC;
	#endif
}
#endif
	
	return RespStat;
}

#endif

