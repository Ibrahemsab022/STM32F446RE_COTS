/*****************************************************
 * file: RCC_Interface.h
 * brief: This file contains the interfaces & func prototypes for the RCC peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 24-03-2024
 ****************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/******************************

      Interfacing Macros

******************************/









/******************************

      Interfacing Enums

******************************/


/*Error State Enum*/
typedef enum
{
	TIME_OUT_EXCEEDED,
	OK,
	WRONG_CLK_SRC_INPUT,
	SWITCHING_OFF_SELECTED_CLK,
	CONFIGING_PLL_WHILE_ON,
	CONFIGURING_PLLSRC_WHILE_PLL_ON,
	WRONG_PLLM_CONFIGURATION,
	WRONG_PLLN_CONFIGURATION,
	WRONG_PLLP_CONFIGURATION,
	WRONG_PLLQ_CONFIGURATION,
	WRONG_PLLR_CONFIGURATION,



}RCC_ErrorStates_t;


/*This enum used for indicating the clk sources*/
typedef enum
{
	HSI,
	HSE,
	PLLP,
	PLL_R,
	PLLI2S,
	PLLSAI,

}clockTypes_t;


/*This enum is used for indicating the state of a clk src*/
typedef enum
{
	ON,
	OFF,

}clockStatus_t;



/*this enum contains the Peripherals on the AHB1 bus*/
typedef enum
{
	AHB1_GPIOA,
	AHB1_GPIOB,
	AHB1_GPIOC,
	AHB1_GPIOD,
	AHB1_GPIOE,
	AHB1_GPIOF,
	AHB1_GPIOG,
	AHB1_GPIOH,
	AHB1_CRC = 12,
	AHB1_BKP_SRAM = 18,
	AHB1_DMA1 = 21,
	AHB1_DMA2,
	AHB1_OTGHS = 29,
	AHB1_OTGHS_ULPI,

}AHB1_Peripheral_t;


/*this enum contains the Peripherals on the AHB2 bus*/
typedef enum
{
	AHB2_DCMI,
	AHB2_OTGFS = 7,


}AHB2_Peripheral_t;



/*this enum contains the Peripherals on the AHB3 bus*/
typedef enum
{
	AHB3_FMC,
	AHB3_QSPI,

}AHB3_Peripheral_t;



/*This enum contains the peripherals on the APB1 bus*/
typedef enum
{
	APB1_TIM2,
	APB1_TIM3,
	APB1_TIM4,
	APB1_TIM5,
	APB1_TIM6,
	APB1_TIM7,
	APB1_TIM12,
	APB1_TIM13,
	APB1_TIM14,
	APB1_WWDG = 11,
	APB1_SPI2 = 14,
	APB1_SPI3,
	APB1_SPDIFRX,
	APB1_USART2,
	APB1_USART3,
	APB1_UART4,
	APB1_UART5,
	APB1_I2C1,
	APB1_I2C2,
	APB1_I2C3,
	APB1_FMPI2C1,
	APB1_CAN1,
	APB1_CAN2,
	APB1_CEC,
	APB1_PWR,
	APB1_DAC,


}APB1_Peripheral_t;


/*This enum contains the peripherals on the APB2 bus*/
typedef enum
{
	APB2_TIM1,
	APB2_TIM8,
	APB2_USART1 = 4,
	APB2_USART6,
	APB2_ADC1 = 8,
	APB2_ADC2,
	APB2_ADC3,
	APB2_SDIO,
	APB2_SPI1,
	APB2_SPI4,
	APB2_SYSCFG,
	APB2_TIM9 = 16,
	APB2_TIM10,
	APB2_TIM11,
	APB2_SAI1 = 22,
	APB2_SAI2,


}APB2_Peripheral_t;





/******************************

      Configs Structs

******************************/
typedef struct
{
	uint8_t PLL_Src;
	uint8_t M_Factor;
	uint16_t N_Factor;
	uint8_t HSE_Input_Freq;
	uint8_t Q_Factor;
	uint8_t R_Factor;
	uint8_t P_Factor;

}PLL_CFG_t;



/******************************

      Functions Prototypes

******************************/

/***************************************************************************************************
 * 	Decription: This Function is used to set the status of the different clk sources
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HSE, PLL,PLL_R, PLLI2S or PLLSAI.
 * 				- clockStatus_t status: expecting an enum indicating wether it's On or off
 * 	Returns: RCC_ErrorStates_t
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a clk source state is indicated succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_SetClkStatus(clockTypes_t type, clockStatus_t status);


/***************************************************************************************************
 * 	Decription: This Function is used to set the sys clk to a given clk source
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HSE, PLL or PLL_R
 * 	Returns: void
 * 	Preconditions: - The Source clk is off while switching
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: Sys clk is set succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_SetSysClk(clockTypes_t type);


/****************************************************************************************************
 * 	Decription: This Function is used to configure the HSE clk
 * 	Parameters: - HSE_Configs_t *configs:a ptr to sutruct containing the configs
 * 	Returns: void																					*
 * 	Preconditions: -                                                                                *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_HSEConfig(void);


/****************************************************************************************************
 * 	Decription: This Function is used to configure the PLL clk
 * 	Parameters: - PLL_CFG_t *PLL_CfgStructPtr:a ptr to sutruct containing the configs
 * 	Returns: void
 * 	Preconditions: - PLL & PLLI2S are disabled
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions:PLL is configured succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_PLLCongfig(PLL_CFG_t *PLL_CfgStructPtr);



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB1EnableClk(AHB1_Peripheral_t Peripheral);




/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB2EnableClk(AHB2_Peripheral_t Peripheral);


/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB3_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB3EnableClk(AHB3_Peripheral_t Peripheral);




/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB1DisableClk(AHB1_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB2DisableClk(AHB2_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB3_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB3DisableClk(AHB3_Peripheral_t Peripheral);




/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB2 bus
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB2EnableClk(APB2_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB2 bus
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB2DisableClk(APB2_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB1 bus
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB1EnableClk(APB1_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB1 bus
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB1DisableClk(APB1_Peripheral_t Peripheral);



#endif
