/*
Takes input on 12 bit adc and converts it to dbu
dBu is referenced to 0.775 volts.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h" 
#include "hardware/gpio.h"
#include "hardware/adc.h"   


const int GPIO_LEFT = 26; // GPIO pin for left channel adc input
const int GPIO_RIGHT = 27; // GPIO pin for right channel adc input
const int ADC_LEFT = 0; // adc module for left channel
const int ADC_RIGHT = 1; // adc module for right channel

int decibels(int channel)
// 0 for left, 1 for right
 {
    adc_init(); // Initialize adc module

    // Determines which channel the decibel information is coming from
    if (channel == 0) { 
        adc_gpio_init(GPIO_LEFT); 
        adc_select_input(ADC_LEFT);
    }
    else if (channel == 1) {
        adc_gpio_init(GPIO_RIGHT); 
        adc_select_input(ADC_RIGHT); 
    } 
    else
        printf("ERROR: int decibels(int channel)\nValid parameters are\n0 = Left\n1 = Right");
        exit(1);

} 