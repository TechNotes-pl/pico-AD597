/**
 * @file leds.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "../include/leds.h"

const uint8_t green_led_pin = 25;
const uint8_t blue_led_pin = 21;

void leds_init() 
{
    gpio_init(green_led_pin);
    gpio_set_dir(green_led_pin, GPIO_OUT);

    gpio_init(blue_led_pin);
    gpio_set_dir(blue_led_pin, GPIO_OUT);
}

void leds_blink() 
{
        gpio_put(green_led_pin, true);
        gpio_put(blue_led_pin, true);
        sleep_ms(200);
        gpio_put(blue_led_pin, false);
        sleep_ms(800);
        gpio_put(green_led_pin, false);
        sleep_ms(1000);
}