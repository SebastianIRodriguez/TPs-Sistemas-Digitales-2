################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Prueba_acelerometro_2.c \
../source/SD2_I2C.c \
../source/SD2_board.c \
../source/key.c \
../source/mef.c \
../source/mma8451.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/Prueba_acelerometro_2.o \
./source/SD2_I2C.o \
./source/SD2_board.o \
./source/key.o \
./source/mef.o \
./source/mma8451.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/Prueba_acelerometro_2.d \
./source/SD2_I2C.d \
./source/SD2_board.d \
./source/key.d \
./source/mef.d \
./source/mma8451.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\board" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\source" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\drivers" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\component\uart" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\component\serial_manager" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\utilities" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\component\lists" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\device" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\Prueba_acelerometro_2\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


