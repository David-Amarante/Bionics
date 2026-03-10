#include <Arduino.h>
#include <Servo.h>

Servo servo1;  
int pos = 0;

// Função simples para dividir string por "-" e retornar lista
int splitString(String input, String parts[], int maxParts) {
  int partCount = 0;
  int start = 0;
  int end = input.indexOf('-');
  
  while (end != -1 && partCount < maxParts - 1) {
    parts[partCount++] = input.substring(start, end);
    start = end + 1;
    end = input.indexOf('-', start);
  }

  // Última parte
  if (partCount < maxParts) {
    parts[partCount++] = input.substring(start);
  }

  return partCount;
}



void setup() {  
  // Attach the servo to pin 11
  servo1.attach(11);
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  //Message Reader from Serial Port
  if(Serial.available() > 0){
    String input = Serial.readStringUntil('\n');
    input.trim();

    // Usar função simples para dividir por "-"
    String parts[4]; // Lista para até 4 partes
    int numParts = splitString(input, parts, 4);
    
    // Trim cada parte
    for (int i = 0; i < numParts; i++) {
      parts[i].trim();
    }

    if (parts[0] == "UP") {
     pos = servo1.read(); 
     servo1.write(pos + parts[1].toInt());
    }
  }
}
