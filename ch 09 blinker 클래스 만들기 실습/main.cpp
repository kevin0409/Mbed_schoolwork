#include "DigitalOut.h"
#include "PinNames.h"
#include "mbed.h"

class Blinker{
    DigitalOut _led;
    Ticker _tick;
    void blink(){
        _led = !_led;
    }
    public:
    Blinker(PinName pin): _led(pin){
        _led = 0;
    }
    
    void begin(float us){
        _tick.attach_us(callback(this, &Blinker::blink),us);
    }
};
Blinker blink(LED1);
Blinker blink2(D7);

// main() runs in its own thread in the OS
int main()
{
    blink.begin(100000);
    blink2.begin(200000);
    while (true) {
    }
}

