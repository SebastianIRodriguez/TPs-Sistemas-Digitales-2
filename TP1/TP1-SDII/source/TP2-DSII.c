#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
#include "SD2_board.h"
#include "key.h"

typedef enum{
	ESTADO_INICIAL = 0,
	COMIENZO,
	SEC_A_2,
	SEC_A_3,
	SEC_B_2,
	SEC_B_3,
} estado_mef;

int pl1_problema2();
int mef_secuencia();

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

	SysTick_Config(SystemCoreClock / 1000U);

    board_init();
	key_init();
    board_setLed(BOARD_LED_ID_VERDE,BOARD_LED_MSG_OFF);

    //pl1_problema2();
	pl1_problema9();

    return 0 ;
}

int pl1_problema2()
{
	PRINTF("  ====== Plancha 1, problema 2 ======\n ");
	while(1)
	{
		key_periodicTask1ms();
		mef_secuencia();
	}

	return 0;
}

int pl1_problema9()
{
	PRINTF("  ====== Plancha 1, problema 9 ======\n ");
	while(1)
	{
		mef_secuencia();
	}

	return 0;
}

int mef_secuencia()
{
	static estado_mef estado = ESTADO_INICIAL;

	switch (estado)
	{
	case ESTADO_INICIAL:
		if(key_getPressEv(BOARD_SW_ID_1))
		{
			estado = COMIENZO;
		}
		break;

	case COMIENZO:
		if(key_getPressEv(BOARD_SW_ID_1))
		{
			estado = SEC_A_2;
		}
		else if(key_getPressEv(BOARD_SW_ID_3))
		{
			estado = SEC_B_2;
		}

		break;

	case SEC_A_2:
		if(key_getPressEv(BOARD_SW_ID_3))
		{
			estado = SEC_A_3;
			key_getPressEv(BOARD_SW_ID_1); // Leo para borrar un posible evento
			board_setLed(BOARD_LED_ID_VERDE,BOARD_LED_MSG_TOGGLE);
		}
		break;

	case SEC_A_3:
		if(key_getPressEv(BOARD_SW_ID_1))
		{
			estado = COMIENZO;
		} 
		else if(key_getPressEv(BOARD_SW_ID_3))
		{
			estado = SEC_B_3;
			board_setLed(BOARD_LED_ID_VERDE,BOARD_LED_MSG_TOGGLE);
		}
		break;

	case SEC_B_2:
		if(key_getPressEv(BOARD_SW_ID_1))
		{
			estado = COMIENZO;
		} 
		else if(key_getPressEv(BOARD_SW_ID_3))
		{
			estado = SEC_B_3;
			board_setLed(BOARD_LED_ID_VERDE,BOARD_LED_MSG_TOGGLE);
		}
		break;

	case SEC_B_3:
		if(key_getPressEv(BOARD_SW_ID_1))
		{
			estado = COMIENZO;
			key_getPressEv(BOARD_SW_ID_1);
		}
		break;

	}
	return 0;
}

void SysTick_Handler(void)
{
	key_periodicTask1ms();

	//mefControl_task1ms();

	//lightSensor_task1ms();
}
