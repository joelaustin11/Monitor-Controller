#include "pico/stdlib.h"

// VUmeter.c
#define GPIO_LEFT 26 // GPIO pin for left channel adc input
#define GPIO_RIGHT 27 // GPIO pin for right channel adc input
#define ADC_LEFT 0 // adc module for left channel
#define ADC_RIGHT 1 // adc module for right channel
#define CONVERSION_FACTOR (3.3f / (1 << 12)) // Conversion factor for decibels

// display.c
#define SLEEPTIME 5000


// Function Prototypes 

// VUmeter.c
int decibels(int channel); 

// display.c 
void vu_display(int volts, char value); 

void setup_gpios(void);