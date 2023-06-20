################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ioport/r_ioport.c 

C_DEPS += \
./ra/fsp/src/r_ioport/r_ioport.d 

OBJS += \
./ra/fsp/src/r_ioport/r_ioport.o 

SREC += \
MODBUS_RTU_DENEME.srec 

MAP += \
MODBUS_RTU_DENEME.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ioport/%.o: ../ra/fsp/src/r_ioport/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/src" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc/api" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc/instances" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_gen" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_cfg/fsp_cfg/bsp" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

