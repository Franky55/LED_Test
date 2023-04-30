#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "LED.h"



bool s_led_state = true;


extern "C" void app_main(void)
{

  LED DEL(48);

    while (1) {
        DEL.Set_RGB(250, 0, 0);
        vTaskDelay(50);
        DEL.Set_RGB(0, 250, 50);
        vTaskDelay(50);

    }
}