#include	"Buzzer.h"
#include	"Dio_interface.h"


void BuzzerOn(void)
{
	DioConfig DIO;
	DIO.Direction = OUTPUT;
	DIO.Value = HIGH;
	DIO.Port 	= BUZZER_PORT;
	DIO.Pin 	= BUZZER_PIN;
	DIO_voidSetPinDirection(&DIO);
	DIO_voidSetPinValue(&DIO);
}
void BuzzerOff(void)
{
	DioConfig DIO;
	DIO.Direction = OUTPUT;
	DIO.Value = LOW;
	DIO.Port 	= BUZZER_PORT;
	DIO.Pin 	= BUZZER_PIN;
	DIO_voidSetPinDirection(&DIO);
	DIO_voidSetPinValue(&DIO);
}