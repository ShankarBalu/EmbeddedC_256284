#include<avr/io.h>
#include "PWM.h"
/**
 * @file PWM.c
 * @author T.M.B.Shankar Balu
 * @brief This file is the source file for PWM operations
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

void PWM(uint16_t temperature)
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01); //For fast PWM with top as 256
    TCCR0B|=(1<<CS01)|(1<<CS00);    //Setting prescaler
    DDRD|=(1<<PD6);
    //Setting compare as per the temperature
    if(temperature>=0&&temperature<210)
        OCR0A=51;
    else if(temperature>=210&&temperature<510)
        OCR0A=102;
    else if(temperature>=510&&temperature<710)
        OCR0A=179;
    else
        OCR0A=243;
}
