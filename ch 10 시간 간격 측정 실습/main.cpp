#include "mbed.h"

// main() runs in its own thread in the OS
Timer watch;

int main()
{
    while (true) {
        watch.reset();
        watch.start();
        printf("PRINT 15BYTES! \n");
        watch.stop();
        printf("It takes about %5u us\n", watch.read_us());
        wait_us(1000000);

    }
}

