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
#include "mef_habitual.h"

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

/*==================[internal functions declaration]=========================*/}
int actualizar_autos_en_espera();

/*==================[internal data definition]===============================*/
static estado_mefJerarquica estado;
static int autos_en_espera;
static bool corte_habilitado;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
int actualizar_autos_en_espera()
{
    if (key_getPressEv(BOARD_SW_ID_3))
    {
        if (estado == MEF_TRAFICO && autos_en_espera)
            autos_en_espera--;
        else
            autos_en_espera++;
    }
    return autos_en_espera;
}

/*==================[external functions definition]==========================*/

void mefJerarquica_init(void)
{
    estado = MEF_HABITUAL;
    corte_habilitado = true;
    autos_en_espera = 0;
    mefHabitual_init();
    // mefCruce_init();
    // mefTransito_init();
}

int mefJerarquica_run(void)
{
    switch (estado)
    {

    case MEF_HABITUAL:
        bool ruta_habilitada = mefHabitual_run();

        if (key_getPressEv(BOARD_SW_ID_1) && ruta_habilitada && corte_habilitado)
        {
            estado = MEF_CRUCE;
            corte_habilitado = false;
        }

        if(autos_en_espera >= 3)
        {
            estado = MEF_TRAFICO;
        }
        break;

    case MEF_CRUCE:
        bool salir;
        // bool salir = mefCruce();
        corte_habilitado = true;
        if (salir)
            estado = MEF_HABITUAL;
        break;

    case MEF_TRAFICO:

        bool salir;
        // bool salir = mefTrafico(autos_en_espera);

        if (salir)
        {
            mefHabitual_init(); // Reseteo la MEF habitual
            estado = MEF_HABITUAL;
        }

        break;

    default:
        break;
    }

    return 0;
}

void mefJerarquica_periodicTask1ms(void)
{
    /**
     * El enunciado dice: "El sensor que detecta vehículos en el camino secundario se emularautilizando SW3
     *  Mientras el sistema permite el paso por la carretera, cada pulsado de SW3 indicara la presencia de
     * un vehículo. Cuando se habilita el paso por el camino secundario, cada pulsado de SW3 indicara que un
     * vehículo ha cruzado. Se debe definir la función que se ocupa de esta tarea."
     *
     * Me resulta medio al pedo, pero creo q la bola va como que "conceptualmente" no está bueno ponerlo en el 
     * main porque si el procesador está ocupado se pierde los eventos, o una boludez así, por eso lo pongo acá.
     * (imposible q vengan 2 autos en 1 ms). Sino la otra es asignar una interrupción al SW3, pero ni en pedo
     *
     */
    if (estado == MEF_HABITUAL)
        mefHabitual_periodicTask1ms();

    if (estado == MEF_CRUCE)
        1;

    if (estado == MEF_TRAFICO)
        1;

    actualizar_autos_en_espera();
}

/*==================[end of file]============================================*/
