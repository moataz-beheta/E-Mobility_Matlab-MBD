#include	"LED.h"
#include	"Dio_interface.h"


unsigned char Led_TurnOn(unsigned char Led_Id)
{
	DioConfig DIO;
	DIO.Direction = OUTPUT;
	DIO.Value = HIGH;
		if (Led_Id==LED_GREEN)
	{
		DIO.Port 	= LED_GREEN_PORT;
		DIO.Pin 	= LED_GREEN_PIN;
	}

	else if (Led_Id==LED_RED)
	{
		DIO.Port 	= LED_RED_PORT;
		DIO.Pin 	= LED_RED_PIN;
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
		if (Led_Id==LED_GREEN)
	{
		DIO.Port 	= LED_GREEN_PORT;
		DIO.Pin 	= LED_GREEN_PIN;
	}

	else if (Led_Id==LED_RED)
	{
		DIO.Port 	= LED_RED_PORT;
		DIO.Pin 	= LED_RED_PIN;
		
	}
	DIO_voidSetPinDirection(&DIO);
	DIO_voidSetPinValue(&DIO);
	return 0;
}