#include "vumeter.h"
#include "ssd1306.h"




void setup_gpios(void) {
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}

void vu_display(int volts, char value) { 

    // setup display
    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
    int dummy; 
    dummy = volts; 
    char words[1]; 
    words[1] = value; 

    ssd1306_draw_string(&disp, 8, 24, 2, words);
    //ssd1306_draw_square(&disp, 0, 0, volts, 128); 
    ssd1306_show(&disp); 
    ssd1306_clear(&disp);

}
