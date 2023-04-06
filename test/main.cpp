#include "SerialBase.h"
#include "mbed.h"

// main() runs in its own thread in the OS
Serial pc(USBTX, USBRX)

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

