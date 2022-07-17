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

const char* uom = "C deg";

#define POWER_ON true
#define POWER_OFF false

int main() {

    // Initialize chosen serial port
    stdio_init_all();

    // Initialize LED pin
    leds_init();
 
    // Initialize ADC 
    tc_init(TC1_pin);

    // Enable the onboard temperature sensor. 
    adc_set_temp_sensor_enabled(POWER_ON);

    // Loop forever
    while (true) {

        // puts("\nBlinking... ");
        leds_blink( 2000 );

        // Get sensor temperature
        printf("\rSensor temperature: %3.1f %s.", voltage_to_temperature(tc_read()), uom);    

        // Select an ADC input. Input 4 is the onboard temperature sensor.
        adc_select_input(4);

        const float conversion_factor = 3.3f / (1 << 12);
        float ADC_Voltage = (float)adc_read() * conversion_factor;
        float temp = 27 - (ADC_Voltage - 0.706)/0.001721;

        printf(" Board temperature: %3.2f %s.", temp, uom);

    }
}
