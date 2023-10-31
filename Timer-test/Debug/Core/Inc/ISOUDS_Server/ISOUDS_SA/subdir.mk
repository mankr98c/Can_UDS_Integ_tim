################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.c \
../Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.c 

OBJS += \
./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.o \
./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.o 

C_DEPS += \
./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.d \
./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ISOUDS_Server/ISOUDS_SA/%.o Core/Inc/ISOUDS_Server/ISOUDS_SA/%.su Core/Inc/ISOUDS_Server/ISOUDS_SA/%.cyclo: ../Core/Inc/ISOUDS_Server/ISOUDS_SA/%.c Core/Inc/ISOUDS_Server/ISOUDS_SA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/FCM" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOTP" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ATParameter" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_Authentication" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ClearDiagInfo" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_CntrlDTCSetting" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_CommnCtrl" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_DyDfDaID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ECUReset" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_IOCtrlByID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_LinkCntrl" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_MAIN" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RdDaByID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RdDaByPdID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RdDTCInf" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RdMemByAddr" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RdScDaByID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ReqDwnld" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ReqFileTransfer" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_ReqUpld" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RespOnEvent" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_RtnCntrl" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_SA" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_StrtDiagSess" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_TrnsfrDa" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_TrnsfrExit" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_TstrPrsnt" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_WrDaByID" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDS_WrtMemByAddr" -I"D:/Manoj - STM Files/ISOTP_UDSStack/Stack/ISOUDS_Server/ISOUDSSecurDtaTrans" -I"D:/STM-T1/Timer-test/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ISOUDS_Server-2f-ISOUDS_SA

clean-Core-2f-Inc-2f-ISOUDS_Server-2f-ISOUDS_SA:
	-$(RM) ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.cyclo ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.d ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.o ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_Cfg.su ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.cyclo ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.d ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.o ./Core/Inc/ISOUDS_Server/ISOUDS_SA/ISOUDS_SA_HAL.su

.PHONY: clean-Core-2f-Inc-2f-ISOUDS_Server-2f-ISOUDS_SA

