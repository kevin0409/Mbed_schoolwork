#include "Callback.h"
#include "InterruptIn.h"
#include "PinNamesTypes.h"
#include "Timeout.h"
#include "mbed.h"
class Debounce{
    InterruptIn _btn;
    Timeout _tmo;
    int _interval;
    int _state, _ready;
    void btnISR(){
        if(_ready){
            _ready = 0;
            _tmo.attach_us(callback(this, &Debounce::decide), _interval);
        }
    }
    void decide(){
        _state = 0;
        _ready = 1;
        _tmo.detach();
    }
    public:
    Debounce(PinName pin, int interval = 100000) : _btn(pin){
        _btn.fall(callback(this, &Debounce::btnISR));
        _state = 1;
        _ready = 1;
        _interval = interval;
    }
    int read(){
        int state = _state;
        _state = 1;
        return state;
    }
    operator int(){
        return read();
    }
};
// main() runs in its own thread in the OS
int main()
{
    Debounce dbc(BUTTON1, 10000);
    int cnt = 0;
    while (1) {
        if(!dbc){
            cnt++;
            printf("count = %d\n", cnt);
        }

    }
}

