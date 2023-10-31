#include <main.h>
#include <stdio.h>
#include "string.h"
#include "C_can.h"
#include "stm32h7xx_hal_fdcan.h"
#include "CanTP.h"


int indx=0;
char buff[100]={0};
extern FDCAN_TxHeaderTypeDef   TxHeader1;
extern FDCAN_RxHeaderTypeDef   RxHeader1;
extern FDCAN_TxHeaderTypeDef TxResponseHeader;
uint8_t TxResponseData[8] ={1,2,3,4,5};
uint8_t               TxData1[8];
uint8_t               RxData1[8];

extern FDCAN_HandleTypeDef hfdcan3;
extern UART_HandleTypeDef huart7;

void can_Tx()
{
	 sprintf(buff,"\r\n CAN tx data started \r\n");
	 HAL_UART_Transmit(&huart7, (uint8_t *) buff, sizeof(buff), 100);
	 memset(buff,0,sizeof(buff));

	 while (1)
	 {
		 sprintf ((char *)TxData1, "N1%d", indx++);
			  if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader1, TxData1)!= HAL_OK)
			  {
			   Error_Handler();
			  }

			  HAL_Delay (1000);
	 }
}

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {

	  sprintf(buff,"\r\n CAN in RX data callback \r\n");
	   	HAL_UART_Transmit(&huart7, (uint8_t *) buff, sizeof(buff), 100);
	    	memset(buff,0,sizeof(buff));
    /* Retreive Rx messages from RX FIFO0 */

    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader1, RxData1) != HAL_OK)
    {
    /* Reception Error */
    Error_Handler();
    }
    ISOTP_RxMsgCbk(0x731,0x00, 0x08,RxData1);
    uint8_t St = ISOTP_GetStatus();
    sprintf(buff,"\r\n ISOTP callbackdata %d \r\n", St);
    	    	memset(buff,0,sizeof(buff));
     // Set up the response message header
     // You can customize this based on your needs
     TxResponseHeader.Identifier = 0x12;  // Set the identifier as needed
     TxResponseHeader.IdType = FDCAN_STANDARD_ID;
     TxResponseHeader.TxFrameType = FDCAN_DATA_FRAME;
     TxResponseHeader.DataLength = FDCAN_DLC_BYTES_8;

      // Send the response
     if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxResponseHeader, TxResponseData) != HAL_OK)
     {
       // Transmission Error
       Error_Handler();
     }
    sprintf(buff,"\r\n CAN in RX data callback x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x  \r\n",RxData1[0],RxData1[1],RxData1[2],RxData1[3],RxData1[4],RxData1[5],RxData1[6],RxData1[7]);
  	   	HAL_UART_Transmit(&huart7, (uint8_t *) buff, sizeof(buff), 100);
  	    	memset(buff,0,sizeof(buff));

    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
    {
      /* Notification Error */
      Error_Handler();
    }
  }
}

