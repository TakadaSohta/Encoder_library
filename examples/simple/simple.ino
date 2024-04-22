#include "Encoder_AHLab.h"

Encoder myEncoder; // エンコーダーのピン番号を指定

void setup() {
    myEncoder.setupEncoder();
    Serial.begin(115200);
}

void loop() {
    Serial.print("Position: ");
    Serial.print(myEncoder.getEncPosition());
    Serial.print(", Direction: ");
    Serial.print(myEncoder.getEncDirection());
    Serial.print(", Degree: ");
    Serial.println(myEncoder.getEncDegree());
}
