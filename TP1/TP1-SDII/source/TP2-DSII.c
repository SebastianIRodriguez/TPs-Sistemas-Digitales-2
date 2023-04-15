#include "SD2_board.h"
#include "key.h"
#include "mefJerarquica.h"

int main(void)
{
	//SystemCoreClock = 48MHz
	SysTick_Config(SystemCoreClock / 1000U);

	board_init();
	key_init();
	mefJerarquica_init();

	while(true)
	{
		mefJerarquica_run();
	}

	return 0;
}

void SysTick_Handler(void)
{
	key_periodicTask1ms();
	mefJerarquica_periodicTask1ms();
}
