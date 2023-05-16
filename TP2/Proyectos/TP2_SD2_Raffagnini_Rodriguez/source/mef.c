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
#include "fsl_debug_console.h"
#include "clock_config.h"
#include "fsl_smc.h"
#include "power_mode_switch.h"
#include "display_utils.h"
#include "math.h"
#include "mma8451.h"
#include "mef.h"

/*==================[macros and definitions]=================================*/

typedef enum
{
    HACIENDO_NONI = 0,
    CAIDA_LIBRE,
    POST_IMPACTO
} Estado_mef;

static const unsigned int G_cuad = 980 * 980;
static const unsigned int G = 980;
static const unsigned int count_deviation = 40;
static unsigned int g_upper_bound = 0;
static unsigned int g_lower_bound = 0;

/*==================[internal data declaration]==============================*/
static unsigned int tim_mef;
static unsigned int tim_led;
static unsigned int maximo;
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
    g_upper_bound = (G + count_deviation) * (G + count_deviation);
    g_lower_bound = (G - count_deviation) * (G - count_deviation);

    board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_OFF);
    mma8451_disable_DR_IRQ();
    display_sleepingState();

    // Bajamos la frecuencia del micro
    APP_PowerModeSwitch(kSMC_PowerStateRun, kAPP_PowerModeVlpr);
    APP_ShowPowerMode(SMC_GetPowerModeState(SMC));

    estado = HACIENDO_NONI;
}

int mef_run(void)
{
    switch (estado)
    {

    case HACIENDO_NONI:
    {
        board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_OFF);

        if (mma8451_getIsFalling())
        {
            APP_PowerModeSwitch(kSMC_PowerStateVlpr, kAPP_PowerModeRun);
            APP_ShowPowerMode(SMC_GetPowerModeState(SMC));
            mma8451_enable_DR_IRQ();
            //print_falling_state();

            estado = CAIDA_LIBRE;
        }
    }
    break;

    case CAIDA_LIBRE:
    {
    	// ***** Detección de máxima aceleración
        int64_t x = mma8451_getAcX();
        int64_t y = mma8451_getAcY();
        int64_t z = mma8451_getAcZ();

        unsigned int nuevo_valor = x * x + y * y + z * z;

        if (maximo < nuevo_valor)
            maximo = nuevo_valor;

        if (maximo > G_cuad && nuevo_valor < maximo
        && nuevo_valor > g_lower_bound && nuevo_valor < g_upper_bound)
        {
        	display_accelDisplayState((unsigned int)sqrt(maximo));
            tim_mef = 10000;
            key_getPressEv(BOARD_SW_ID_1); // Tomo cualquier posible evento
            maximo = 0;
            estado = POST_IMPACTO;
        }

        if (tim_led <= 0)
        {
            tim_led = 250;
            board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_TOGGLE);
        }
    }
    break;

    case POST_IMPACTO:
    {
        board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_ON);

        if (key_getPressEv(BOARD_SW_ID_1) || tim_mef <= 0)
        {
        	mma8451_disable_DR_IRQ();
        	display_sleepingState();
        	mma8451_getIsFalling();

        	// Bajamos la frecuencia del micro
            APP_PowerModeSwitch(kSMC_PowerStateRun, kAPP_PowerModeVlpr);
            APP_ShowPowerMode(SMC_GetPowerModeState(SMC));
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
