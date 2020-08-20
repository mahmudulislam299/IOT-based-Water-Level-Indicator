
#define TRIGGER D0
#define ECHO    D2
#define buzzer  D4

// NodeMCU Pin D0 > TRIGGER | Pin D2 > ECHO

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = " fZZ3GGx7Ak1J2sbi7xEGPMGxo2lrLQ6o";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ks.main";
char pass[] = "";
int distanceVals[8] = {5, 10, 15, 20, 25, 30, 35, 300};
void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.println("Centimeter: ");
  Serial.print(distance);
  
  Blynk.virtualWrite(V8, distance);
  delay(200);
  Blynk.run();

 Serial.print(distance);
 Serial.println("Centimeter:");
  Blynk.virtualWrite(V9, distance);
  delay(100);
  Blynk.run();
  

   if (distance <=distanceVals[0]) {
    Blynk.virtualWrite(V0, 255);

}
  else {
    Blynk.virtualWrite(V0, 0);
  }

 if (distance <= distanceVals[1]) {
    Blynk.virtualWrite(V1, 255);
}
  else {
    Blynk.virtualWrite(V1, 0);
  }

   if (distance <= distanceVals[2]) {
    Blynk.virtualWrite(V2, 255);
    
}
  else {
    Blynk.virtualWrite(V2, 0);
  }
//*************************************************************************
  if (distance > distanceVals[0] && distance <= distanceVals[2]) {
    digitalWrite(buzzer,HIGH);  
    delay(300);
    digitalWrite(buzzer,LOW);
    delay(300); 
    }
if (distance >0 && distance <= distanceVals[0]) {
    digitalWrite(buzzer,HIGH);  
    delay(150);
    digitalWrite(buzzer,LOW);
    delay(150); 
    }


//****************************************

   if (distance <= distanceVals[3]) {
    Blynk.virtualWrite(V3, 255);
}
  else {
    Blynk.virtualWrite(V3, 0);
  }

   if (distance <= distanceVals[4]) {
    Blynk.virtualWrite(V4, 255);
}
  else {
    Blynk.virtualWrite(V4, 0);
  }
  
   if (distance <= distanceVals[5]) {
    Blynk.virtualWrite(V5, 255);
}
  else {
    Blynk.virtualWrite(V5, 0);
  }

   if (distance <= distanceVals[6]) {
    Blynk.virtualWrite(V6, 255);
}
  else {
    Blynk.virtualWrite(V6, 0);
  }


   if (distance <= distanceVals[7]) {
    Blynk.virtualWrite(V7, 255);
}
  else {
    Blynk.virtualWrite(V7, 0);
  }
  
  
  
}

