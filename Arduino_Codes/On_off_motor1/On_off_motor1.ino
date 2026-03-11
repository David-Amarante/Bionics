char comando;

void setup() {
  pinMode(11, OUTPUT);//Pin do motor
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    
    comando = Serial.read();

    if (comando == 'w') {
      Serial.println("Moving");
      analogWrite(11, 180);//pwm para o motor
    }

    if (comando == 's') {
      Serial.println("Stop");
      analogWrite(11, 0);
    }

  }
}