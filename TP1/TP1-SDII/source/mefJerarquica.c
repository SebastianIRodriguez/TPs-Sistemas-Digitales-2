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
#include "mefJerarquica.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    MEF_HABITUAL = 0,
    MEF_CRUCE,
    MEF_TRAFICO,
    SECUNDARIO_CORTANDO;
}
estado_mefJerarquica;

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
static estado_mefJerarquica estado;
static bool corte_habilitado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void mefJerarquica_init(void)
{
    estado = MEF_HABITUAL;
    corte_habilitado = true;
    key_getPressEv(BOARD_SW_ID_1); // Por las dudas si estaba apretado
}

int mefJerarquica_run(void)
{
    switch (estado)
    {

    case MEF_HABITUAL:
        mefHabitual_run();

        if (key_getPressEv(BOARD_SW_ID_1) && corte_habilitado)
        {
            estado = MEF_CRUCE;
            corte_habilitado = false;
        }
        break;

    case RUTA_CORTANDO:
        board_setLed(LRS, ON);
        board_setLed(LRR, OFF);
        board_setLed(LVS, OFF);

        if (contador_titilar <= 0)
        {
            contador_titilar = 200;
            board_setLed(LVR, TOGGLE);
        }

        if (tim_mefJerarquica <= 0)
        {
            estado = SECUNDARIO_HABILITADO;
            tim_mefJerarquica = 30000;
        }
        break;

    case SECUNDARIO_HABILITADO:
        board_setLed(LVR, OFF);
        board_setLed(LRS, OFF);
        board_setLed(LRR, ON);
        board_setLed(LVS, ON);

        if (tim_mefJerarquica <= 0)
        {
            estado = SECUNDARIO_CORTANDO;
            tim_mefJerarquica = 5000;
        }
        break;

    case SECUNDARIO_CORTANDO:
        board_setLed(LVR, OFF);
        board_setLed(LRS, OFF);
        board_setLed(LRR, ON);

        if (contador_titilar <= 0)
        {
            contador_titilar = 200;
            board_setLed(LVS, TOGGLE);
        }

        if (tim_mefJerarquica <= 0)
        {
            estado = RUTA_HABILITADA;
            tim_mefJerarquica = 120000;
        }
        break;

    default:
        break;
    }

    return estado;
}

void mefJerarquica_periodicTask1ms(void)
{
    if (estado == MEF_HABITUAL)
        mefHabitual_periodicTask1ms();
}

/*==================[end of file]============================================*/
