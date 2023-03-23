#include "mbed.h"

// main() runs in its own thread in the OS
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalIn but(BUTTON1);

int main()
{
    led1 = 1;
    while (true) {
        if(!but){
            led1 =! led1;
            led2 =! led2;
            wait_us(200);
        }
    }
}

