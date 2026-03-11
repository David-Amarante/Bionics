#include <Servo.h>
Servo M1;
Servo M2;
int pos1 =180;
int pos2 = 0;

char comando;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  M1.attach(11);
  M2.attach(10);
  M1.write(180);
  M2.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    
    comando = Serial.read();

    if (comando == 'w') {
      if (pos1 == 180 or pos2 == 0) 
      {
      	Serial.println("Max Move");
      }
      else
      {
        pos1 = pos1 + 10;
        pos2 = pos2 -10;
      	M1.write(pos1);
        M2.write(pos2);
        Serial.println("Move");
      }
    }
    if (comando == 's') {
          if (pos1 == 0 or pos2 == 180) 
      {
      	Serial.println("Max Move");
      }
      else
      {
        pos1 = pos1 - 10;
        pos2 = pos2 + 10;
      	M1.write(pos1);
        M2.write(pos2);
        Serial.println("Move");
      }
  	 }
	}
}