#include "DigitalOut.h"
#include "PinNameAliases.h"
#include "mbed.h"
#include <cstdint>
#include "Adafruit_SSD1306.h"
#define REG_SEC (0X00)
#define REG_MIN (0x01)
#define REG_HOUR (0x02)
#define PCF8563_ADDR (0xD0)

I2C myi2c(D14, D15);
I2C i2c(I2C_SDA, I2C_SCL);
DigitalOut myled(LED1);

Adafruit_SSD1306_I2c OLED(myi2c, D2, 0x78, 64,128);

void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
char readByte(uint8_t address, uint8_t subAddress);
uint8_t bcdToDex(uint8_t val);
uint8_t decToBcd(uint8_t val);
void OLED_drawString(char *str);

void OLED_drawString(char *str){
    for(int i = 0;str[i];i++){
        OLED.writeChar(str[i]);
    }
}
void writeByte(uint8_t address, uint8_t regAddress, uint8_t data){
    char data_write[2];
    data_write[0] = regAddress;
    data_write[1] = data;
    i2c.write(address, data_write, 2, 0);
}
char readByte(uint8_t address, uint8_t regAddress){
    char data[1];
    char data_write[1];
    data_write[0] = regAddress;
    i2c.write(address, data_write, 1, 1);
    i2c.read(address, data, 1, 0);
    return data[0];
}
uint8_t bcdToDec(uint8_t val){
    return((val/16)*10 + (val%16));
}
uint8_t decToBcd(uint8_t val){
    return((val/10)*16 + (val%10));
}
// main() runs in its own thread in the OS
int main()
{
    //writeByte(PCF8563_ADDR, REG_SEC, decToBcd(1));
    //writeByte(PCF8563_ADDR, REG_MIN, decToBcd(14));
    //writeByte(PCF8563_ADDR, REG_HOUR, decToBcd(16));
    OLED.clearDisplay();

    OLED.setTextSize(1);
    OLED_drawString("Hello~");
    OLED.display();
    while (true) {
        char s = readByte(PCF8563_ADDR, REG_SEC);
        char m = readByte(PCF8563_ADDR, REG_MIN);
        char h = readByte(PCF8563_ADDR, REG_HOUR);
        printf("Time = %02u:%02u:%02u\n", bcdToDec(h & 0x3F), bcdToDec(m & 0x7F), bcdToDec(s % 0x7F));
        myled = !myled;
        wait_us(1000000);

    }
}

