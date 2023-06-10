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
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\board" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\source" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\drivers" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\component\uart" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\component\serial_manager" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\utilities" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\component\lists" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\device" -I"D:\FCEIA\Sistemas Digitales II\TPs-Sistemas-Digitales-2\TP3\Ejemplos de la cátedra\Ejemplo_UART_RingBuffer_Con_Decodificacion\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


