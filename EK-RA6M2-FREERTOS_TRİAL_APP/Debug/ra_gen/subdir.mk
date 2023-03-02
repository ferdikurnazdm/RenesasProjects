################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/BLUERED_thread.c \
../ra_gen/REDLED_thread.c \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/BLUERED_thread.d \
./ra_gen/REDLED_thread.d \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/BLUERED_thread.o \
./ra_gen/REDLED_thread.o \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

SREC += \
FREERTOS_DENEME_000.srec 

MAP += \
FREERTOS_DENEME_000.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/src" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/fsp/inc" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/fsp/inc/api" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/fsp/inc/instances" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/fsp/src/rm_freertos_port" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra_gen" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra_cfg/fsp_cfg/bsp" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra_cfg/fsp_cfg" -I"C:/Users/ferdi.kurnaz/e2_studio/workspace/FREERTOS_DENEME_000/ra_cfg/aws" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

