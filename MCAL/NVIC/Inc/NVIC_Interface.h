/***************************************************************************************************
 * @file  	NVIC_Interface.h
 * @brief 	This file contains the function prototypes & public interfaces components of the NVIC driver
 * @author 	Ibrahim Saber
 * @version 1.0
 * @date 	7 - 2 -2025
 ***************************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

					/**************** Interfacing Enums **********************/
typedef enum
{
	NVIVC_Exit_Ok,
	NVIC_Invalid_IRQ,
	NVIC_NULL_PTR

}NVIC_ErrorState_t;


typedef enum
{
	NVIC_ActvFlag_Set,
	NVIC_ActvFlag_Clear

}NVIC_ActvFlag_t;

typedef enum
{
	IRQ0_WWDG,
	IRQ1_PVD,
	IRQ2_TAMP_STAMP,
	IRQ3_RTC_WKUP,
	IRQ4_FLASH,
	IRQ5_RCC,
	IRQ6_EXTI0,
	IRQ7_EXTI1,
	IRQ8_EXTI2,
	IRQ9_EXTI3,
	IRQ10_EXTI4,
	IRQ11_DMA1_Stream0,
	IRQ12_DMA1_Stream1,
	IRQ13_DMA1_Stream2,
	IRQ14_DMA1_Stream3,
	IRQ15_DMA1_Stream4,
	IRQ16_DMA1_Stream5,
	IRQ17_DMA1_Stream6,
	IRQ18_ADC,
	IRQ19_CAN1_TX,
    IRQ20_CAN1_RX0,
	IRQ21_CAN1_RX1,
	IRQ22_CAN1_SCE,
	IRQ23_EXTI9_5,
	IRQ24_TIM1_BRK_TIM9,
	IRQ25_TIM1_UP_TIM10,
	IRQ26_TIM1_TRG_COM_TIM11,
	IRQ27_TIM1_CC,
	IRQ28_TIM2,
	IRQ29_TIM3,
	IRQ30_TIM4,
	IRQ31_I2C1_EV,
	IRQ32_I2C1_ER,
    IRQ33_I2C2_EV,
	IRQ34_I2C2_ER,
	IRQ35_SPI1,
	IRQ36_SPI2,
	IRQ37_USART1,
	IRQ38_USART2,
	IRQ39_USART3,
	IRQ40_EXTI15_10,
	IRQ41_RTC_Alarm,
	IRQ42_OTG_FS_WKUP,
	IRQ43_TIM8_BRK_TIM12,
	IRQ44_TIM8_UP_TIM13,
	IRQ45_TIM8_TRG_COM_TIM14,
	IRQ46_TIM8_CC,
	IRQ47_DMA1_Stream7,
	IRQ48_FMC,
	IRQ49_SDIO,
	IRQ50_TIM5,
	IRQ51_SPI3,
	IRQ52_UART4,
	IRQ53_UART5,
	IRQ54_TIM6_DAC,
	IRQ55_TIM7,
	IRQ56_DMA2_Stream0,
	IRQ57_DMA2_Stream1,
	IRQ58_DMA2_Stream2,
	IRQ59_DMA2_Stream3,
	IRQ60_DMA2_Stream4,
	IRQ61_Reserved,
	IRQ62_Reserved,
	IRQ63_CAN2_TX,
	IRQ64_CAN2_RX0,
	IRQ65_CAN2_RX1,
    IRQ66_CAN2_SCE,
	IRQ67_OTG_FS,
	IRQ68_DMA2_Stream5,
	IRQ69_DMA2_Stream6,
	IRQ70_DMA2_Stream7,
	IRQ71_USART6,
	IRQ72_I2C3_EV,
	IRQ73_I2C3_ER,
	IRQ74_OTG_HS_EP1_OUT,
	IRQ75_OTG_HS_EP1_IN,
	IRQ76_OTG_HS_WKUP,
	IRQ77_OTG_HS,
	IRQ78_DCMI,
	IRQ79_Reserved,
	IRQ80_Reserved,
	IRQ81_FPU,
	IRQ82_Reserved,
	IRQ83_Reserved,
	IRQ84_SPI4,
	IRQ85_Reserved,
	IRQ86_Reserved,
	IRQ87_SAI1,
	IRQ88_Reserved,
	IRQ89_Reserved,
	IRQ90_Reserved,
	IRQ91_SAI2,
	IRQ92_QuadSPI,
	IRQ93_HDMI_CEC,
	IRQ94_SPDIF_RX,
	IRQ95_FMPI2C1_Event,
	IRQ96_FMPI2C1_Error


}NVIC_IRQs_t;



/****************************************************************************************************
 * 	@brief		 This Function is used to enable the interrupt of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 Interrupt is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_EnableIRQ(NVIC_IRQs_t Copy_u8IRQNum);



/****************************************************************************************************
 * 	@brief		 This Function is used to disable the interrupt of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 Interrupt is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_DisableIRQ(NVIC_IRQs_t Copy_u8IRQNum);



/****************************************************************************************************
 * 	@brief		 This Function is used to set the pending flag of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_SetPendingFlag(NVIC_IRQs_t Copy_u8IRQNum);



/****************************************************************************************************
 * 	@brief		 This Function is used to clear the pending flag of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_ClearPendingFlag(NVIC_IRQs_t Copy_u8IRQNum);



/****************************************************************************************************
 * 	@brief		 This Function is used to get the active flag status of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: 			an enum value that holds the IRQ number(position) from the vector table.
 * 				 NVIC_ActvFlag_t Copy_u8ActvFlgStat:	used to store the status.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_GetActiveFlag(NVIC_IRQs_t Copy_u8IRQNum, NVIC_ActvFlag_t* Copy_u8ActvFlgStat);


#endif
