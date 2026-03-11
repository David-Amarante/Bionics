// C++ code
#include <Servo.h>

Servo myservo;

int potPin = A0; //Pin do potenciometro
float valor = 0; 

//Servo Values
float current_pos;
float ratio;


void setup()
{
  pinMode(A0, INPUT);
  pinMode(11,OUTPUT);//Pin do servo
  Serial.begin(9600);
  myservo.attach(11);
}

void loop()
{  
  valor = analogRead(potPin);    

  Serial.println(valor); 
  
  delay(100);

  
  myservo.write((valor-300)/(1023-300)*180);
  
}