#include "mbed.h"

// main() runs in its own thread in the OS
PwmOut pwm(D7);

int main()
{
    int count = 0;
    pwm.preiod_us(25);
    while (true) {
        pwm = count/100.;
        count++;
        count%=101;
        wait_us(100);
    }
}

