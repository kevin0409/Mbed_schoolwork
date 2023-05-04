#include "mbed.h"
#include <cstdlib>
#define LED_PINs 9

BusOut leds(D4,D5,D6,D7,D8,D9,D10,D11,D12);
// main() runs in its own thread in the OS
int main()
{
    leds = 0x1FF;
    while (true) {
        leds = rand();
        wait_us(100000);
    }
}

