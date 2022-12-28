#include "pico/stdlib.h"


// Data buffer LEFT CHANNEL 
#define LEFT_ADDR       0x20000000
#define READ_LEFT()     (*(volatile uint32_t *)LEFT_ADDR)
#define WRITE_LEFT(val) ((*(volatile uint32_t *)LEFT_ADDR) = (val))
// Data buffer RIGHT CHANNEL
#define RIGHT_ADDR       0x20000004
#define READ_RIGHT()     (*(volatile uint32_t *)RIGHT_ADDR)
#define WRITE_RIGHT(val) ((*(volatile uint32_t *)RIGHT_ADDR) = (val))
// PGA2310data.S output address
#define OUT_ADDR       0x20000008
#define READ_OUT()     (*(volatile uint32_t *)OUT_ADDR)
// Test LED pins
#define LED_PIN16 16 
#define LED_PIN25 25 


// Function prototypes
void pga2310_spi_setup();

void pga2310_write(uint8_t right, uint8_t left);





