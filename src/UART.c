#include<avr/io.h>
#include "UART.h"
/**
 * @file ADC.c
 * @author T.M.B.Shankar Balu
 * @brief This file is the source file for UART operations
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Macro definition
#define ubrr_value 103

void USARTInit()
{
    //Setting the baud rate
    UBRR0H=(ubrr_value>>8)&0x00ff;
    UBRR0L=ubrr_value;
    //Setting the size as 8 bit
    UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
    //Enabling the transmitter and receiver
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void USARTWriteValue(uint8_t data)
{
    //Waiting until the transmitter is ready
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //Empty loop
    }
    //Writing data to USART buffer
    UDR0=data;
}

void sendtemperature(uint16_t temperature)
{
    if(temperature>=0&&temperature<210)
        USARTWriteValue(20);
    else if(temperature>=210&&temperature<510)
        USARTWriteValue(25);
    else if(temperature>=510&&temperature<710)
        USARTWriteValue(29);
    else
        USARTWriteValue(33);
}
