#include "DigitalIn.h"
#include "DigitalOut.h"
#include "mbed.h"

Timeout tmo;
DigitalOut led1(LED1);
DigitalOut led2(D7, 1);
void flip(){
    led2 = !led2;
}

// main() runs in its own thread in the OS
int main()
{
    tmo.attach_us(&flip, 1000000);
    while (true) {
        led1 = !led1;
        wait_us(20000);

    }
}

