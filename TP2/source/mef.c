/* Copyright 2017, DSI FCEIA UNR - Sistemas Digitales 2
 *    DSI: http://www.dsi.fceia.unr.edu.ar/
 * Copyright 2017, Diego Alegrechi
 * Copyright 2017, Gustavo Muro
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
#include "mef.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    HACIENDO_NONI = 0,
    CAIDA_LIBRE,
    POST_IMPACTO
} Estado_mef;

/*==================[internal data declaration]==============================*/
static unsigned int tim_mef;
static unsigned int tim_led;
static float maximo;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
static Estado_mef estado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void mef_init(void)
{
    tim_led = 0;
    tim_mef = 0;
    maximo = 0;
    board_setLed(ROJO, OFF);
    estado = HACIENDO_NONI;
}

int mef_run(void)
{
    switch (estado)
    {

    case HACIENDO_NONI:
    {
        // verificar como ponerlo en bajo consumo
        board_setLed(ROJO, OFF);

        if ("DETECTAMOS CAIDA LIBRE")
        {
            estado = CAIDA_LIBRE;
        }
    }
    break;

    case CAIDA_LIBRE:
    {
        float nuevo_valor = x * x + y * y + z * z;
        if (maximo < nuevo_valor)
            maximo = nuevo_valor;

        if (maximo > (9.5 * 9.5)) // verificar como resolver si no hay medidas nuevas
            medida_quieto++;

        if (medida_quieto > 2)
        {
            tim_mef = 10000;
            key_getPressEv(BOARD_SW_ID_1); // Tomo cualquier posible evento
            estado = POST_IMPACTO;
        }

        if (tim_led <= 0)
        {
            tim_led = 500;
            board_setLed(ROJO, TOGGLE);
        }
    }
    break;

    case POST_IMPACTO:
    {
        // MOSTRAR MEDIDA EN OLED
        board_setLed(ROJO, ON);

        if (key_getPressEv(BOARD_SW_ID_1) || tim_mef <= 0)
        {
            estado = HACIENDO_NONI;
        }
    }
    break;

    default:
        break;
    }

    return 0;
}

void mef_periodicTask1ms(void)
{

    key_periodicTask1ms();

    if (tim_led)
        tim_led--;

    if (tim_mef)
        tim_mef--;
}

/*==================[end of file]============================================*/
