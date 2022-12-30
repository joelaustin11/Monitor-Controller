/**
 * Takes input on 12 bit adc and converts it to dbu
 * dBu is referenced to 0.775 volts.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h" 
#include "hardware/gpio.h"
#include "hardware/adc.h"  
#include "ssd1306.h"
#include "vumeter.h"




int vu_setup(int channel) // 0 Left, 1 Right
// Returns adc output in Volts
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
    else {
        exit(1);
    }

} 

int vu_calc() { // calculates VUs based on adc input
    uint16_t adc_raw_output; 
    int vus;
    adc_raw_output = adc_read(); 
    vus = adc_raw_output * CONVERSION_FACTOR; 
    return vus; 
}


