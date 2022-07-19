/**
 * @file AD597.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "hardware/adc.h"

#define TC1_pin 26
 
void tc_init(uint adc_pin);

float tc_read();

float voltage_to_temperature(float voltage);

#ifdef __cplusplus
}
#endif