#include "mefJerarquica.h"

int main(void)
{
	//SystemCoreClock = 48MHz
	SysTick_Config(SystemCoreClock / 1000U);

	mefJerarquica_init();

	while(true)
	{
		mefJerarquica_run();
	}

	return 0;
}

void SysTick_Handler(void)
{
	mefJerarquica_periodicTask1ms();
}
