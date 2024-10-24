#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H






/******************* Error States Enum *******************/

typedef enum
{
	Exit_Ok = 0,
	InvalidPinOrPortNum,
	NullPtr


}GPIOErrorStates_t;
/******************* Interfacing Enums *******************/

typedef enum
{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
	
}Port_t;


typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
	
}Pin_t;




typedef enum
{
	INPUT = 0,
	OUTPUT,
	ALT_FUNC,
	ANALOG
	
}Mode_t;


typedef enum
{
	
	LOW_SPEED = 0,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
	
}OutputSpeed_t;


typedef enum
{
	
	PUSH_PULL = 0,
	OPEN_DRAIN
	
}OutputType_t;



typedef enum
{
	NO_PULL = 0,
	PULL_UP,
	PULL_DOWN
	
}PullUpDown_t;



typedef enum
{
	AF0 = 0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15

}AltFunc_t;


typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH
}PinVal_t;




/******************* Interfacing Structs *******************/


typedef struct
{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	OutputSpeed_t Speed;
	OutputType_t OutputType;
	PullUpDown_t PullType;
	AltFunc_t AltFunc;
	
}GPIO_PinConfig_t;






/******************* Function Prototypes *******************/



/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO pin.			 						
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.											     								
 * 	Returns: uint8_t errorState																					
 * 	Preconditions: - RCC is initialized and working                                 
 * 				   - Clk enabled for GPIO Peripheral 										
 * 	Side effects: No side effects                                                                   
 * 	Post Conditions: a GPIO Pin is configed				                                
 * 	Synch/Asynch: Synch.																			
 * 	Reentrant/NonReenterant: Re                                                						
 ***************************************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t * PinConfigs);




/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO Port (use it when all pins have same configs)
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Port is configed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8PortInit(const GPIO_PinConfig_t * PinConfigs);




/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.			 						
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t PinVal: is an enum holding the pin value.
 * 	Returns: uint8_t errorState																					
 * 	Preconditions: - RCC is initialized and working                                 
 * 				   - Clk enabled for GPIO Peripheral	
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT 
 * 	Side effects: No side effects                                                                   
 * 	Post Conditions: a GPIO Pin is set to a value		                                
 * 	Synch/Asynch: Synch.																			
 * 	Reentrant/NonReenterant: Re                                                						
 ***************************************************************************************************/
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);





/****************************************************************************************************
 * 	Decription: This Function is used to toggle a GPIO pin.			 						
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 * 	Returns: uint8_t errorState																					
 * 	Preconditions: - RCC is initialized and working                                 
 * 				   - Clk enabled for GPIO Peripheral	
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT 
 * 	Side effects: No side effects                                                                   
 * 	Post Conditions: a GPIO Pin is set to a value		                                
 * 	Synch/Asynch: Synch.																			
 * 	Reentrant/NonReenterant: Re                                                						
 ***************************************************************************************************/
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum);





/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.			 						
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t* PinVal: is a ptr to an enum to recive the value by reference.
 * 	Returns: uint8_t errorState																					
 * 	Preconditions: - RCC is initialized and working                                 
 * 				   - Clk enabled for GPIO Peripheral	
 *				   - Pin is Configed usin GPIO_u8PinInit as INPUT 
 * 	Side effects: No side effects                                                                   
 * 	Post Conditions: a GPIO Pin is read	                                
 * 	Synch/Asynch: Synch.																			
 * 	Reentrant/NonReenterant: Re                                                						
 ***************************************************************************************************/
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal);






#endif
