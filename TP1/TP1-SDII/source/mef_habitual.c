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
#include "mef_habitual.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    RUTA_HABILITADA = 0,
    RUTA_CORTANDO,
    SECUNDARIO_HABILITADO,
    SECUNDARIO_CORTANDO,
}
estado_mefHabitual;

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
//Temporizaciones en [ms]
static const unsigned int TIEMPO_RUTA_HABILITADA = 20000; //120000
static const unsigned int TIEMPO_RUTA_CORTANDO = 5000;
static const unsigned int TIEMPO_SECUNDARIO_HABILITADO = 10000;
static const unsigned int TIEMPO_SECUNDARIO_CORTANDO = 5000;
static const unsigned int PERIODO_LVR = 200;
static const unsigned int PERIODO_LVS = 200;

static unsigned int tim_mefHabitual;
static unsigned int contador_titilar;
static estado_mefHabitual estado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void mefHabitual_init(void)
{
    contador_titilar = 0;
    tim_mefHabitual = TIEMPO_RUTA_HABILITADA;
    estado = RUTA_HABILITADA;
    reset_autos_en_espera();
}

bool mefHabitual_run(void)
{
    // Devuelve verdadero si la ruta está habilitada, falso en cualquier otro caso
    switch (estado)
    {

    case RUTA_HABILITADA:
        board_setLed(LVR, ON);
        board_setLed(LRS, ON);
        board_setLed(LRR, OFF);
        board_setLed(LVS, OFF);

        if (tim_mefHabitual <= 0)
        {
            estado = RUTA_CORTANDO;
            tim_mefHabitual = TIEMPO_RUTA_CORTANDO;
        }

        break;

    case RUTA_CORTANDO:
        board_setLed(LRS, ON);
        board_setLed(LRR, OFF);
        board_setLed(LVS, OFF);

        if (contador_titilar <= 0)
        {
            contador_titilar = PERIODO_LVR;
            board_setLed(LVR, TOGGLE);
        }

        if (tim_mefHabitual <= 0)
        {
            estado = SECUNDARIO_HABILITADO;
            tim_mefHabitual = TIEMPO_SECUNDARIO_HABILITADO;
        }

        break;

    case SECUNDARIO_HABILITADO:
        board_setLed(LVR, OFF);
        board_setLed(LRS, OFF);
        board_setLed(LRR, ON);
        board_setLed(LVS, ON);

        if (tim_mefHabitual <= 0)
        {
            estado = SECUNDARIO_CORTANDO;
            tim_mefHabitual = TIEMPO_SECUNDARIO_CORTANDO;
        }
        break;

    case SECUNDARIO_CORTANDO:
        board_setLed(LVR, OFF);
        board_setLed(LRS, OFF);
        board_setLed(LRR, ON);

        if (contador_titilar <= 0)
        {
            contador_titilar = PERIODO_LVS;
            board_setLed(LVS, TOGGLE);
        }

        if (tim_mefHabitual <= 0)
        {
            estado = RUTA_HABILITADA;
            tim_mefHabitual = TIEMPO_RUTA_HABILITADA;
        }
        break;

    default:
        break;
    }

    return (estado == RUTA_HABILITADA);
}

void mefHabitual_periodicTask1ms(void)
{
    if (tim_mefHabitual)
        tim_mefHabitual--;

    if (contador_titilar)
        contador_titilar--;

    actualizar_autos_en_espera(estado == RUTA_HABILITADA);
}

/*==================[end of file]============================================*/
