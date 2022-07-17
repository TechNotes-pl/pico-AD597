/**
 * @file main.c
 * @author TechNotes.pl
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/AD597.h"
#include "../include/leds.h"

const char* uom = "C deg"

int main() {

    // Initialize chosen serial port
    stdio_init_all();

    // Initialize LED pin
    leds_init();
 
    // Initialize ADC 
    tc_init(TC1_pin);

    // Loop forever
    while (true) {

        // puts("\nBlinking... ");
        leds_blink();

        // Get sensor temperature
        printf("\rSensor temperature: %3.1f %s", voltage_to_temperature(tc_read()), uom);    
    }
}
