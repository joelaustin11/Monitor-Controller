/**
 * C Program to set PIO in action   
*/  

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "PGA2310.pio.h"


const uint CS0 = 0; // CHIP SELECT PIN
const uint SDI1 = 1; // DATA PIN
const uint SCLK2 = 2; // SERIAL CLOCK INPUT PIN 


extern void PGA2310_start(PIO pio, uint sm, uint offset, uint setpin, uint outpin, uint sidesetpin, uint freq); 

int main() {
    PIO pio = pio0; 
    uint offset = pio_add_program(pio, &PGA2310_program); 

    PGA2310_start(pio, 0, offset, CS0, SDI1, SCLK2, 5); // Start the state machine

    

}

extern void PGA2310_start(PIO pio, uint sm, uint offset, uint setpin, uint outpin, uint sidesetpin, uint freq) {
    PGA2310_program_init(pio, sm, offset, setpin, outpin, sidesetpin); // Sends options to .pio file
    pio_sm_set_enabled(pio, sm, true); // Enables pio state machine

}