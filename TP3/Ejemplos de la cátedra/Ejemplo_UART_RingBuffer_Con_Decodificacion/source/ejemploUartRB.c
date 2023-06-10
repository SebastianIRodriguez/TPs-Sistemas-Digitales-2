/* Copyright , DSI FCEIA UNR - Sistemas Digitales 2
 *    DSI: http://www.dsi.fceia.unr.edu.ar/
 * Copyright, Diego Alegrechi
 * Copyright, Gustavo Muro
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
#include "SD2_board.h"
#include "fsl_lpuart.h"
#include "fsl_port.h"
#include "board.h"
#include "uart_ringBuffer.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

#define LED_ACTION_MESSAGE '0'
#define SW_STATE_MESSAGE '1'
#define ACCEL_STATE_MESSAGE '2'

#define LED_RED_MESSAGE_ID '1'
#define LED_GREEN_MESSAGE_ID '2'

#define SW1_MESSAGE_ID '1'
#define SW3_MESSAGE_ID '3'

/** 
 *  LED ROJO
 *  :XX01Y’LF’ :XX01Y’LF’   Y = E - A - T
 *  LED VERDE
 *  :XX02Y’LF’ :XX02Y’LF’   Y = E - A - T
 *  XX = '23'
**/
void NUESTROTP_process_led_action_request(uint8_t* buffer, uint8_t received_message_id) {
    //Leer el ultimo byte que falta, ya que estos paquetes tienen 10 bytes en vez de 9
    int read_bytes = uart_ringBuffer_recDatos(buffer, 1, 7);
    
    if (read_bytes < 1) 
        return;
    
    board_ledId_enum requested_led_id = (received_message_id == LED_RED_MESSAGE_ID) ? BOARD_LED_ID_ROJO : BOARD_LED_ID_VERDE;

    char requested_led_action = buffer[5]; //'E', 'A' o 'T'
    switch (requested_led_action) {
        case 'E':
            board_setLed(requested_led_id, BOARD_LED_MSG_ON);
            break;
    
        case 'A':
            board_setLed(requested_led_id, BOARD_LED_MSG_OFF);
            break;

        case 'T':
            board_setLed(requested_led_id, BOARD_LED_MSG_TOGGLE);
            break;

        default:
            break;
    }

    //Envio el mensaje tal cual lo recibi
    uart_ringBuffer_envDatos(buffer, 7);
}

/**
 * :XX11’LF’ :XX11Y’LF’   Y = N - P
 * :XX13’LF’ :XX13Y’LF’   Y = N - P
 * XX = '23'
 */
void NUESTROTP_process_switch_state_request(uint8_t* buffer, uint8_t received_message_id) {
    uint8_t requested_sw_state = 0;

    switch (received_message_id) {
        case SW1_MESSAGE_ID:
            requested_sw_state = board_getSw(BOARD_SW_ID_1);
            break;

        case SW3_MESSAGE_ID:
            requested_sw_state = board_getSw(BOARD_SW_ID_3);
            break;

        default:
            break;
    }

    buffer[5] = (requested_sw_state) ? 'P' : 'N';
    buffer[6] = 0x0A;

    uart_ringBuffer_envDatos(buffer, 7);
}

/**
 * :XX21’LF’ :XX21SXXXSYYYSZZZ’LF’
 * XX = '23'
 */
void NUESTROTP_process_acceleration_request(uint8_t* buffer) {
    //TODO: obtener medicion del acelerometro
    sprintf(buffer, ":2321+123-456+789\n");

    uart_ringBuffer_envDatos(buffer, 18);
}

int main(void)
{
    int32_t ret;
    uint8_t buffer[21];

	BOARD_BootClockRUN();

	// Se inicializan funciones de la placa
	board_init();

	// Se inicializa UART0 con ring buffer
	uart_ringBuffer_init();

    while(1) {
        if (uart_available_bytes_to_read() >= 6) {
            ret = uart_ringBuffer_recDatos(buffer, 6, 0);

            if (ret == 6) {
                uint8_t received_message_type = buffer[3];
                uint8_t received_message_id = buffer[4];

                switch (received_message_type) {
                    case LED_ACTION_MESSAGE:
                        while (uart_available_bytes_to_read() < 1); //Espero a que llegue el byte que me falta
                        NUESTROTP_process_led_action_request(buffer, received_message_id);
                        break;

                    case SW_STATE_MESSAGE:
                        NUESTROTP_process_switch_state_request(buffer, received_message_id);
                        break;

                    case ACCEL_STATE_MESSAGE:
                        NUESTROTP_process_acceleration_request(buffer);
                        break;
                
                    default:
                        break;
                }
            }
        }
    }
}

/*==================[end of file]============================================*/


