/* Copyright 2022, DSI FCEIA UNR - Sistemas Digitales 2
 *    DSI: http://www.dsi.fceia.unr.edu.ar/
  * Copyright 2017-2019, Gustavo Muro - Daniel Márquez
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*==================[inclusions]=============================================*/

// Standard C Included Files
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Project Included Files
#include "SD2_board.h"
#include "fsl_lpuart.h"
#include "fsl_port.h"
#include "board.h"
#include "MKL43Z4.h"
#include "pin_mux.h"
#include "uart0_drv.h"
#include "rs485_drv.h"
#include "mma8451.h"
#include "SD2_I2C.h"


#define _RETARDO_MSEG 100

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

long cuenta = 2000;
int total = 0;

int main(void)
{
    uint8_t buffer0_rx[32]; // Buffer de recepción del UART0
    uint8_t buffer0_tx[32]; // Buffer de transmisión del UART0
    uint8_t buffer0_analisis[32];
    //uint8_t buffer_1[32]; // Buffer del UART1
    int16_t acc; // Variable de lectura de un eje del acelerometro

	BOARD_BootClockRUN();

	// Se inicializan funciones de la placa
	board_init();

	SD2_I2C_init();
	mma8451_init();
	mma8451_setDataRate(DR_12p5hz);

	//Inicializa driver de UART0
	uart0_drv_init();

	//Inicializa driver de UART1
	rs485_drv_init();

	//inicializa interrupción de systick cada 1 ms
	SysTick_Config(SystemCoreClock / 1000U);

	//Lazo infinito
	while(1)
	{

		//Desde aquí se genera un retardo de X mSeg con el Systick Timer
		//cuenta = _RETARDO_MSEG;
		//while(cuenta!=0);

		//Lee valor de aceleración del eje X
	    acc = mma8451_getAcX();

        uint8_t ret = rs485_drv_recDatos(buffer0_rx, sizeof(buffer0_rx));

        buffer0_rx[ret] = 0;

        for(int i = 0; i < ret; i++, total ++)
        	buffer0_analisis[total] = buffer0_rx[i];

        if (total > 10)
        {
        	buffer0_analisis[total] = 0;
        	sprintf((char*)buffer0_tx, "- %s EJE X:%d \r\n", buffer0_analisis, acc);
        	rs485_drv_envDatos(buffer0_tx, strlen((char*)buffer0_tx));
        	total = 0;
        }


        if(kLPUART_RxOverrunFlag & LPUART_GetStatusFlags(LPUART0))
        	board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_ON);


	    //Desde aquí se genera un retardo de X mSeg con el Systick Timer
	    //cuenta = _RETARDO_MSEG;
	    //while(cuenta!=0);

	}
}


void SysTick_Handler(void)
{
	cuenta--;

   if(cuenta <= 0)
   {
	   cuenta = 2000;
	   char mensaje[] = "Probando UART0!\n";
	   uart0_drv_envDatos((uint8_t *)mensaje, strlen(mensaje));
   }
}


/*==================[end of file]============================================*/


