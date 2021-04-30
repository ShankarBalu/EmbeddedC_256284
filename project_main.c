/**
 * @file project_main.c
 * @author T.M.B.Shankar Balu
 * @brief  This is the main program file of the project where all the header file functions are used
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"
#include "ADC.h"
#include "PWM.h"
#include "UART.h"
/**
 * @brief This is the main function of the project
 * 
 */
/* D0 and D1 are the pins to which the buttons(D0-button sensor D1-Heater button) are connected and B0 is the pin to which the LED is connected */
int main(void)
{
    uint16_t temperature=0; //Declaring a variable for storing the digital value from temperature
    //Initializing the GPIO pins
	LED_SWITCH_INIT();
    while(1)
    {   
		//Reading from the SWITCHES
        if(!(SWITCHES_STATUS&(1<<SEAT_SWITCH))&&!(SWITCHES_STATUS&(1<<HEAT_SWITCH)))
        {
            //Making the LED to glow
			LED_ON();
			//Using ADC
            ADC_INIT();
            temperature=ReadADC(0);
			//Generating PWM signal
            PWM(temperature);
            _delay_ms(200);
			//Sending temperature through USART
            USARTInit();
            sendtemperature(temperature);
            _delay_ms(200);
        }
        else
        {
            //Switching off the LED
			LED_OFF();
        }
    }
    return 0;
}
