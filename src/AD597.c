#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/AD597.h"


const float AD_voltage_temperature_factor = 100.0;

/**
 * @brief Prepare a GPIO for use with ADC by disabling all digital functions.
 *
 * @param adc_pin The GPIO number to use. Allowable GPIO numbers are 26 to 29 inclusive.
 */
void tc_init(uint adc_pin)
{
    stdio_init_all();

    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(adc_pin);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
}

/**
 * @brief
 *  12-bit conversion, assume max value == ADC_VREF == 3.3 V
 *
 * @return float voltage
 */
float tc_read()
{
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = adc_read();

    return result * conversion_factor;
}

/**
 * @brief Voltage to temperature conversion function
 * 
 * @param voltage 
 * @return float 
 */
float voltage_to_temperature(float voltage)
{
    return voltage * AD_voltage_temperature_factor;
}