################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/board/ra6m2_ek/board_init.c \
../ra/board/ra6m2_ek/board_leds.c 

C_DEPS += \
./ra/board/ra6m2_ek/board_init.d \
./ra/board/ra6m2_ek/board_leds.d 

OBJS += \
./ra/board/ra6m2_ek/board_init.o \
./ra/board/ra6m2_ek/board_leds.o 

SREC += \
quickstart_ek_ra6m2_ep.srec 

MAP += \
quickstart_ek_ra6m2_ep.map 


# Each subdirectory must supply rules for building sources it contributes
ra/board/ra6m2_ek/%.o: ../ra/board/ra6m2_ek/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra/fsp/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra/fsp/inc/api" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra/fsp/inc/instances" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra_gen" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra_cfg/fsp_cfg" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra_cfg/fsp_cfg/bsp" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/ra/fsp/src/r_usb_basic/src/driver/inc" -I"D:/Users/ferdi.kurnaz/e2_studio/workspace/_quickstart/quickstart_ek_ra6m2_ep/e2studio/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

