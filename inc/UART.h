#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED
/**
 * @file UART.h
 * @author T.M.B.Shankar Balu
 * @brief This header file is for using UART communication
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief This function is for initializing the USART module
 * 
 */
void USARTInit();

/**
 * @brief This function is for transmitting a value through USART
 * 
 * @param data 
 */
void USARTWriteValue(uint8_t data);

/**
 * @brief This function is for sending the apropriate temperature value
 * 
 * @param temperature This function takes the digital value returned from the ADC as argument
 */
void sendtemperature(uint16_t temperature);

#endif // UART_H_INCLUDED
