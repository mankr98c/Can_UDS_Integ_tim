

#ifndef INC_C_CAN_H_
#define INC_C_CAN_H_


//void Initialization();
void can_Tx();
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs);
//void setCallbackFunction(void (*func)(void));


typedef enum {
    STATE_IDLE,
    STATE_CAN_RX,
    STATE_CAN_TX,
} AppState;

extern AppState appState;

#endif /* INC_C_CAN_H_ */
