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
#include "mef_trafico.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    AVISO_HABILITACION_CAMINO,
    CAMINO_HABILITADO,
    AVISO_CORTE_RUTA,
    SALIR
}
estado_mefTrafico;

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
static unsigned int tim_mefTrafico;
static unsigned int contador_titilar;
static estado_mefTrafico estado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void mefTrafico_init(void)
{
    tim_mefTrafico = 0;
    contador_titilar = 0;
    tim_mefTrafico = 5 * 1000;
    estado = AVISO_HABILITACION_CAMINO;
}

int mefTrafico_run(int cant_autos_en_espera)
{
    switch (estado)
    {
        case AVISO_HABILITACION_CAMINO:
            board_setLed(LRS, ON);
            board_setLed(LRR, OFF);
            board_setLed(LVS, OFF);

            if (contador_titilar <= 0)
            {
                contador_titilar = 200;
                board_setLed(LVR, TOGGLE);
            }

            if (tim_mefTrafico <= 0)
            {
                estado = CAMINO_HABILITADO;
            }
            break;

        case CAMINO_HABILITADO:
            board_setLed(LVR, OFF);
            board_setLed(LRS, OFF);
            board_setLed(LRR, ON);
            board_setLed(LVS, ON);

            if (cant_autos_en_espera <= 0)
            {
                estado = AVISO_CORTE_RUTA;
                tim_mefTrafico = 5 * 1000;
            }
            break;

        case AVISO_CORTE_RUTA:
            board_setLed(LVR, OFF);
            board_setLed(LRS, OFF);
            board_setLed(LRR, ON);

            if (contador_titilar <= 0)
            {
                contador_titilar = 200;
                board_setLed(LVS, TOGGLE);
            }


            if (tim_mefTrafico <= 0)
            {
                estado = SALIR;
            }
            break;

        case SALIR:
            break;

        default:
            break;
    }

    return (estado == SALIR);
}

void mefTrafico_periodicTask1ms(void)
{
    if (tim_mefTrafico)
        tim_mefTrafico--;

    if (contador_titilar)
        contador_titilar--;
}

/*==================[end of file]============================================*/