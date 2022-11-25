/*
 * Trigger_Every_5ms.c
 *
 * Created: 11/15/2022 1:46:23 PM
 * Author : Moataz
 */ 

#include <avr/io.h>
#include "util/delay.h"

//#include "Trigger_Every_5ms_Edited.h"
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(5);
		In1();
		
		
    }
}

