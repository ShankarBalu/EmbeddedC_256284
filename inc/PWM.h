#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED
/**
 * @file PWM.h
 * @author T.M.B.Shankar Balu
 * @brief This header file is for generating PWM signals
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief This function generates PWM signal with the corresponding duty cycle as per the temperature
 * 
 * @param temperature The temperature obtained from ADC is passed as input here
 */

void PWM(uint16_t temperature);

#endif // PWM_H_INCLUDED
