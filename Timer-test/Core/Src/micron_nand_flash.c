/*
Micron flash
 Author:  Shekhar
 Company: Pupilmesh pvt ltd
 Ver. 1.0
*/

#include "micron_nand_flash.h"

extern UART_HandleTypeDef huart7;	// change with UART handle in use for debug_nand
extern SPI_HandleTypeDef hspi2;	// change with SPI handle in use
#define NAND_Flash_spi  hspi2			// change with SPI handle in use
#define debug_uart  huart7			// change with UART handle in use for debug_nand
// all buffs and temp declarations
char debug_nand[1600] = {0};
uint8_t buff;
uint8_t cmd[4];
uint8_t temp[2]={0};
// low level functions

void clear_buffs_nand_nand(){
	 memset(debug_nand,0,sizeof(debug_nand));
	 buff = 0;
	 memset(cmd,0,sizeof(cmd));
}

void csLow(void){

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); // PB12 is connected to CS pin on flash (change according to schematics)
}

void csHigh(void){

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);  // PB12 is connected to CS pin on flash (change according to schematics)
}

uint16_t micron_nand_flash_ReadID(void){
	clear_buffs_nand_nand();
	cmd[0]=SPI_NAND_READ_ID ;
	cmd[1]= 0x00;
	if (Nand_Flash_DEBUG  ==  1){
			sprintf(debug_nand,"The device cmd is : 0x%.4x \r\n",((cmd[0]<< 8 )& 0xFF00));
			HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			HAL_Delay(100);
							}
	csLow();
	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 2, 500);
	HAL_SPI_Receive(&NAND_Flash_spi,temp, 2 ,500);
	csHigh();
	uint16_t id_is = ((temp[0]<<8)|(temp[1]));
	clear_buffs_nand();

	if (Nand_Flash_DEBUG  ==  1){
		sprintf(debug_nand,"The device ID is : 0x%.4x \r\n",id_is);
		HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
		clear_buffs_nand();
		HAL_Delay(100);
						}
	return id_is;

}

void micron_nand_flash_Init(void){
	uint16_t ID;
	HAL_Delay(2); // duration for chip to power on
	micron_nand_flash_reset();
	ID = micron_nand_flash_ReadID();
	if (Nand_Flash_DEBUG  ==  1){
			if(ID == ((NAND_ID_MANUFACTURER<<8) | NAND_ID_DEVICE )){
				sprintf(debug_nand,"The device Initialized successfully \r\n");
				HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				clear_buffs_nand();
				HAL_Delay(100);
							}
			else{
					sprintf(debug_nand,"The device Initialized unsuccessful \r\n");
					HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
					clear_buffs_nand();
					HAL_Delay(100);

			}
		}


}

// function to reset flash
void micron_nand_flash_reset(void){
	clear_buffs_nand();
	cmd[0]=SPI_NAND_RESET;
	csLow();
	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 1, 500);
	csHigh();
	clear_buffs_nand();
	HAL_Delay(2);  // duration for reset to complete
	if (Nand_Flash_DEBUG  ==  1){
		sprintf(debug_nand,"Flash reset initialized");
		HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
		clear_buffs_nand();
		HAL_Delay(100);
							}
}
// Enable/disable write functionality 1 for enable, 0 for disable
void micron_nand_flash_write_enable_disable(uint8_t en_dis){
	clear_buffs_nand();

		if (en_dis == 1){
			csLow();
			cmd[0] =  SPI_NAND_WRITE_ENABLE;
			HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 1, 500);
			clear_buffs_nand();
			csHigh();
			HAL_Delay(100);
			if( Nand_Flash_DEBUG  == 1){
				sprintf(debug_nand,"  write is enabled \r\n");
				HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				clear_buffs_nand();
		}

			}

		else if(en_dis==0){
			csLow();
			cmd[0] =  SPI_NAND_WRITE_DISABLE;
			HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 1, 500);
			clear_buffs_nand();
			csHigh();
			HAL_Delay(100);
			if( Nand_Flash_DEBUG  == 1){
				sprintf(debug_nand," write is disabled \r\n");
				HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				clear_buffs_nand();
		}
			}

			else if( Nand_Flash_DEBUG  == 1) {
			sprintf(debug_nand,"Wrong command\r\n");
			HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			clear_buffs_nand();

		}
}

