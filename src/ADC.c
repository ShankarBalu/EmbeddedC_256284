#include<avr/io.h>
#include "ADC.h"
/**
 * @file ADC.c
 * @author T.M.B.Shankar Balu
 * @brief This file is the source file for ADC operations
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


void ADC_INIT()
{
    //For getting a resolution of 1024,making Aref=Vcc
    ADMUX=(1<<REFS0);
    //Enabling the ADC and setting prescaler of 128
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
    //Initalizing the mux to take value from channel ch
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Starting the coversion
    ADCSRA|=(1<<ADSC);
    //Waiting for conversion to get over
    while(!(ADCSRA&(1<<ADIF)));
    //Clearing ADIF by setting it to 1 as mentioned in the datasheet
    ADCSRA|=(1<<ADIF);
    //Returning the converted value from the ADC register
    return(ADC);
}
