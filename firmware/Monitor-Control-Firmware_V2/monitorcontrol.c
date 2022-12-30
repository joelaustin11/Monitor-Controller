/**
 * Main C file for Monitor Controller logic on RP2040 chip
*/
#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/spi.h"
#include "pico/time.h"
#include "PGA2310/PGA2310.h"
#include "VUmeter/vumeter.h"
#include "VUmeter/ssd1306.h"


#define SLEEPTIME 5000
  



int main() {

    setup_gpios(); 

    // setup display
    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);

    vu_setup(0); 

    while (true) {
        int volts = vu_calc(); 
        meter_display(&disp, volts);
    }
    
}