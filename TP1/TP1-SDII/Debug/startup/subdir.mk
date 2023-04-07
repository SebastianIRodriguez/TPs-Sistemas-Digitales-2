################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mkl43z4.c 

OBJS += \
./startup/startup_mkl43z4.o 

C_DEPS += \
./startup/startup_mkl43z4.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu17 -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\board" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\source" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\drivers" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\component\uart" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\component\serial_manager" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\utilities" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\component\lists" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\device" -I"C:\Users\lraff\Documents\MCUXpressoIDE_11.5.1_7266\workspace\clase_5_4\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


