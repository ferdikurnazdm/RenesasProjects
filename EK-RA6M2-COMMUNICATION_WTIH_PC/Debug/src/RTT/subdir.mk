################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/RTT/SEGGER_RTT_ASM_ARMv7M.S 

C_SRCS += \
../src/RTT/SEGGER_RTT.c \
../src/RTT/SEGGER_RTT_printf.c 

C_DEPS += \
./src/RTT/SEGGER_RTT.d \
./src/RTT/SEGGER_RTT_printf.d 

OBJS += \
./src/RTT/SEGGER_RTT.o \
./src/RTT/SEGGER_RTT_ASM_ARMv7M.o \
./src/RTT/SEGGER_RTT_printf.o 

SREC += \
COMMUNICATION_WITH_PC.srec 

S_UPPER_DEPS += \
./src/RTT/SEGGER_RTT_ASM_ARMv7M.d 

MAP += \
COMMUNICATION_WITH_PC.map 


# Each subdirectory must supply rules for building sources it contributes
src/RTT/%.o: ../src/RTT/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/src" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc/api" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc/instances" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_gen" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_cfg/fsp_cfg/bsp" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"
src/RTT/%.o: ../src/RTT/%.S
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -x assembler-with-cpp -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/src" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc/api" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/fsp/inc/instances" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_gen" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_cfg/fsp_cfg/bsp" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/COMMUNICATION_WITH_PC/ra_cfg/fsp_cfg" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

