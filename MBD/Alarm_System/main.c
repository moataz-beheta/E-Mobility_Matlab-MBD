#include	"STD_types.h"
#include	"Dio_interface.h"
#include	<util/delay.h>

int main(void)
{
	int Value;
	DioConfig DIO;
	
	/////////// Set Port Direction ///////////
	DIO.Port = PORTA;
	DIO.Direction = 0x0F;
	DIO_voidSetPortDirection(&DIO);
	
	/////////// Set Pin Direction ///////////
	DIO.Port = PORTB;
	DIO.Direction = OUTPUT;
	DIO.Pin = 1;
	DIO_voidSetPinDirection(&DIO);
	
	/////////// Get Pin Value ///////////
	DIO.Port = PORTC;
	DIO.Pin = 1;
	Value = DIO_u8GetPinValue (&DIO);
	
	/////////// Set Port Value ///////////
	DIO.Port = PORTD;
	DIO.Value = 0xA1;
	DIO_voidSetPortValue(&DIO);
	
	/////////// Set Pin Value ///////////
	DIO.Port = PORTA;
	DIO.Value = LOW;
	DIO.Pin = 1;
	DIO_voidSetPinValue(&DIO);
	
	while(1)
	{
		
	}
	return 0 ;
}