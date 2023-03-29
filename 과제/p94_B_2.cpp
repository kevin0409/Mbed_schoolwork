//2.	Nucleo의 A0에서 A5핀의 전압을 0.5초마다 차례로 ADC하여 PC에 16비트 정수로 표시하는 코드를 작성하라. 단, 객체의 배열을 사용한다.

#include "mbed.h"

// A0 ~ A5까지의 아날로그 입력핀 객체를 배열로 선언
AnalogIn adc[] = {A0, A1, A2, A3, A4, A5};

// NUM_ADC_CHANNELS에 배열의 크기 저장
const int NUM_ADC_CHANNELS = sizeof(adc) / sizeof(adc[0]);

int main()
{

    uint16_t value[NUM_ADC_CHANNELS]; // value 배열에 배열의 크기를 저장하고 이를 부호 없는 16비트로 읽음

    while (1) {
        for (int i = 0; i < NUM_ADC_CHANNELS; i++) {
            value[i] = adc[i].read_u16();	//16비트로 읽음
            printf("%u\n", value[i]);
            wait_us(500000); 		// 0.5초 마다
        }
    }
}
