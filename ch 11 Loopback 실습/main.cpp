
#include "mbed.h"

UnbufferedSerial pc(USBTX, USBRX);

int main() {
    printf("Loop back program start!\n");
    
    while(1) {
        char list[100];
        if(pc.read(&list, 1)) {
            pc.write(&list, 1);
        }
        wait_us(10000);
    }
}

