//1.	가변저항의 회전에 따라 RC 서보모터가 비례적으로 회전하도록 한다. 단, POT의 최소와 최대 회전각도가 RC 서보의 0도와 180도에 대응하도록 한다.

#include "mbed.h"
 
// POT의 최소, 최대 회전각도
const int MIN_POT_ANGLE = 0;   // 0도
const int MAX_POT_ANGLE = 180; // 180도
 
// RC 서보의 최소, 최대 PWM 신호 폭 (단위: us)
const int SERVO_MIN_PULSEWIDTH = 600;  // 0도에 해당하는 펄스 폭 (600us)
const int SERVO_MAX_PULSEWIDTH = 2400; // 180도에 해당하는 펄스 폭 (2400us)
 
// RC 서보 모터를 D9에 할당
PwmOut servo(D9);
 
// POT를 A0에 할당
AnalogIn pot(A0);
 
// RC 서보의 회전각도로부터 PWM 신호 폭을 계산하는 함수
int calculatePulseWidth(int angle) {
    int pulseWidth = ((angle - MIN_POT_ANGLE) * (SERVO_MAX_PULSEWIDTH -SERVO_MIN_PULSEWIDTH)) / (MAX_POT_ANGLE - MIN_POT_ANGLE) + SERVO_MIN_PULSEWIDTH;
    return pulseWidth;
}
 
int main() {
    // PWM 주기 설정 (단위: us)
    servo.period_us(20000); 

    while (1) {
        // POT의 회전각도 측정 (단위: 도)
        int potAngle = (int)(pot.read() * MAX_POT_ANGLE);
 
        // RC 서보의 회전각도 계산 (단위: 도)
        int servoAngle = potAngle;
 
        // RC 서보의 PWM 신호 폭 계산 (단위: us)
        int pulseWidth = calculatePulseWidth(servoAngle);
 
        // RC 서보 모터 제어
        servo.pulsewidth_us(pulseWidth);
 
        wait_us(1000);
    }
}


