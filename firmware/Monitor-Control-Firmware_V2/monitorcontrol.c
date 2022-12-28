/**
 * Main C file for Monitor Controller logic on RP2040 chip
*/
#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/spi.h"
#include "pico/time.h"
#include "PGA2310/PGA2310.h"
#include"VUmeter/vumeter.h"


#define SLEEPTIME 5000



int main() {
    
    setup_gpios(); 
    decibels(0);
   

    // Initialize I/O
    stdio_init_all(); 
    printf("tersting\ntewstint");


    // Initialize the SPI functions
    pga2310_spi_setup();
    
    while (true) {
        pga2310_write(128, 128); 
        sleep_ms(3000);
        pga2310_write(50, 50);
        printf("tersting\ntewstint");
    
    }
    
}







