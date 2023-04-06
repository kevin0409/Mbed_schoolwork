#include "PinNameAliases.h"
#include "UnbufferedSerial.h"
#include "mbed.h"

// main() runs in its own thread in the OS
UnbufferedSerial pc(USBTX, USBRX);
DigitalOut led(LED1);
char buf;
void seriralEvent(){
    if (pc.readable()){
        pc.read(&buf, 1);
        pc.write(&buf, 1);
    }
}
int main()
{
    printf("loop back program start!\n");
    pc.attach(&seriralEvent);
    while (true) {
        led = !led;
        wait_us(100000);

    }
}

