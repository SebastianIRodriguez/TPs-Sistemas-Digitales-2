################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/SD2_I2C.c \
../source/SD2_board.c \
../source/TP2.c \
../source/coyote.c \
../source/display_utils.c \
../source/font5x7.c \
../source/key.c \
../source/mef.c \
../source/mma8451.c \
../source/mtb.c \
../source/oled.c \
../source/power_mode_switch.c \
../source/semihost_hardfault.c 

OBJS += \
./source/SD2_I2C.o \
./source/SD2_board.o \
./source/TP2.o \
./source/coyote.o \
./source/display_utils.o \
./source/font5x7.o \
./source/key.o \
./source/mef.o \
./source/mma8451.o \
./source/mtb.o \
./source/oled.o \
./source/power_mode_switch.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/SD2_I2C.d \
./source/SD2_board.d \
./source/TP2.d \
./source/coyote.d \
./source/display_utils.d \
./source/font5x7.d \
./source/key.d \
./source/mef.d \
./source/mma8451.d \
./source/mtb.d \
./source/oled.d \
./source/power_mode_switch.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\board" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\source" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\drivers" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\component\uart" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\component\serial_manager" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\utilities" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\component\lists" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\device" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\TP2_SD2_Raffagnini_Rodriguez\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


