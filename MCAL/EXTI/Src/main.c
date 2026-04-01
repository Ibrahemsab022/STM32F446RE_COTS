/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ibrahim Saber
 * @brief          : Testing the EXTI and the SYSCFG drivers
 * @date: 			24-03-2025
 * Last Update:     09:50 PM, Wednesday, April 1, 2026
 ******************************************************************************
 */

#include <stdint.h>

#include "RCC_Interface.h"
#include "GPIO_Interface.h"

#include "NVIC_Interface.h"
#include "SYSCFG_Interface.h"
#include "EXTI_Interface.h"




/*App func prototype*/
void AppFunc(void);


/*Configs structs*/
PinConfig_t PC13_UsrButton = {
								.Mode = INPUT,
								.Port = PORTC,
								.PinNum = PIN13,
								.PullType = NO_PULL,
};

PinConfig_t PA05_LED2 = {

							   .Mode = OUTPUT,
							   .OutputType = PUSH_PULL,
							   .Speed = LOW_SPEED,
							   .AltFunc = AF0,
							   .PullType = PULL_DOWN,
							   .Port = PORTA,
							   .PinNum = 5

};



EXTI_Configs_t PC13_EXTIConfigs = {
										.InitStat = EXTI_DISABLED,
										.IntLine = EXTI13,
										.TrigType = EXTI_FallingEdge,
										.callBackFunc = &AppFunc,
};



uint8_t Local_u8ButtonTest = 1;

int main(void)
{
	RCC_SetClkStatus(HSI, ON);
	RCC_SetSysClk(HSI);

	RCC_AHB1EnableClk(AHB1_GPIOC);
	RCC_AHB1EnableClk(AHB1_GPIOA);
	RCC_APB2EnableClk(APB2_SYSCFG);

	GPIO_u8PinInit((PinConfig_t *) &PC13_UsrButton);
	GPIO_u8PinInit((PinConfig_t *) &PA05_LED2);


	SYSCFG_SetEXTIPort(SYSCFG_PORTC, SYSCFG_EXTI13);
	//GPIO_u8TogglePinValue(PORTA, PIN5);

	EXTI_Init((EXTI_Configs_t *) &PC13_EXTIConfigs);
	EXTI_EnableInterrupt(PC13_EXTIConfigs.IntLine);

	NVIC_SetPriority(IRQ40_EXTI15_10, 0b0101);
	NVIC_EnableIRQ(IRQ40_EXTI15_10);



    /* Loop forever */
	for(;;)
	{
		//GPIO_u8ReadPinValue(PORTC, PIN13, (PinVal_t*) &Local_u8ButtonTest);
	}
}


void AppFunc(void)
{
	GPIO_u8TogglePinValue(PORTA, PIN5);
}
