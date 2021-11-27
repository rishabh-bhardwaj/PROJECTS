#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h> 
#define trig D3
#define led D2
#define echo D5

bool pinValue = 0;
#define buzz D0
BlynkTimer timer;
void setup() 
{ 
  char auth[] = "Nx9p2l7jYuU66b1qBd87HbXHQAGv-Jxi";
  char ssid[] = "vivo 1902";//Enter your WIFI nameZ
  char pass[] = "rishabh12345";
  pinMode(led,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1L, Wlevel);
  digitalWrite(led, HIGH);
  
}
BLYNK_WRITE(V0) {
  pinValue = param.asInt();
}
void loop() 
{  
  Blynk.run();
  timer.run();
}
void Wlevel() {
    
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo,1);
  long cm = t *0.034/ 2;
  Serial.println(cm);
  if(cm<2){
    digitalWrite(buzz,1);
    
    //digitalWrite(led,0);
    }
    else {digitalWrite(buzz,0);
       
       //   digitalWrite(led,1);
}
  if (pinValue == 0) 
    {
    digitalWrite(led, LOW);
    digitalWrite(buzz,0);
    }
    else
      if (pinValue == 1) 
      {
          digitalWrite(led, HIGH);
          
      }
 
  Blynk.virtualWrite(V1, cm);
  Serial.println(cm);
}
