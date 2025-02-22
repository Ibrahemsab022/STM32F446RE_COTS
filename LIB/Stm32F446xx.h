#ifndef STM32F446xx_H
#define STM32F446xx_H




/******************* Core Peripherals Base Addresses *******************/
/*@todo: add systic*/
#define NVIC_BASE_ADDRESS	 	0xE000E100UL
#define SCB_BASE_ADDRESS		0xE000E008UL



/******************* Various Memories Base Addresses *******************/
#define FLASH_BASE_ADDRESS		0x08004000UL
#define SRAM_BASE_ADDRESS		0x20000000UL
#define ROM_BASE_ADDRESS		0x1FFF0000UL


/******************* AHB1 Peripheral Base Addresses *******************/
#define GPIOA_BASE_ADDRESS		0x40020000U			
#define GPIOB_BASE_ADDRESS      0x40020400U 
#define GPIOC_BASE_ADDRESS      0x40020800U
#define GPIOD_BASE_ADDRESS      0x40020C00U
#define GPIOE_BASE_ADDRESS      0x40021000U
#define GPIOF_BASE_ADDRESS      0x40021400U
#define GPIOG_BASE_ADDRESS      0x40021800U
#define GPIOH_BASE_ADDRESS      0x40021C00U


#define RCC_BASE_ADDRESS		0x40023800U

/******************* AHB2 Peripheral Base Addresses *******************/






/******************* AHB3 Peripheral Base Addresses *******************/




/******************* APB1 Peripheral Base Addresses *******************/





/******************* APB2 Peripheral Base Addresses *******************/




/******************* SCB Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t ACTLR;					/*Auxiliary Control Register*/
	volatile uint32_t RESERVED0[829];           /*Reserved for 3316 bytes offset*/
	volatile uint32_t CPUID;                    /*CPU ID Base Register*/
	volatile uint32_t ICSR;                     /*Interrupt Control and State Register*/
	volatile uint32_t VTOR;                     /*Vector Table Offset Register*/
	volatile uint32_t AIRCR;                    /*Application Interrupt and Reset Control Register*/
	volatile uint32_t SCR;                      /*System Control Register*/
	volatile uint32_t CCR;                      /*Configuration & Control Register*/
	volatile uint32_t SHPR[3];                  /*System Handler Priority Registers*/
	volatile uint32_t SHCRS;                    /*System Handler Control and State Register*/
	union                                       /*Union because the following two Regs. share the same address*/
	{
		volatile uint32_t CFSR;                 /*Configurable Fault Status Register*/
		volatile uint32_t MMSR;                 /*MemManage Fault Status Register*/
	};
	volatile uint8_t BFSR;                      /*BusFault Status Register*/
	volatile uint16_t UFSR;                     /*UsageFault Status Register*/
	volatile uint32_t HFSR;                     /*HardFault Status Register*/
	volatile uint32_t RESERVED1;                /*Reserved for 4 bytes offset*/
	volatile uint32_t MMAR;                     /*MemManage Fault Address Register*/
	volatile uint32_t BFAR;                     /*Bus Fault Address Register*/
	volatile uint32_t AFSR;                     /*Auxiliary Fault Status Register*/


}SCB_RegDef_t;



/******************* NVIC Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t ISER[8];				/*Interrupt Set-enable Registers*/
	volatile uint32_t RERSERVED1[24];
	volatile uint32_t ICER[8];				/*Interrupr Clear-enable Registers*/
	volatile uint32_t RERSERVED2[24];
	volatile uint32_t ISPR[8];				/*Interrupt Set-Pending Registers*/
	volatile uint32_t RERSERVED3[24];
	volatile uint32_t ICPR[8];				/*Interrupt Clear-pending Registers*/
	volatile uint32_t RERSERVED4[24];
	volatile uint32_t IABR[8];              /*Interrupt Active Bit Registers*/
	volatile uint32_t RERSERVED5[56];
	volatile uint8_t  IPR[240];              /*Interrupt priority Registers*/
	volatile uint32_t RERSERVED6[643];
	volatile uint32_t STIR;					/*Software Trigger Interrupt Register*/

}NVIC_RegDef_t;



