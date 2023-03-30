#include "DigitalOut.h"
#include "mbed.h"

Ticker tic, tic2;
DigitalOut led1(LED1);
DigitalOut led2(D7);

void toggle() {
    led1 = !led1;
}
void toggle_2(){
    led2 = !led2;
}


// main() runs in its own thread in the OS
int main()
{
    tic.attach_us(&toggle, 1000000);
    tic2.attach_us(&toggle_2, 2000000);
}


