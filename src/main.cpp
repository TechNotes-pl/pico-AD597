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
#include <iostream>
#include <chrono>
#include <thread>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "leds.h"
#include "AD597.h"
#include "one_wire.h"
#include "Menu.h"

using namespace std;


const char* uom = "C deg";

#define MIN_TEMPERATURE -273.0
#define POWER_ON true
#define POWER_OFF false
// Internal pico temperature sensor uses ADC4
#define PICO_TEMP_SENSOR_ADC 4
// I2C data on GP15 - Pin 20 on Pi Pico
#define TEMP_SENSE_GPIO_PIN 15

int main() {

    // Initialize chosen serial port
    stdio_init_all();

    // Initialize LED pin
    leds_init();
 
    // Initialize ADC 
    tc_init(TC1_pin);

    // Enable the onboard temperature sensor. 
    adc_set_temp_sensor_enabled(POWER_ON);

    One_wire one_wire(TEMP_SENSE_GPIO_PIN); 
    one_wire.init();

    // Loop forever
    while (true) {
        // Led blink with delay
        leds_blink( 1000 );

         // Select an ADC input 4 - the onboard temperature sensor.
        adc_select_input(PICO_TEMP_SENSOR_ADC);
        const float conversion_factor = 3.3f / (1 << 12);
        float ADC_Voltage = (float)adc_read() * conversion_factor;
        float temp1 = 27 - (ADC_Voltage - 0.706)/0.001721;
        
        // Get termocouple sensor temperature
        float temp2 = voltage_to_temperature(tc_read());
          
        // Get I2C sensor temperature
        rom_address_t address{};
        one_wire.single_device_read_rom(address);
        //printf(" Device Address: %02x%02x%02x%02x%02x%02x%02x%02x", address.rom[0], address.rom[1], address.rom[2], address.rom[3], address.rom[4], address.rom[5], address.rom[6], address.rom[7]);
        one_wire.convert_temperature(address, true, false);
        float temp3 = one_wire.temperature(address);

        // Report results
        printf("\rBoard temperature: %3.2f %s.", temp1, uom);
        printf("\tTC sensor temperature: %3.2f %s.",temp2, uom);  
        if(temp3 > MIN_TEMPERATURE)
            printf("\tDS18b20 temperature: %3.2f %s", temp3, uom);
        else 
            printf("\tDS18b20 temperature: N/A     ");
    }
}
