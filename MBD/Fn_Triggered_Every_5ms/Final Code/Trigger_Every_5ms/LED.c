#include	"LED.h"
#include	"Dio_interface.h"


unsigned char Led_TurnOn(unsigned char Led_Id)
{
	DioConfig DIO;
	DIO.Direction = OUTPUT;
	DIO.Value = HIGH;
		if (Led_Id==LED_1)
	{
		DIO.Port = LED_1_PORT;
		DIO.Pin = LED_1_PIN;
	}

	else if (Led_Id==LED_2)
	{
		DIO.Port = LED_2_PORT;
		DIO.Pin = LED_2_PIN;
	}
	DIO_voidSetPinDirection(&DIO);
	DIO_voidSetPinValue(&DIO);
	return 0;
}
unsigned char Led_TurnOff(unsigned char Led_Id)
{
	DioConfig DIO;
	DIO.Direction = OUTPUT;
	DIO.Value = LOW;
		if (Led_Id==LED_1)
	{
		DIO.Port = LED_1_PORT;
		DIO.Pin = LED_1_PIN;
	}

	else if (Led_Id==LED_2)
	{
		DIO.Port = LED_2_PORT;
		DIO.Pin = LED_2_PIN;
		
	}
	DIO_voidSetPinDirection(&DIO);
	DIO_voidSetPinValue(&DIO);
	return 0;
}