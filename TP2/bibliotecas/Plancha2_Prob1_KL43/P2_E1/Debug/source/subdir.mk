################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/P2_E1.c \
../source/SD2_I2C.c \
../source/SD2_board.c \
../source/key.c \
../source/mef.c \
../source/mma8451.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/P2_E1.o \
./source/SD2_I2C.o \
./source/SD2_board.o \
./source/key.o \
./source/mef.o \
./source/mma8451.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/P2_E1.d \
./source/SD2_I2C.d \
./source/SD2_board.d \
./source/key.d \
./source/mef.d \
./source/mma8451.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\board" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\source" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\drivers" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\component\uart" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\component\serial_manager" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\utilities" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\component\lists" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\device" -I"C:\Users\guido\Documents\MCUXpressoIDE_11.3.0_5222\workspace\Docencia SD2\P2_E1\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


