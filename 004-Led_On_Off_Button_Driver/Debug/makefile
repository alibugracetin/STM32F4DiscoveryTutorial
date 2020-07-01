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
004\ -\ Led_On_Off_Button_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
004\ -\ Led_On_Off_Button_Driver.list \

OBJCOPY_BIN += \
004\ -\ Led_On_Off_Button_Driver.bin \


# All Target
all: 004\ -\ Led_On_Off_Button_Driver.elf secondary-outputs

# Tool invocations
004\ -\ Led_On_Off_Button_Driver.elf: $(OBJS) $(USER_OBJS) C:\Calismalar\STM32F4Discovery_Tutorial\004\ -\ Led_On_Off_Button_Driver\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "004 - Led_On_Off_Button_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Calismalar\STM32F4Discovery_Tutorial\004 - Led_On_Off_Button_Driver\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="004 - Led_On_Off_Button_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

004\ -\ Led_On_Off_Button_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "004 - Led_On_Off_Button_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

004\ -\ Led_On_Off_Button_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "004 - Led_On_Off_Button_Driver.bin"
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
