#include "SD2_board.h"
#include "key.h"
#include "mefJerarquica.h"

int main(void)
{
	SysTick_Config(SystemCoreClock / 1000U);

	board_init();
	key_init();
	mefHabitual_init();

	return 0;
}

void SysTick_Handler(void)
{
	key_periodicTask1ms();
}
