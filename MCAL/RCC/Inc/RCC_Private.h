/********************************************************************************************************
 * file: RCC_Private.h
 * brief: This file contains the registers mapping, private definitions for the RCC peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 24-03-2024
 ********************************************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_






#define ENABLED 	1u
#define DISABLED 	0u


/***********************************
 * 	Enums for the Registers bits
 * **********************************/

/*CR Register*/
typedef enum
{
	HSI_ON,
	HSI_RDY,
	HSI_TRIM0 = 3,
	HSI_TRIM1,
	HSI_TRIM2,
	HSI_TRIM3,
	HSI_TRIM4,
	HSI_CAL0,
	HSI_CAL1,
	HSI_CAL2,
	HSI_CAL3,
	HSI_CAL4,
	HSI_CAL5,
	HSI_CAL6,
	HSI_CAL7,
	HSE_ON,
	HSE_RDY,
	HSE_BYP,
	CSS_ON,
	PLL_ON = 24,
	PLL_RDY,
	PLLI2S_ON,
	PLLI2S_RDY,
	PLLSAI_ON,
	PLLSAI_RDY,

}CR_REG_t;


/*PLL CFGR Register*/
typedef enum
{
	PLLM0,
	PLLM1,
	PLLM2,
	PLLM3,
	PLLM4,
	PLLM5,
	PLLN0,
	PLLN1,
	PLLN2,
	PLLN3,
	PLLN4,
	PLLN5,
	PLLN6,
	PLLN7,
	PLLN8,
	PLLP0 = 16,
	PLLP1,
	PLLSRC = 22,
	PLLQ0 = 24,
	PLLQ1,
	PLLQ2,
	PLLQ3,
	PLLR0,
	PLLR1,
	PLLR2,

}PLLCFGR_REG_t;


/*RCC_CFGR*/
typedef enum
{
	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE1_0 = 10,
	PPRE1_1,
	PPRE1_2,
	PPRE2_0,
	PPRE2_1,
	PPRE2_2,
	RTCPRE0,
	RTCPRE1,
	RTCPRE2,
	RTCPRE3,
	RTCPRE4,
	MCO1_0,
	MCO1_1,
	MCO1_PRE0 = 24,
	MCO1_PRE1,
	MCO1_PRE2,
	MCO2_PRE0,
	MCO2_PRE1,
	MCO2_PRE2,
	MCO2_0,
	MCO2_1,

}CFGR_REG_t;



/*CIR Register*/
typedef enum
{
	LSI_RDYF,
	LSE_RDYF,
	HSI_RDYF,
	HSE_RDYF,
	PLL_RDYF,
	PLLI2S_RDYF,
	PLLSAI_RDYF,
	CSSF,
	LSI_RDYIE,
	LSE_RDYIE,
	HSI_RDYIE,
	HSE_RDYIE,
	PLL_RDYIE,
	PLLI2S_RDYIE,
	PLLSAI_RDYIE,
	LSI_RDYC = 16,
	LSE_RDYC,
	HSI_RDYC,
	HSE_RDYC,
	PLL_RDYC,
	PLLI2S_RDYC,
	PLLSAI_RDYC,
	CSSC,

}CIR_REG_t;

/*AHB1 Reset Register*/
typedef enum
{
	GPIOA_RST,
	GPIOB_RST,
	GPIOC_RST,
	GPIOD_RST,
	GPIOE_RST,
	GPIOF_RST,
	GPIOG_RST,
	GPIOH_RST,
	CRC_RST = 12,
	DMA1_RST = 21,
	DMA2_RST,
	OTGHS_RST = 29,

}AHB1RSTR_REG_t;


/*AHB2 Reset Register*/
typedef enum
{
	DCMI_RST,
	OTGFS_RST = 7,

}AHB2RSTR_REG_t;



/*AHB3 Reset Register*/
typedef enum
{
	FMC_RST,
	QSPI_RST,

}AHB3RSTR_REG_t;




/*APB1 Reset Register*/
typedef enum
{
	TIM2_RST,
	TIM3_RST,
	TIM4_RST,
	TIM5_RST,
	TIM6_RST,
	TIM7_RST,
	TIM12_RST,
	TIM13_RST,
	TIM14_RST,
	WWDG_RST = 11,
	SPI2_RST = 14,
	SPI3_RST,
	SPDIFRX_RST,
	UART2_RST,
	UART3_RST,
	UART4_RST,
	UART5_RST,
	I2C1_RST,
	I2C2_RST,
	I2C3_RST,
	DMPI2C1_RST,
	CAN1_RST,
	CAN2_RST,
	CEC_RST,
	PWR_RST,
	DAC_RST,

}APB1RSTR_REG_t;




/*APB2 Reset Register*/
typedef enum
{
	TIM1_RST,
	TIM8_RST,
	USART1_RST = 4,
	USART6_RST,
	ADC_RST = 8,
	SDIO_RST = 11,
	SPI1_RST,
	SPI4_RST,
	SYSCFG_RST,
	TIM9_RST = 16,
	TIM10_RST,
	TIM11_RST,
	SAI1_RST = 23,
	SAI2_RST,


}APB2RSTR_REG_t;


