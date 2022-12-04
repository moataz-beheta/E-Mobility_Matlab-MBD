#define LED_RED		1
#define LED_GREEN	2

#define LED_RED_PORT 	PORTD
#define LED_RED_PIN 	3

#define LED_GREEN_PORT 	PORTD
#define LED_GREEN_PIN 	4

extern unsigned char Led_TurnOn(unsigned char Led_Id);
extern unsigned char Led_TurnOff(unsigned char Led_Id);