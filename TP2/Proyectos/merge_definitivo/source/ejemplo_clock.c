/* Copyright 2019, DSI FCEIA UNR - Sistemas Digitales 2
 *    DSI: http://www.dsi.fceia.unr.edu.ar/
 * Copyright 2019, Esteban Almiron
 * Copyright 2019, Gustavo Muro
 * Copyright 2023, Guido Cicconi
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

#include <stdio.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "clock_config.h"
#include "fsl_smc.h"
#include "power_mode_switch.h"

#include "SD2_board.h"
#include "key.h"
#include "oled.h"
#include "SD2_I2C.h"
#include "mma8451.h"
#include "mef.h"
#include "display_utils.h"

static uint32_t timeDown1ms;

int main(void)
{
  // Init FSL debug console.
  BOARD_InitDebugConsole();

  uint32_t freq = 0;
  smc_power_state_t currentPowerState;

  PRINTF("\r\n####################  TP2 Raffagnini Rodriguez - SD2 ####################\n\r\n");

  currentPowerState = SMC_GetPowerModeState(SMC);
  APP_ShowPowerMode(currentPowerState);
  PRINTF("    Clock luego del Reset\n");

  freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
  PRINTF("    Core Clock = %dMHz \r\r", freq / 1000000);

  BOARD_InitBootClocks();                                  // Se configuran los clocks a máxima frecuencia
  SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll); // Se habilita la posibilidad de operar con todos los modos de bajo consumo

  PRINTF("    Clock a max. frec.\n");
  freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
  PRINTF("    Core Clock = %dMHz \r\r", freq / 1000000);

  // =========== Inicializaciones varias ===================
  board_init();                            // Funciones de la placa
  key_init();                              // MEF de pulsadores
  SysTick_Config(SystemCoreClock / 1000U); // Interrupción de systick

  // =========== SPI ===================
  board_configSPI1();

  // =========== OLED ===================
  oled_init();
  oled_setContrast(16);
  oled_clearScreen(OLED_COLOR_BLACK);

  // =========== I2C ===================
  SD2_I2C_init();

  // =========== MMA8451 ================
  mma8451_init();
  mma8451_setDataRate(DR_100hz);
  print_accel_display_state(1281);

  // ****************** EJECUCIÓN
  mef_init();

  while (1)
  {
    mef_run();
    /*
    if (timeDown1ms == 0)
    {
      timeDown1ms = 100;
      board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_TOGGLE);
    }

    if (key_getPressEv(BOARD_SW_ID_1))
    {
      APP_PowerModeSwitch(kSMC_PowerStateVlpr, kAPP_PowerModeRun);

      currentPowerState = SMC_GetPowerModeState(SMC);
      APP_ShowPowerMode(currentPowerState);

      freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
      PRINTF("    Core Clock = %dMHz \r\r", freq / 1000000);
    }

    if (key_getPressEv(BOARD_SW_ID_3))
    {
      APP_PowerModeSwitch(kSMC_PowerStateRun, kAPP_PowerModeVlpr);

      currentPowerState = SMC_GetPowerModeState(SMC);
      APP_ShowPowerMode(currentPowerState);

      freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
      PRINTF("    Core Clock = %dMHz \r\r", freq / 1000000);
    }*/
  }

  return 0;
}

void SysTick_Handler(void)
{
  mef_periodicTask1ms();
}
