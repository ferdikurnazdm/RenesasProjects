################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_dac/r_dac.c 

C_DEPS += \
./ra/fsp/src/r_dac/r_dac.d 

OBJS += \
./ra/fsp/src/r_dac/r_dac.o 

SREC += \
FLASHWARE_DENEME_004.srec 

MAP += \
FLASHWARE_DENEME_004.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_dac/%.o: ../ra/fsp/src/r_dac/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/src" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra/fsp/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra/fsp/inc/api" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra/fsp/inc/instances" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra_gen" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra_cfg/fsp_cfg/bsp" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_004/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