/*AHB1 Enable register*/
typedef enum
{
	GPIOA_EN,
	GPIOB_EN,
	GPIOC_EN,
	GPIOD_EN,
	GPIOE_EN,
	GPIOF_EN,
	GPIOG_EN,
	GPIOH_EN,
	CRC_EN = 12,
	BKP_SRAM_EN = 18,
	DMA1_EN = 21,
	DMA2_EN,
	OTGHS_EN = 29,
	OTGHS_ULPI_EN,

}AHB1ENR_REG_t;



/*AHB2 Enable register*/
typedef enum
{
	DCMI_EN,
	OTGFS_EN = 7,

}AHB2ENR_REG_t;



/*AHB3 Enable Register*/
typedef enum
{
	FMC_EN,
	QSPI_EN,

}AHB3ENR_REG_t;



/*APB1 Enable Register*/
typedef enum
{
	TIM2_EN,
	TIM3_EN,
	TIM4_EN,
	TIM5_EN,
	TIM6_EN,
	TIM7_EN,
	TIM12_EN,
	TIM13_EN,
	TIM14_EN,
	WWDG_EN = 11,
	SPI2_EN = 14,
	SPI3_EN,
	SPDIFRX_EN,
	USART2_EN,
	USART3_EN,
	UART4_EN,
	UART5_EN,
	I2C1_EN,
	I2C2_EN,
	I2C3_EN,
	FMPI2C1_EN,
	CAN1_EN,
	CAN2_EN,
	CEC_EN,
	PWR_EN,
	DAC_EN,

}APB1ENR_REG_t;



/*APB2 Enable Register*/
typedef enum
{
	TIM1_EN,
	TIM8_EN,
	USART1_EN = 4,
	USART6_EN,
	ADC1_EN = 8,
	ADC2_EN,
	ADC3_EN,
	SDIO_EN,
	SPI1_EN,
	SPI4_EN,
	SYSCFG_EN,
	TIM9_EN = 16,
	TIM10_EN,
	TIM11_EN,
	SAI1_EN = 22,
	SAI2_EN,


}APB2ENR_REG_t;



/*AHB1 Low pwr mode register*/
typedef enum
{
	GPIOA_LPEN,
	GPIOB_LPEN,
	GPIOC_LPEN,
	GPIOD_LPEN,
	GPIOE_LPEN,
	GPIOF_LPEN,
	GPIOG_LPEN,
	GPIOH_LPEN,
	CRC_LPEN = 12,
	FLITF_LPEN = 15,
	SRAM1_LPEN,
	SRAM2_LPEN,
	BKP_SRAM_LPEN,
	DMA1_LPEN = 21,
	DMA2_LPEN,
	OTGHS_LPEN = 29,
	OTGHS_ULPI_LPEN,

}AHB1LPENR_REG_t;



/*AHB2 Low pwr mode register*/
typedef enum
{
	DCMI_LPEN,
	OTGFS_LPEN = 7,

}AHB2LPENR_REG_t;



/*AHB3 Low pwr mode Register*/
typedef enum
{
	FMC_LPEN,
	QSPI_LPEN,

}AHB3LPENR_REG_t;



/*APB1 Low pwr mode Register*/
typedef enum
{
	TIM2_LPEN,
	TIM3_LPEN,
	TIM4_LPEN,
	TIM5_LPEN,
	TIM6_LPEN,
	TIM7_LPEN,
	TIM12_LPEN,
	TIM13_LPEN,
	TIM14_LPEN,
	WWDG_LPEN = 11,
	SPI2_LPEN = 14,
	SPI3_LPEN,
	SPDIFRX_LPEN,
	UART2_LPEN,
	UART3_LPEN,
	UART4_LPEN,
	UART5_LPEN,
	I2C1_LPEN,
	I2C2_LPEN,
	I2C3_LPEN,
	DMPI2C1_LPEN,
	CAN1_LPEN,
	CAN2_LPEN,
	CEC_LPEN,
	PWR_LPEN,
	DAC_LPEN,

}APB1LPENR_REG_t;



/*APB2 Low pwr mode Register*/
typedef enum
{
	TIM1_LPEN,
	TIM8_LPEN,
	USART1_LPEN = 4,
	USART6_LPEN,
	ADC1_LPEN = 8,
	ADC2_LPEN,
	ADC3_LPEN,
	SDIO_LPEN = 11,
	SPI1_LPEN,
	SPI4_LPEN,
	SYSCFG_LPEN,
	TIM9_LPEN = 16,
	TIM10_LPEN,
	TIM11_LPEN,
	SAI1_LPEN = 23,
	SAI2_LPEN,


}APB2LPENR_REG_t;



/*Backup domain control register*/
typedef enum
{
	LSE_ON,
	LSE_RDY,
	LSE_BYP,
	LSE_MOD,
	RTC_SEL0 = 8,
	RTC_SEL1,
	RTC_EN = 15,
	BDR_RST,


}BDCR_REG_t;



