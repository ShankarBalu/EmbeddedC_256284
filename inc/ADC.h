#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED
/**
 * @file ADC.h
 * @author T.M.B.Shankar Balu
 * @brief Header file to operate analog to digital converter in AVR ATmega328
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Include files
#include<avr/io.h>

/**
 * @brief Function to inialize the ADC of the microcontroller
 * 
 */
void ADC_INIT();

/**
 * @brief To read a digital value after conversion from the ADC
 * 
 * @param ch This denotes the channel (0-8) of the ADC to which the value is provided
 * @return uint16_t This function returns the digital value that is obtained after conversion
 */
uint16_t ReadADC(uint8_t ch);

#endif // ADC_H_INCLUDED
