################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/SD2_I2C.c \
../source/SD2_board.c \
../source/font5x7.c \
../source/key.c \
../source/main.c \
../source/mef.c \
../source/mma8451.c \
../source/mtb.c \
../source/oled.c \
../source/semihost_hardfault.c 

OBJS += \
./source/SD2_I2C.o \
./source/SD2_board.o \
./source/font5x7.o \
./source/key.o \
./source/main.o \
./source/mef.o \
./source/mma8451.o \
./source/mtb.o \
./source/oled.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/SD2_I2C.d \
./source/SD2_board.d \
./source/font5x7.d \
./source/key.d \
./source/main.d \
./source/mef.d \
./source/mma8451.d \
./source/mtb.d \
./source/oled.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\board" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\source" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\drivers" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\component\uart" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\component\serial_manager" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\utilities" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\component\lists" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\device" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\merge_oled_acelerometro\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


