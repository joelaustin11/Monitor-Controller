#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/spi.h"
#include "PGA2310.h"

void pga2310_spi_setup() {
    // Frequency of transfer logic analyzer must be double
    int baud = 100000; 
    // SPI inistalization
    spi_init(spi_default, baud); 
    spi_set_format(spi_default, 16, SPI_CPOL_1 , SPI_CPHA_0, SPI_MSB_FIRST);

    // Sets SPI pins 
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);

    // Sets LED pins for tests
    gpio_init(LED_PIN16); 
    gpio_set_dir(LED_PIN16, GPIO_OUT); 
    gpio_init(LED_PIN25); 
    gpio_set_dir(LED_PIN25, GPIO_OUT); 
} 

void pga2310_write(uint8_t right, uint8_t left) {
    const uint16_t pga_frame = (right << 8) | left; // Bit shift left and right values together into 16 bit word
    // Put value in buffer array
    uint16_t buffer[1];
    buffer[0] = pga_frame; 
    // Write to SPI
    spi_write16_blocking(spi_default, buffer, 1);
}
