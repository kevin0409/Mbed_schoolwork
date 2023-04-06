#include "PinNameAliases.h"
#include "UnbufferedSerial.h"
#include "mbed.h"

InterruptIn btn(BUTTON1);
DigitalOut led(LED1);
UnbufferedSerial pc(USBTX, USBRX);

char c = '\0';
volatile bool pressed = false;

void onCharReceived(){
    pc.read(&c, 1);
}

void onPressed(){
    pressed = true;
}
int main()
{
    pc.attach(&onCharReceived);
    btn.fall(&onPressed);
    while (true) {
        if (c == '1'){
            c = '\0';
            led = 1;
        }
        else if (c == '0'){
            c = '\0';
            led = 0;
        }
        if(pressed){
            printf("b");
            pressed = false;
        }

    }
}

