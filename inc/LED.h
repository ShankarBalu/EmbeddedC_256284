#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED
/**
 * @file LED.h
 * @author T.M.B.Shankar Balu
 * @brief This file is for initializing the pins for the switches and LEDS and functions for operating the LED
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<avr/io.h>

//Defining macros
#define SEAT_SWITCH PD0
#define HEAT_SWITCH PD1
#define SWITCHES_STATUS PIND

/**
 * @brief Function for switching on the LED
 * 
 */
void LED_ON();

/**
 * @brief Function for switching off the LED
 * 
 */
void LED_OFF();

/**
 * @brief Function for initializing the switches and LED
 * 
 */
void LED_SWITCH_INIT();


#endif // LED_H_INCLUDED
