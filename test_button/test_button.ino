#include <CapacitiveSensor.h>
#include <Servo.h>

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;

Servo myservo;

CapacitiveSensor  cs_2_4 = CapacitiveSensor(2,4); //sensor between 4 and 2

int led = 12;
int pos = 0;

void setup() {

pinMode(led, OUTPUT);
pinMode(photocellPin, INPUT);

Serial.begin(9600);

myservo.attach(9);
}



void loop(){
  photocellReading = analogRead(photocellPin);  
  //Serial.print(photocellReading);
  //Serial.print("\n");

  if(Serial.available()){
    char ledState = Serial.read();
    if (ledState == '1'){
      digitalWrite(led, HIGH);
      }
    if (ledState == '0'){
      digitalWrite(led, LOW);
      }

    
    }


      long sensor = cs_2_4.capacitiveSensor(30);

      Serial.print(sensor);
      Serial.print("\n");
      delay(100);

   if (photocellReading<10){
        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
        
   if(photocellReading>10){
    pos = 120;
    myservo.write(pos);
    }
        
  }  }  }
      

 
    

  

