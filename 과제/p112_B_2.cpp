//2. pb1과 pb2라는 2개의 푸시 버튼을 사용하여 하나는 카운트 값을 증가시키고 나머지는 카운트 값을 0으로 초기화 하도록하는 CounterR 클래스를 설계하고 코딩한다. 단, 이 클래스를 테스트 할 수 있는 main 함수 코드도 작성한다.



#include "mbed.h"

class CounterR {
public:
    CounterR(PinName pb1, PinName pb2) : pb1_(pb1), pb2_(pb2), count_(0) { // count변수의 초기화를 위해 count_(0) 사용
        pb1_.mode(PullUp);              //pb1, pb2를 pullup으로 설정
        pb2_.mode(PullUp);
        pb1_.fall(callback(this, &CounterR::increment));    //pb1은 count 증가 함수 콜백
        pb2_.fall(callback(this, &CounterR::reset));        //pb2은 count 초기화 함수 콜백
    }
    
    int getCount() const {      // count_ 반환
        return count_;
    }
    
private:
    void increment() {          // count_ 증가
        count_++;
    }
    
    void reset() {              // count_초기화
        count_ = 0;
    }

    DigitalIn pb1_;
    DigitalIn pb2_;
    volatile int count_;
};

int main() {
    CounterR counter(PB_1, PB_2);
    
    while(1) {
        printf("count: %d\n", counter.getCount());
        wait_us(500000); // 0.5초 대기
    }
}