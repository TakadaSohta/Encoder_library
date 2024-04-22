#ifndef Encoder_AHLab_h
#define Encoder_AHLab_h

#include <Arduino.h>

class Encoder {
public:
    Encoder(int pinA = 21, int pinB = 22); // デフォルト引数の設定

    void setupEncoder();
    static void encoderISR();
    static void encoderISR2();
    static Encoder* instance;  // 静的インスタンスへのポインタ

    int getEncPosition() const { return enc_position; }
    int getEncDirection() const { return enc_direction; }
    double getEncDegree() const { return enc_degree; }

private:
    int ENC_A;
    int ENC_B;
    static volatile int enc_position; // ISR内で変更される変数はstatic volatileにする
    static volatile int enc_direction;
    static volatile double enc_degree;
};

#endif
