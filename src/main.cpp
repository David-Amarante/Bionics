#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
    pinMode(11,OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    for (int i = 0; i < 20; i++) {  // corrigido o for
        analogWrite(11, i*10);    // envia o valor para o pino 11
        Serial.println("out");     // mostra o valor no Serial Monitor
        delay(100);                    // pequeno atraso para ver a mudança
    }
}
