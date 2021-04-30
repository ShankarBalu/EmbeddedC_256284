#include<avr/io.h>
#include "LED.h"
/**
 * @file LED.c
 * @author T.M.B.Shankar Balu
 * @brief This file is the source file for GPIO operations
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

void LED_ON()
{
    //Setting the bit
    PORTB|=(1<<PB0);
}

void LED_OFF()
{
    //Clearing the bit
    PORTB&=~(1<<PB0);
}

void LED_SWITCH_INIT()
{
    DDRB|=(1<<PB0);  // Setting the pin as output for LED
    // Setting and configuring the input pins
    DDRD&=~(1<<PD0);  
    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD0);  
    PORTD|=(1<<PD1);
}
