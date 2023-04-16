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
#include "mef_cruce.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    AVISO_CORTE_CAMINO,
    CRUCE_HABILITADO,
    AVISO_HABILITACION_RUTA
}
estado_mefCruce;

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

//Temporizaciones en [ms]
static const unsigned int TIEMPO_AVISO_CORTE_RUTA = 10000;
static const unsigned int TIEMPO_CRUCE_HABILITADO = 30000; //60000
static const unsigned int TIEMPO_AVISO_HABILITACION_RUTA = 10000;
static const unsigned int PERIODO_LVR = 200;
static const unsigned int PERIODO_LRR = 200;

static unsigned int tim_mefCruce;
static unsigned int contador_titilar;
static estado_mefCruce estado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void mefCruce_init(void)
{
    contador_titilar = 0;
    tim_mefCruce = TIEMPO_AVISO_CORTE_RUTA;
    estado = AVISO_CORTE_CAMINO;
}

bool mefCruce_run(void)
{
    switch (estado)
    {
        case AVISO_CORTE_CAMINO:
            board_setLed(LRS, ON);
            board_setLed(LRR, OFF);
            board_setLed(LVS, OFF);

            if (contador_titilar <= 0)
            {
                contador_titilar = PERIODO_LVR;
                board_setLed(LVR, TOGGLE);
            }

            if (tim_mefCruce <= 0)
            {
                estado = CRUCE_HABILITADO;
                tim_mefCruce = TIEMPO_CRUCE_HABILITADO;
            }
            break;

        case CRUCE_HABILITADO:
            board_setLed(LVR, OFF);
            board_setLed(LRS, OFF);
            board_setLed(LRR, ON);
            board_setLed(LVS, ON);

            if (tim_mefCruce <= 0)
            {
                estado = AVISO_HABILITACION_RUTA;
                tim_mefCruce = TIEMPO_AVISO_HABILITACION_RUTA;
            }
            break;

        case AVISO_HABILITACION_RUTA:
            board_setLed(LVR, OFF);
            board_setLed(LRS, OFF);
            board_setLed(LVS, ON);

            if (contador_titilar <= 0)
            {
                contador_titilar = PERIODO_LRR;
                board_setLed(LRR, TOGGLE);
            }


            if (tim_mefCruce <= 0)
            {
                return true;
            }
            break;

        default:
            break;
    }

    return false;
}

void mefCruce_periodicTask1ms(void)
{
    if (tim_mefCruce)
        tim_mefCruce--;

    if (contador_titilar)
        contador_titilar--;
}

/*==================[end of file]============================================*/
