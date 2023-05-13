/*
###############################################################################
#
# Copyright 2023, Guido Cicconi
# All rights reserved
#
# This file is part of SISTEMAS DIGITALES 2 - FCEIA - UNR.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#                                                                             */

/*==================[inclusions]=============================================*/
#include <mef.h>

#include "SD2_board.h"
#include "mma8451.h"
#include "fsl_debug_console.h"
/*==================[macros and typedef]=====================================*/
typedef enum{
	INICIO=0, LR_ON, LV_ON
}estMef_enum;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
static estMef_enum estMef;
static int16_t acc;

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

extern void mef_init(void)
{
    estMef = INICIO;
}

extern void mef(void)
{
	acc = mma8451_getAcX();
	switch(estMef){
		case INICIO:
			if(acc>50){
				//board_setLed(BOARD_LED_ID_ROJO, BOARD_LED_MSG_ON);
				PRINTF("    LED ROJO ON\n\n");
				estMef = LR_ON;
			}
			if(acc<-50){
				PRINTF("    LED VERDE ON\n\n");
				estMef = LV_ON;
			}
			break;

		case LR_ON:
			if(acc<50){
				PRINTF("    LED ROJO OFF\n\n");
				estMef = INICIO;
			}
			break;

		case LV_ON:
			if(acc>-50){
				PRINTF("    LED VERDE OFF\n\n");
				estMef = INICIO;
			}
			break;

		default:
			estMef=INICIO;
			break;
	}
}

/*==================[end of file]============================================*/