void micron_nand_flash_check_busy(void){
	clear_buffs_nand();
	uint8_t flag = 0;
	uint8_t status_reg=0;
	micron_nand_flash_get_feature(SPI_NAND_STATUS_REG_ADDR, status_reg);
	if (CHECK_OIP(status_reg)){
		 if (Nand_Flash_DEBUG  ==  1){
		 		sprintf(debug_nand,"flash busy \r\n");
		 		HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
		 		clear_buffs_nand();
		 		HAL_Delay(100);
	 }
		 flag =	1;
		}
	else{
		if(Nand_Flash_DEBUG  ==  1){
		sprintf(debug_nand,"flash free \r\n");
		HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
		clear_buffs_nand();
		HAL_Delay(100);
		}
		flag = 0;
	}
	while(flag){
		HAL_Delay(2);
	}
}

//
void micron_nand_flash_until_ready(void){
	clear_buffs_nand();
	uint8_t timeout_counter = 0;
	uint8_t max_attempts = 2;
	uint8_t data_rx;
	 micron_nand_flash_check_busy();
	 while (CHECK_OIP(data_rx)) {
	             if (timeout_counter < max_attempts) {
	            	 HAL_SPI_Receive(&NAND_Flash_spi, &data_rx, 1 ,500);
	            	 HAL_Delay(2);
	                 timeout_counter += 1;
	                 if(Nand_Flash_DEBUG  ==  1){
	                 		sprintf(debug_nand,"flash Ready \r\n");
	                 		HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
	                 		clear_buffs_nand();
	                 		HAL_Delay(100);
	                 		}
	             } else {
	            	 if(Nand_Flash_DEBUG  ==  1){
	            		sprintf(debug_nand,"flash busy \r\n");
						HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
						clear_buffs_nand();
						HAL_Delay(100);
	             }
	         }
	 	 }
}

// function to get feature register value
void micron_nand_flash_get_feature(RegisterAddr reg_addr, uint8_t reg){
	clear_buffs_nand();
	cmd[0]=SPI_NAND_GET_FEATURES;
	cmd[1]=reg_addr;
	csLow();
	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 2, 500);
	HAL_SPI_Receive(&NAND_Flash_spi, &reg, 1 ,500);
	csHigh();
	clear_buffs_nand();
	if(Nand_Flash_DEBUG  ==  1){
			sprintf(debug_nand,"Get feature value is: 0x%.2x ",reg);
			HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			clear_buffs_nand();
			HAL_Delay(100);
			}
}
// function to set feature register value
void micron_nand_flash_set_feature(RegisterAddr reg_addr, uint8_t reg){
	clear_buffs_nand();
		cmd[0]=SPI_NAND_SET_FEATURES;
		cmd[1]=reg_addr;
		cmd[2]=reg;
		csLow();
		micron_nand_flash_write_enable_disable(1);
		HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 3, 500);
		csHigh();
		clear_buffs_nand();
		if(Nand_Flash_DEBUG  ==  1){
				sprintf(debug_nand,"Set feature value is: 0x%.2x ",reg);
				HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				clear_buffs_nand();
				HAL_Delay(100);
				}
}

void micron_nand_flash_block_erase(PhysicalAddrs *addr){

	clear_buffs_nand();
	micron_nand_flash_write_enable_disable(1);
	uint32_t block = addr->block;
	cmd[0] = SPI_NAND_BLOCK_ERASE;
	cmd[1] = ((block & 0xFF0000) >> 16 );
	cmd[2] = ((block & 0xFF00) >> 8);
	cmd[3] = (block & 0xFF);

	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 4, 500);

	micron_nand_flash_until_ready();
	micron_nand_flash_write_enable_disable(0);
	clear_buffs_nand();
	 if(Nand_Flash_DEBUG  ==  1){
			 sprintf(debug_nand,"Erase successful \r\n");
			 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			 clear_buffs_nand();
			 HAL_Delay(100);
	 }

}

