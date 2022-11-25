#ifndef			DIO_INTERFACE_H
#define			DIO_INTERFACE_H

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#define				PORTA			0
#define				PORTB			1
#define				PORTC			2
#define				PORTD			3

#define				PIN0			0
#define				PIN1			1
#define				PIN2			2
#define				PIN3			3
#define				PIN4			4
#define				PIN5			5
#define				PIN6			6
#define				PIN7			7


#define				INPUT					0
#define				INPUT_PULLED_UP			1
#define				OUTPUT					2

#define				HIGH			1
#define				LOW				0

#define				NO_ErrorS			0
#define				Error_WRONG_PORT	1
#define				Error_WRONG_PIN		2


typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Direction;
	u8 Value;
	u8 Error;
}DioConfig;

void	DIO_voidSetPinDirection(DioConfig *DIO); 	// this pin will be used as i/p or o/p
void	DIO_voidSetPinValue(DioConfig *DIO);        	// this o/p pin will high or low

u8		DIO_u8GetPinValue(DioConfig *DIO);			// this i/p pin is high or low
void	DIO_voidSetPortDirection(DioConfig *DIO); 	// this port will be used as i/p or o/p
void	DIO_voidSetPortValue(DioConfig *DIO);        // this o/p port will high or low



#endif