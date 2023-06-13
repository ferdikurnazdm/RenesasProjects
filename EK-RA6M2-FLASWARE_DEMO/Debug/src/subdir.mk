################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/calculate.c \
../src/hal_entry.c \
../src/smith_prothocol.c \
../src/timer_code.c \
../src/uart_code.c 

C_DEPS += \
./src/calculate.d \
./src/hal_entry.d \
./src/smith_prothocol.d \
./src/timer_code.d \
./src/uart_code.d 

OBJS += \
./src/calculate.o \
./src/hal_entry.o \
./src/smith_prothocol.o \
./src/timer_code.o \
./src/uart_code.o 

SREC += \
FLASHWARE_DENEME_003.srec 

MAP += \
FLASHWARE_DENEME_003.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/src" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra/fsp/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra/fsp/inc/api" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra/fsp/inc/instances" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra_gen" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra_cfg/fsp_cfg/bsp" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/FLASHWARE_DENEME_003/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

