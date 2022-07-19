/**
 * @file input.c
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
#include "input.h"

const uint8_t input_pin = 20;

void input_init()
{
    gpio_init(input_pin);
    gpio_set_dir(input_pin, GPIO_IN);
    gpio_pull_up(input_pin);
    
}

int input_read()
{
    int result = gpio_get(input_pin);
    return result;
}