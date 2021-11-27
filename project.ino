
#include <Servo.h>
Servo myservo,myservo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);

}
long dur,dis,dis2,dur2;
void loop() {
  digitalWrite(7,LOW);
  delay(2);
   digitalWrite(7,1);
  delay(10);
   digitalWrite(7,LOW);
  
    /*digitalWrite(4,LOW);
  delay(2);
   digitalWrite(4,1);
  delay(10);
   digitalWrite(4,LOW);*/
   dur=pulseIn(6,HIGH);
    dis=dur*0.034/2;
   digitalWrite(4,LOW);
  delay(2);
   digitalWrite(4,1);
  delay(10);
   digitalWrite(4,LOW);
   dur2=pulseIn(5,HIGH);
  
   dis2=dur2*0.034/2;
  if(dis<8||dis2<8)
  {
    digitalWrite(12,1);
    delay(10000);

  }
  else
  {
    digitalWrite(12,0);
  }
  Serial.print("this is distance 1 :");
  Serial.print(dis);
  Serial.print("\n");
  Serial.print("this is distance 2 :");
  Serial.print(dis2);
  Serial.print("\n");
  //delay(3000);
  for (pos = 0; pos <= 45; pos += 1)
  {

    myservo.write(pos); 
    myservo1.write(pos); 
    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos); 
    myservo1.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
