#include "PinNameAliases.h"
#include "mbed.h"
#include "Adafruit_SSD1306.h"
I2C i2c(I2C_SDA, I2C_SCL);

Adafruit_SSD1306_I2c my0led(i2c, D4, 0x78, 32, 128);


// main() runs in its own thread in the OS
int main()
{   
    int16_t x = 0;
    float inc = 0.0f, force = 1.0f;
    i2c.frequency(400000);
    my0led.begin();
    my0led.printf("Hello world\r\n");
    my0led.display();
    while (true) {
        my0led.fillRect(0, 19, 128, 12, 0);
        my0led.drawRect(x, 20, 10, 10 ,1);
        my0led.display();
        inc+=0.1f*force; x+=inc;
        if (x>118 || x<0){
            force =-force;
            inc = 0.0f;
            wait_us(10000);
        }

    }
}

