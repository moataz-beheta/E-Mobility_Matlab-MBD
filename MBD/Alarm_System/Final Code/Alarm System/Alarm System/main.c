/*
 * Alarm System.c
 *
 * Created: 12/3/2022 1:09:25 PM
 * Author : Moataz Beheta
 */ 

#include <avr/io.h>

int main(void)
{
	ADC_Init		();
	Alarm_System_initialize();
    /* Replace with your application code */
    while (1) 
    {
		Alarm_System_step();
    }
}