/******************* RCC Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t CR;						/*RCC Clk Control Register*/
	volatile uint32_t PLLCFGR;					/*RCC PLL Configuration Register*/
	volatile uint32_t CFGR;						/*RCC Clk Interrupt Register*/
	volatile uint32_t CIR;						/*RCC AHB1 Peripheral Reset Register*/
	volatile uint32_t AHB1RSTR;					/*RCC AHB1 Peripheral Reset Register*/
	volatile uint32_t AHB2RSTR;					/*RCC AHB1 Peripheral Reset Register*/
	volatile uint32_t AHB3RSTR;					/*RCC AHB1 Peripheral Reset Register*/
	uint32_t RESERVED0;                         /*Reserved, 0x1C*/
	volatile uint32_t APB1RSTR;                 /*RCC APB1 perihpheral Reset Register*/
	volatile uint32_t APB2RSTR;                 /*RCC APB2 perihpheral Reset Register*/
	uint32_t RESERVED1[2];                      /*Reserved, 0x28 ~ 0x2C*/
	volatile uint32_t AHB1ENR;                  /*RCC AHB1 Peripheral Clk enable Register*/
	volatile uint32_t AHB2ENR;                  /*RCC AHB2 Peripheral Clk enable Register*/
	volatile uint32_t AHB3ENR;                  /*RCC AHB3 Peripheral Clk enable Register*/
	uint32_t RESERVED2;                         /*Reserved, 0x3C*/
	volatile uint32_t APB1ENR;                  /*RCC APB1 peripheral clk enable Register*/
	volatile uint32_t APB2ENR;                  /*RCC APB1 peripheral clk enable Register*/
	uint32_t RESERVED3[2];                      /*Reserved, 0x48 ~ 0x4C*/
	volatile uint32_t AHB1LPENR;                /*RCC AHB1 Peripherial clk enable in low power mode Register*/
	volatile uint32_t AHB2LPENR;                /*RCC AHB2 Peripherial clk enable in low power mode Register*/
	volatile uint32_t AHB3LPENR;                /*RCC AHB3 Peripherial clk enable in low power mode Register*/
	uint32_t RESERVED4;                         /*Reserved, 0x5C*/
	volatile uint32_t APB1LPENR;                /*RCC APB1 Peripheral clk enable in low power mode Register*/
	volatile uint32_t APB2LPENR;                /*RCC APB2 Peripheral clk enable in low power mode Register*/
	uint32_t RESERVED5[2];                      /*Reserved, 0x68 ~ 0x6C*/
	volatile uint32_t BDCR;                     /*RCC Back Domain Control Register*/
	volatile uint32_t CSR;                      /*RCC Clk Control & Status Register*/
	uint32_t RESERVED6[2];                      /*Reserve, 0x78~0x7C*/
	volatile uint32_t SSCGR;                    /*RCC Spread Spectrum clk generation Register*/
	volatile uint32_t PLLI2SCFGR;               /*RCC PLLI2S configuration Register*/
	volatile uint32_t PLLSAICFGR;               /*RCC PLLSAI configuration Register*/
	volatile uint32_t DCKCFGR;                  /*RCC Dedicated Clock configuration Register*/
	volatile uint32_t CKGATENR;                 /*RCC Clocks Gated Enable Register*/
	volatile uint32_t DCKCFGR2;                 /*RCC Dedicated Clocks Configuration register 2*/
	
	
}RCC_RegDef_t;



/******************* GPIO Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t MODER;				/*GPIO PORT Mode Register*/
	volatile uint32_t OTYPER;				/*GPIO PORT Output Type Register*/
	volatile uint32_t OSPEEDR;				/*GPIO PORT Output speed Register*/
	volatile uint32_t PUPDR;				/*GPIO PORT Pull-Up/Pull-Down Register*/
	volatile uint32_t IDR;					/*GPIO PORT Input Data Register*/
	volatile uint32_t ODR;					/*GPIO PORT Output Data Register*/
	volatile uint32_t BSRR;					/*GPIO PORT Bit Set/Reset Register*/
	volatile uint32_t LCKR;					/*GPIO PORT Lock Register*/
	volatile uint32_t AFR[2];				/*GPIO PORT Alternate Function High & Low Registers*/

}GPIO_RegDef_t;




/******************* SCB Peripheral Definition *******************/
#define SCB 	((SCB_RegDef_t *) SCB_BASE_ADDRESS)

/******************* NVIC Peripheral Definition *******************/
#define NVIC	((NVIC_RegDef_t *) NVIC_BASE_ADDRESS)


/******************* RCC Peripheral Definition *******************/
#define RCC		((RCC_RegDef_t *) RCC_BASE_ADDRESS)


/******************* GPIO Peripheral Definitions *******************/
#define GPIOA		((GPIO_RegDef_t *) GPIOA_BASE_ADDRESS)
#define GPIOB		((GPIO_RegDef_t *) GPIOB_BASE_ADDRESS)
#define GPIOC		((GPIO_RegDef_t *) GPIOC_BASE_ADDRESS)
#define GPIOD		((GPIO_RegDef_t *) GPIOD_BASE_ADDRESS)
#define GPIOE		((GPIO_RegDef_t *) GPIOE_BASE_ADDRESS)
#define GPIOF		((GPIO_RegDef_t *) GPIOF_BASE_ADDRESS)
#define GPIOG		((GPIO_RegDef_t *) GPIOG_BASE_ADDRESS)
#define GPIOH		((GPIO_RegDef_t *) GPIOH_BASE_ADDRESS)






#endif
