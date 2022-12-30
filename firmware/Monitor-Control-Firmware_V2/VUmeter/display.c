#include "vumeter.h"
#include "ssd1306.h"


// Function prototypes only for this .c file



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