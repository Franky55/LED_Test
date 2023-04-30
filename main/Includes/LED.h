#include "led_strip.h"


class LED
{
    private:
    led_strip_handle_t Led_strip;
    int GPIO;

    public:
    LED(int GPIO);

    void Set_RGB(int r, int g, int b);

};
