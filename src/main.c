#include <stdio.h>
#include "pico/stdlib.h"
#include "AD597.h"

int main() {

    const uint8_t green_led_pin = 25;
    const uint8_t blue_led_pin = 21;
    const uint8_t input_pin = 20;

    // Initialize LED pin
    gpio_init(green_led_pin);
    gpio_set_dir(green_led_pin, GPIO_OUT);

    gpio_init(blue_led_pin);
    gpio_set_dir(blue_led_pin, GPIO_OUT);

    gpio_init(input_pin);
    gpio_set_dir(input_pin, GPIO_IN);
    gpio_pull_up(input_pin);
    int x = gpio_get(input_pin);

    // Initialize chosen serial port
    stdio_init_all();

    printf("Hello, world!\n");
   
    // Loop forever
    while (true) {

        // Blink LED
        printf("Blinking!\r\n");
        gpio_put(green_led_pin, true);
        gpio_put(blue_led_pin, true);
        sleep_ms(200);
        gpio_put(blue_led_pin, false);
        sleep_ms(800);
        gpio_put(green_led_pin, false);
        sleep_ms(1000);
    }
}