################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

SREC += \
MODBUS_RTU_DENEME.srec 

MAP += \
MODBUS_RTU_DENEME.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/src" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc/api" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/fsp/inc/instances" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_gen" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_cfg/fsp_cfg/bsp" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/MODBUS_RTU_DENEME/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"