/*Clock control & status register*/
typedef enum
{
	LSI_ON,
	LSI_RDY,
	RMVF = 24,
	BOR_RSTF,
	PIN_RSTF,
	POR_RSTF,
	SFT_RSTF,
	IWDG_RSTF,
	WWDG_RSTF,
	LPWR_RSTF,


}CSR_REG_t;


/*Spread spectrum clock generation register*/
typedef enum
{
	MOD_PER0,
	MOD_PER1,
	MOD_PER2,
	MOD_PER3,
	MOD_PER4,
	MOD_PER5,
	MOD_PER6,
	MOD_PER7,
	MOD_PER8,
	MOD_PER9,
	MOD_PER10,
	MOD_PER11,
	MOD_PER12,
	INC_STEP0,
	INC_STEP1,
	INC_STEP2,
	INC_STEP3,
	INC_STEP4,
	INC_STEP5,
	INC_STEP6,
	INC_STEP7,
	INC_STEP8,
	INC_STEP9,
	INC_STEP10,
	INC_STEP11,
	INC_STEP12,
	INC_STEP13,
	INC_STEP14,
	SPREAD_SEL = 30,
	SSCG_EN,

}SSCGR_REG_t;



/* PLLI2S Config register*/
typedef enum
{
	PLLI2S_M0,
	PLLI2S_M1,
	PLLI2S_M2,
	PLLI2S_M3,
	PLLI2S_M4,
	PLLI2S_M5,
	PLLI2S_N0,
    PLLI2S_N1,
    PLLI2S_N2,
    PLLI2S_N3,
    PLLI2S_N4,
    PLLI2S_N5,
    PLLI2S_N6,
    PLLI2S_N7,
    PLLI2S_N8,
	PLLI2S_P0 = 16,
	PLLI2S_P1,
	PLLI2S_Q0 = 24,
	PLLI2S_Q1,
	PLLI2S_Q2,
	PLLI2S_Q3,
	PLLI2S_R0,
	PLLI2S_R1,
	PLLI2S_R2,

}PLLI2SCFGR_REG_t;


/*PLL configuration register*/
typedef enum
{
	PLLSAI_M0,
	PLLSAI_M1,
	PLLSAI_M2,
	PLLSAI_M3,
	PLLSAI_M4,
	PLLSAI_M5,
	PLLSAI_N0,
	PLLSAI_N1,
	PLLSAI_N2,
	PLLSAI_N3,
	PLLSAI_N4,
	PLLSAI_N5,
	PLLSAI_N6,
	PLLSAI_N7,
	PLLSAI_N8,
	PLLSAI_P0 = 16,
	PLLSAI_P1,
	PLLSAI_Q0 = 24,
	PLLSAI_Q1,
	PLLSAI_Q2,
	PLLSAI_Q3,

}PLLSAICFGR_REG_t;


/*dedicated clock configuration register*/
typedef enum
{
	PLLIS2_DIVQ0,
	PLLIS2_DIVQ1,
	PLLIS2_DIVQ2,
	PLLIS2_DIVQ3,
	PLLIS2_DIVQ4,
	PLLISAI_DIV_Q0 = 8,
	PLLISAI_DIV_Q1,
	PLLISAI_DIV_Q2,
	PLLISAI_DIV_Q3,
	PLLISAI_DIV_Q4,
	SAI1_SRC0 = 20,
	SAI1_SRC1,
	SAI2_SRC0,
	SAI2_SRC1,
	TIM_PRE,
	I2S1_SRC0,
	I2S1_SRC1,
	I2S2_SRC0,
	I2S2_SRC1,

}DCKCFGR_REG_t;


/*clocks gated enable register*/
typedef enum
{
	AHB2APB1_CKEN,
	AHB2APB2_CKEN,
	CM4DBG_CKEN,
	SPARE_CKEN,
	SRAM_CKEN,
	FLITF_CKEN,
	RCC_CKEN,

}CKGATENR_REG_t;


/*dedicated clocks configuration register 2*/
typedef enum
{
	FMPI2C1_SEL0 = 22,
	FMPI2C1_SEL1,
	CEC_SEL = 26,
	CK48M_SEL,
	SDIO_SEL,
	SPDIFRX_SEL,

}DCKCFGR2_REG_t;





/***************************
 * 			Macros
 * *************************/
#define TIME_OUT	50000u



/***************************
 * 			Masks
 * *************************/
#define CFGR_SW_BITS_MASK		3
#define CFGR_SWS_BITS_MASK  	12
#define CFGR_PLL_M_FACTOR_BITS_MASK	0b111111
#define CFGR_PLL_N_FACTOR_BITS_MASK 0b111111111
#define CFGR_PLL_P_FACTOR_BITS_MASK 0b11
#define CFGR_PLL_Q_FACTOR_BITS_MASK 0b1111
#define CFGR_PLL_R_FACTOR_BITS_MASK 0b111




#endif
