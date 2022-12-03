#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"Dio_interface.h"
#include	"Dio_private.h"

void	DIO_voidSetPinDirection(DioConfig *DIO )	//this pin will be used as i/p or o/p
{
	/*		Range Check				*/
	if( (DIO->Port < NUM_OF_PORTS) && (DIO->Pin < NUM_OF_PINS) )
	{
		if(DIO->Direction == OUTPUT)
		{
			switch(DIO->Port)
			{
				case PORTA :	SET_BIT(HWREG(DDRA_REG),DIO->Pin);	break;
				case PORTB :	SET_BIT(HWREG(DDRB_REG),DIO->Pin);	break;
				case PORTC :	SET_BIT(HWREG(DDRC_REG),DIO->Pin);	break;
				case PORTD :	SET_BIT(HWREG(DDRD_REG),DIO->Pin);	break;
				default    :										break;
			}
		}
		
		else if (DIO->Direction == INPUT)
		{
			switch(DIO->Port)
			{
				case PORTA :	CLR_BIT(HWREG(DDRA_REG),DIO->Pin);	break;
				case PORTB :	CLR_BIT(HWREG(DDRB_REG),DIO->Pin);	break;
				case PORTC :	CLR_BIT(HWREG(DDRC_REG),DIO->Pin);	break;
				case PORTD :	CLR_BIT(HWREG(DDRD_REG),DIO->Pin);	break;
				default    :										break;
			}			
		}	
		else if (DIO->Direction == INPUT_PULLED_UP)
		{
			CLR_BIT(HWREG(SFIOR_REG),PUD_PIN);	//Clear PUD pin in SFIOR to enable pulling up the pin
			switch(DIO->Port)
			{
				case PORTA :	CLR_BIT(HWREG(DDRA_REG),DIO->Pin);
								SET_BIT(HWREG(PORTA_REG),DIO->Pin);
								break;
				case PORTB :	CLR_BIT(HWREG(DDRB_REG),DIO->Pin);
								SET_BIT(HWREG(PORTA_REG),DIO->Pin);
								break;
				case PORTC :	CLR_BIT(HWREG(DDRC_REG),DIO->Pin);
								SET_BIT(HWREG(PORTA_REG),DIO->Pin);
								break;
				case PORTD :	CLR_BIT(HWREG(DDRD_REG),DIO->Pin);
								SET_BIT(HWREG(PORTA_REG),DIO->Pin);
								break;
				default    :	break;
			}		
		}
		else{}
	}
	else
	{
		if( DIO->Port >= NUM_OF_PORTS )
		{
			DIO->Error = Error_WRONG_PORT;
		}
		else if( DIO->Pin >= NUM_OF_PINS )
		{
			DIO->Error = Error_WRONG_PIN;
		}
		else{}
	}
}
void	DIO_voidSetPinValue(DioConfig *DIO )	//this o/p will high or low
{
	/*		Range Check				*/
	if( (DIO->Port < NUM_OF_PORTS) && (DIO->Pin < NUM_OF_PINS) )
	{
		if(DIO->Value == HIGH)
		{
			switch(DIO->Port)
			{
				case PORTA :	SET_BIT(HWREG(PORTA_REG),DIO->Pin);	break;
				case PORTB :	SET_BIT(HWREG(PORTB_REG),DIO->Pin);	break;
				case PORTC :	SET_BIT(HWREG(PORTC_REG),DIO->Pin);	break;
				case PORTD :	SET_BIT(HWREG(PORTD_REG),DIO->Pin);	break;
				default    :										break;
			}
		}
		else if (DIO->Value == LOW)
		{
			switch(DIO->Port)
			{
				case PORTA :	CLR_BIT(HWREG(PORTA_REG),DIO->Pin);	break;
				case PORTB :	CLR_BIT(HWREG(PORTB_REG),DIO->Pin);	break;
				case PORTC :	CLR_BIT(HWREG(PORTC_REG),DIO->Pin);	break;
				case PORTD :	CLR_BIT(HWREG(PORTD_REG),DIO->Pin);	break;
				default    :										break;
			}			
		}
		else{}
				
	}
	else
	{
		if( DIO->Port >= NUM_OF_PORTS )
		{
			DIO->Error = Error_WRONG_PORT;
		}
		else if( DIO->Pin >= NUM_OF_PINS )
		{
			DIO->Error = Error_WRONG_PIN;
		}
		else{}
	}
}

u8		DIO_u8GetPinValue(DioConfig *DIO)		//this i/p is high or low
{
	u8 Local_u8Value = 0xFF;		//Initial value, it will be edited
	/*		Range Check				*/
	if( (DIO->Port < NUM_OF_PORTS) && (DIO->Pin < NUM_OF_PINS) )
	{
		DIO->Error = NO_ErrorS;	//User entered a valid PORT name and PIN number
		
		switch(DIO->Port)
		{
			case PORTA :	Local_u8Value	=	GET_BIT(HWREG(PINA_REG),DIO->Pin);	break;
			case PORTB :	Local_u8Value	=	GET_BIT(HWREG(PINB_REG),DIO->Pin);	break;
			case PORTC :	Local_u8Value	=	GET_BIT(HWREG(PINC_REG),DIO->Pin);	break;
			case PORTD :	Local_u8Value	=	GET_BIT(HWREG(PIND_REG),DIO->Pin);	break;
			default    :															break;
		}		
	}	
	else
	{
		if( DIO->Port >= NUM_OF_PORTS )
		{
			DIO->Error = Error_WRONG_PORT;
		}
		else if( DIO->Pin >= NUM_OF_PINS )
		{
			DIO->Error = Error_WRONG_PIN;
		}
		else{}
	}
	
	return Local_u8Value ;
}

void	DIO_voidSetPortDirection(DioConfig *DIO) //this port will be used as i/p or o/p
{
	/*		Range Check				*/
	if( (DIO->Port < NUM_OF_PORTS) )
	{
		switch(DIO->Port)
		{
			case PORTA :	HWREG(DDRA_REG) = DIO->Direction;	break;
			case PORTB :	HWREG(DDRB_REG) = DIO->Direction;	break;
			case PORTC :	HWREG(DDRC_REG) = DIO->Direction;	break;
			case PORTD :	HWREG(DDRD_REG) = DIO->Direction;	break;
			default    :										break;
		}	
	}
	else
	{
		if( DIO->Port >= NUM_OF_PORTS )
		{
			DIO->Error = Error_WRONG_PORT;
		}
		else if( DIO->Pin >= NUM_OF_PINS )
		{
			DIO->Error = Error_WRONG_PIN;
		}
		else{}
	}
}
void	DIO_voidSetPortValue(DioConfig *DIO)        //this o/p port will high or low
{
	/*		Range Check				*/
	if( (DIO->Port < NUM_OF_PORTS) )
	{
		switch(DIO->Port)
		{
			case PORTA :	HWREG(PORTA_REG) = DIO->Value;	break;
			case PORTB :	HWREG(PORTB_REG) = DIO->Value;	break;
			case PORTC :	HWREG(PORTC_REG) = DIO->Value;	break;
			case PORTD :	HWREG(PORTD_REG) = DIO->Value;	break;
			default    :									break;
		}
	}
	else
	{
		if( DIO->Port >= NUM_OF_PORTS )
		{
			DIO->Error = Error_WRONG_PORT;
		}
		else if( DIO->Pin >= NUM_OF_PINS )
		{
			DIO->Error = Error_WRONG_PIN;
		}
		else{}
	}
}