#include <CapacitiveSensor.h>
CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); //sensor between 4 and 2

//int ledPin = 13;
//int tweetButton = 12;

//int ledState = HIGH;

//int tweetButtonState = LOW;

void setup() {
  /*
pinMode(ledPin, OUTPUT);
pinMode(tweetButton, INPUT);
digitalWrite(ledPin, ledState);
*/
Serial.begin(9600);
}
void loop(){
  /*
  int tweetButtonReading = digitalRead(tweetButton);
  if(tweetButtonReading != tweetButtonState){
    tweetButtonState = tweetButtonReading;
    if(tweetButtonState == HIGH){
      ledState != ledState;
      Serial.println("YES");
      delay(1000);   
      }
      */
      long sensor = cs_4_2.capacitiveSensor(30);

      Serial.print(sensor);
      Serial.print("\n");
      

      delay(250);
    
    }
  
  
  /*if(Serial.available() > 0) {
    char ledState = Serial.read();
    if(ledState == '1'){
      digitalWrite(led, HIGH);
      }
      if(ledState == '0'){
        digitalWrite(led, LOW);
        }
     }*/
     //int buttonState = digitalRead(button); // buttonState
     //if ( buttonState == HIGH){
      //digitalWrite(led, High);
      //Serial.println("YES");
     // delay(500);