void micron_nand_flash_page_program(PhysicalAddrs *addr, uint16_t length,uint8_t data[length-1]){


	clear_buffs_nand();
	if (length > PAGE_DATA_SIZE) {
		 if(Nand_Flash_DEBUG  ==  1){
			 sprintf(debug_nand,"Data overruns the memory space \r\n");
			 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			 clear_buffs_nand();
			 HAL_Delay(100);
		}
	}

	if(Nand_Flash_DEBUG  ==  1){
		 sprintf(debug_nand,"Page  Program initialize \r\n");
		 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
		 clear_buffs_nand();
		 for(int i = 0;i<length;i++){
				 sprintf(debug_nand,"Data written at index %d is : 0x%.2x  \r\n",i,data[i]);
				 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				 clear_buffs_nand();
				 HAL_Delay(100);
			 }
	 }

	micron_nand_flash_write_enable_disable(1);
	uint32_t col = addr->colAddr;
	cmd[0] = SPI_NAND_PROGRAM_LOAD_X1;
	cmd[1] = ((col & 0xFF00 )>> 8);
	cmd[2] = (col & 0xFF);

	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 3, 500);
	HAL_SPI_Transmit(&NAND_Flash_spi, data, length ,5000);
	micron_nand_flash_until_ready();
	clear_buffs_nand();

	uint32_t row = addr->rowAddr;
	cmd[0] = SPI_NAND_PROGRAM_EXEC;
	cmd[1] = ((row & 0xFF0000) >> 16 );
	cmd[2] = ((row & 0xFF00) >> 8);
	cmd[3] = (row & 0xFF);

	HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 4, 500);

	micron_nand_flash_until_ready();
	micron_nand_flash_write_enable_disable(0);
	clear_buffs_nand();

	 if(Nand_Flash_DEBUG  ==  1){
			 sprintf(debug_nand,"Page  program successful \r\n");
			 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
			 clear_buffs_nand();
			 HAL_Delay(100);
	 }
}

void micron_nand_flash_page_read(PhysicalAddrs *addr, uint16_t length,uint8_t buffer[length-1] ){
	clear_buffs_nand();
		if (length > PAGE_DATA_SIZE) {
			 if(Nand_Flash_DEBUG  ==  1){
				 sprintf(debug_nand,"Data overruns the memory space \r\n");
				 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				 clear_buffs_nand();
				 HAL_Delay(100);
			}
		}

		micron_nand_flash_write_enable_disable(1);
		uint32_t row = addr->rowAddr;
		cmd[0] = SPI_NAND_PAGE_READ;
		cmd[1] = ((row & 0xFF0000) >> 16 );
		cmd[2] = ((row & 0xFF00) >> 8);
		cmd[3] = (row & 0xFF);

		HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 4, 500);
		micron_nand_flash_until_ready();
		clear_buffs_nand();

		uint32_t col = addr->colAddr;
		cmd[0] = SPI_NAND_READ_CACHE_X1;
		cmd[1] = ((col & 0xFF0000) >> 8 );
		cmd[2] = ((col & 0xFF00));
		cmd[3] = DUMMY_Byte;

		HAL_SPI_Transmit(&NAND_Flash_spi, cmd, 4, 500);
		HAL_SPI_Receive(&NAND_Flash_spi,buffer, length, 5000);
		micron_nand_flash_write_enable_disable(0);
		clear_buffs_nand();

		 if(Nand_Flash_DEBUG  ==  1){
				 sprintf(debug_nand,"Page  Read successful \r\n");
				 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
				 clear_buffs_nand();
				 for(int i = 0;i<length;i++){
					 sprintf(debug_nand,"Data at index %d is : 0x%.2x  \r\n",i,buffer[i]);
					 HAL_UART_Transmit(&debug_uart,(uint8_t *) debug_nand, strlen(debug_nand), 1000);
					 clear_buffs_nand();
					 HAL_Delay(100);
				 }
		 }

}
