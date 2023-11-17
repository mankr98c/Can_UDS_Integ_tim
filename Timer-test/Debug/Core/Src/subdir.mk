################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/C_Can.c \
../Core/Src/main.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c 

OBJS += \
./Core/Src/C_Can.o \
./Core/Src/main.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o 

C_DEPS += \
./Core/Src/C_Can.d \
./Core/Src/main.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/STM-T1/Timer-test/Core/Inc/ISOTP" -I"D:/STM-T1/Timer-test/Core/Inc/FCM" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ATParameter" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_Authentication" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ClearDiagInfo" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_CntrlDTCSetting" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_CommnCtrl" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_DyDfDaID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ECUReset" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_IOCtrlByID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_LinkCntrl" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_MAIN" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RdDaByID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RdDaByPdID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RdDTCInf" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RdMemByAddr" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RdScDaByID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ReqDwnld" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ReqFileTransfer" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_ReqUpld" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RespOnEvent" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_RtnCntrl" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_SA" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_StrtDiagSess" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_TrnsfrDa" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_TrnsfrExit" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_TstrPrsnt" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_WrDaByID" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDSSecurDtaTrans" -I"D:/STM-T1/Timer-test/Core/Inc/ISOUDS_Server/ISOUDS_WrtMemByAddr" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/C_Can.cyclo ./Core/Src/C_Can.d ./Core/Src/C_Can.o ./Core/Src/C_Can.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su

.PHONY: clean-Core-2f-Src

