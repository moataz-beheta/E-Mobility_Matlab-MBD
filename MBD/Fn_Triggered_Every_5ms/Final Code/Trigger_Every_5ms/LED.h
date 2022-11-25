#define LED_1		1
#define LED_2		2

#define LED_1_PORT 	PORTD
#define LED_1_PIN 	3

#define LED_2_PORT 	PORTD
#define LED_2_PIN 	4

extern unsigned char Led_TurnOn(unsigned char Led_Id);
extern unsigned char Led_TurnOff(unsigned char Led_Id);