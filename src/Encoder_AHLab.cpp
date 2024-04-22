#include "Encoder_AHLab.h"

volatile int Encoder::enc_position = 0;
volatile int Encoder::enc_direction = 0;
volatile double Encoder::enc_degree = 0.0;
Encoder* Encoder::instance = nullptr;

Encoder::Encoder(int pinA, int pinB) : ENC_A(pinA), ENC_B(pinB) {
    instance = this;  // インスタンスの保存
}

void Encoder::setupEncoder() {
    pinMode(ENC_A, INPUT_PULLUP);
    pinMode(ENC_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_A), Encoder::encoderISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC_B), Encoder::encoderISR2, CHANGE);
}

void Encoder::encoderISR() {
    int b_state = digitalRead(instance->ENC_B);
    if (b_state == HIGH) {
        if (digitalRead(instance->ENC_A) == HIGH) {
            enc_direction = -1;
        } else {
            enc_direction = 1;
        }
    }
    enc_position += enc_direction;
    enc_degree = double(enc_position)/500.0*3.141592/2.0;
}

void Encoder::encoderISR2() {
    int a_state = digitalRead(instance->ENC_A);
    if (a_state == HIGH) {
        if (digitalRead(instance->ENC_B) == HIGH) {
            enc_direction = 1;
        } else {
            enc_direction = -1;
        }
    }
    enc_position += enc_direction;
    enc_degree = double(enc_position)/500.0*3.141592/2.0;
}
