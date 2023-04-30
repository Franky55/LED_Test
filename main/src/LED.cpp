#include <stdio.h>
#include "LED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"

LED::LED(int gpio)
{
    GPIO = gpio;


    led_strip_config_t strip_config = { .strip_gpio_num = GPIO, .max_leds = 1,};
    led_strip_rmt_config_t rmt_config = { .resolution_hz = 10 * 1000 * 1000, };
    
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &Led_strip));

    /* Set all LED off to clear all pixels */
    led_strip_clear(Led_strip);

}




/// @brief Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color
/// @param r 
/// @param g 
/// @param b 
void LED::Set_RGB(int r, int g, int b)
{
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    led_strip_set_pixel(Led_strip, 0, r, g, b);
    /* Refresh the strip to send data */
    led_strip_refresh(Led_strip);
}
