################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_WrtMemByAddr/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_WrDaByID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_TrnsfrExit/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_TrnsfrDa/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_StrtDiagSess/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_SA/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RtnCntrl/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RespOnEvent/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ReqUpld/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ReqFileTransfer/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ReqDwnld/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RdScDaByID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RdMemByAddr/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RdDaByPdID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RdDaByID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_RdDTCInf/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_MAIN/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_LinkCntrl/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_IOCtrlByID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ECUReset/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_DyDfDaID/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_CommnCtrl/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_CntrlDTCSetting/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ClearDiagInfo/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_Authentication/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDS_ATParameter/subdir.mk
-include Core/Inc/ISOUDS_Server/ISOUDSSecurDtaTrans/subdir.mk
-include Core/Inc/ISOTP/subdir.mk
-include Core/Inc/FCM/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Timer-test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Timer-test.elf \

MAP_FILES += \
Timer-test.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Timer-test.list \


# All Target
all: main-build

# Main-build Target
main-build: Timer-test.elf secondary-outputs

# Tool invocations
Timer-test.elf Timer-test.map: $(OBJS) $(USER_OBJS) D:\STM-T1\Timer-test\STM32H723VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Timer-test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\STM-T1\Timer-test\STM32H723VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Timer-test.map" -Wl,--gc-sections -static -L"D:\STM-T1\cantest\Core\Inc\ISOUDS_Server" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\FCM" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOTP" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ATParameter" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_Authentication" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ClearDiagInfo" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_CntrlDTCSetting" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_CommnCtrl" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_DyDfDaID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ECUReset" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_IOCtrlByID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_LinkCntrl" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_MAIN" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RdDaByID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RdDaByPdID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RdDTCInf" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RdMemByAddr" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RdScDaByID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ReqDwnld" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ReqFileTransfer" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_ReqUpld" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RespOnEvent" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_RtnCntrl" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_SA" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_StrtDiagSess" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_TrnsfrDa" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_TrnsfrExit" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_TstrPrsnt" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_WrDaByID" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDS_WrtMemByAddr" -L"D:\Manoj - STM Files\ISOTP_UDSStack\Stack\ISOUDS_Server\ISOUDSSecurDtaTrans" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Timer-test.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Timer-test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Timer-test.elf Timer-test.list Timer-test.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
