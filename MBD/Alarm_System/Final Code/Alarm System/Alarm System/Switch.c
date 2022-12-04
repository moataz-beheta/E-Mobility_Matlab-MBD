#include	"Dio_interface.h"
#include	"Switch.h"

unsigned char ReadSwitch(unsigned char Switch_Id)
{
	DioConfig DIO;
	DIO.Direction = INPUT;
	
	if (Switch_Id==SWITCH_1)
	{
		DIO.Port = SWITCH_1_PORT;
		DIO.Pin = SWITCH_1_PIN;
	}

	else if (Switch_Id==SWITCH_2)
	{
		DIO.Port = SWITCH_2_PORT;
		DIO.Pin = SWITCH_2_PIN;
	}
	DIO_voidSetPinDirection(&DIO);
	DIO_u8GetPinValue (&DIO);
	return DIO_u8GetPinValue (&DIO);
}
