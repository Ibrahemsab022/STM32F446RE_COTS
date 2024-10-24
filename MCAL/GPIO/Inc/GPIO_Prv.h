#ifndef GPIO_PRV_H
#define GPIO_PRV_H


/*Number of GPIO Peripherals for this mcu (GPIOA...GPIOH)*/
#define GPIO_PERIPHERAL_NUM			8u

/*To divide by or Modul by for finding if we should config AFRL or AFRH and to find the bit Number correctly*/
#define AFR_PIN_SHIFTING			8u

/******************* Masks *******************/
#define GPIO_1BIT_MASK  0b1
#define GPIO_2BIT_MASK  0b11
#define GPIO_4BIT_MASK	0b1111


#define GPIO_2BIT_PIN_REG 2u
#define GPIO_4BIT_PIN_REG 4u



#define NULL ((void *)0)



#endif
