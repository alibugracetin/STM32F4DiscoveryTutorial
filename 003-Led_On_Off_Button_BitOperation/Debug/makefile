################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
003-Led_On_Off_Button_BitOperation.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
003-Led_On_Off_Button_BitOperation.list \

OBJCOPY_BIN += \
003-Led_On_Off_Button_BitOperation.bin \


# All Target
all: 003-Led_On_Off_Button_BitOperation.elf secondary-outputs

# Tool invocations
003-Led_On_Off_Button_BitOperation.elf: $(OBJS) $(USER_OBJS) C:\Calismalar\STM32F4Discovery_Tutorial\003-Led_On_Off_Button_BitOperation\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "003-Led_On_Off_Button_BitOperation.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Calismalar\STM32F4Discovery_Tutorial\003-Led_On_Off_Button_BitOperation\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="003-Led_On_Off_Button_BitOperation.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

003-Led_On_Off_Button_BitOperation.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "003-Led_On_Off_Button_BitOperation.list"
	@echo 'Finished building: $@'
	@echo ' '

003-Led_On_Off_Button_BitOperation.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "003-Led_On_Off_Button_BitOperation.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
