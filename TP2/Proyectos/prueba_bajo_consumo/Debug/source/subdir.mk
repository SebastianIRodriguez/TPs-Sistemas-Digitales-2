################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/SD2_board.c \
../source/ejemplo_clock.c \
../source/key.c \
../source/mtb.c \
../source/power_mode_switch.c \
../source/semihost_hardfault.c 

OBJS += \
./source/SD2_board.o \
./source/ejemplo_clock.o \
./source/key.o \
./source/mtb.o \
./source/power_mode_switch.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/SD2_board.d \
./source/ejemplo_clock.d \
./source/key.d \
./source/mtb.d \
./source/power_mode_switch.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\board" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\source" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\drivers" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\component\uart" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\component\serial_manager" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\utilities" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\component\lists" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\device" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\prueba_bajo_consumo\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


