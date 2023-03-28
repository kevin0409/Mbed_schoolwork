#include "Callback.h"
#include "InterruptIn.h"
#include "PinNames.h"
#include "mbed.h"
#include <cstdint>
class CounterUD{
    InterruptIn _upBot, _downBot;
    volatile int _count;
    volatile bool _updated;
    void plus(){
        _count++;
        _updated = true;
        wait_us(10000);
    }
    void minus(){
        _count--;
        _updated = true;
        wait_us(10000);
    }
    public:
    CounterUD(PinName p1, PinName p2): _upBot(p2, PullUp), _downBot(p1, PullUp){
        _count = 0; _updated = false;
        _upBot.fall(callback(this, &CounterUD::plus));
        _downBot.fall(callback(this, &CounterUD::minus));
    }
    int read(){ _updated = false; return _count;}
    bool isUpdated(){return _updated;}

};
// main() runs in its own thread in the OS
CounterUD cnt(D2, D3);

int main()
{
    while (true) {
        if(cnt.isUpdated()){
            printf("count = %3d\n", cnt.read());
            wait_us(100000);
        }
    }
}

