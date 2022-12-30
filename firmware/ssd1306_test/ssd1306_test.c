#include "ssd1306.h"    
#include "pico/time.h"
#include <stdlib.h>
#include <time.h>

void setup_gpios(void);

void meter_display(ssd1306_t *disp, int level);

void level_display(ssd1306_t *disp, char level);

void main() {

    srand(time(NULL)); 

    
     
    setup_gpios(); 

    // setup display
    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);

    while (1) {
        meter_display(&disp, 55); 
        ssd1306_clear(&disp); 

    }
}

void setup_gpios(void) {
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}

void meter_display(ssd1306_t *disp, int level) { 
    ssd1306_draw_square(disp, 0, 0, level, 64); 
    ssd1306_show(disp); 
}
void level_display(ssd1306_t *disp, char level){ 
    const char x = level; 
    const char *words[] = {"2.5"};
    ssd1306_draw_string(disp, 25, 25, 4, words[0]);
    ssd1306_show(disp);
}