
//#include <BlynkSimpleEsp8266.h>
//#include <ESP8266_Lib.h>
//#include <ESP8266WiFi.h>
#include<BlynkSimpleShieldEsp8266.h>


 
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

  /* Comment this out to disable prints and save space */

//#include <IPSS.h>

int s1, s2, s3, s4;
//IPSS ipss = IPSS(23,34,45,60);     // IPSS(s1,s2,...);

// Initialize the IPSS library
//IPSS ipss = IPSS(s1, s2, s3, s4);  // IPSS(s1,s2,...);
  
#define BLYNK_PRINT Serial

//#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "aab7c08b92b0444d80d56ee085e50f2c";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PIE";
char pass[] = "coopcoop";

// Register virtual pins
int GenSwitch = V0;
int sb1Switch = V1;
int sb2Switch = V2;
int sb3Switch = V3;
int sb4Switch = V4;

// Register LED virtual pins
WidgetLED led0(V10);
WidgetLED led1(V11);
WidgetLED led2(V12);
WidgetLED led3(V13);
WidgetLED led4(V14);

// Physical LED pins
int ledPin1 = 4;
int ledPin2 = 14;
int ledPin3 = 12;
int ledPin4 = 13;
//int ledPin5 = 13;


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
int genSwitchState;
BLYNK_WRITE(V0)
{
  genSwitchState = param.asInt();
  if (genSwitchState == 1) {
    Serial.print("Smart Distribution Board Activated");
    led0.on();
  } else {
    Serial.print("Smart Distribution Board deactivated");
    led0.off(); led1.off(); led2.off(); led3.off(); led4.off();
    Blynk.virtualWrite(GenSwitch, 0);
    Blynk.virtualWrite(sb1Switch, 0);
    Blynk.virtualWrite(sb2Switch, 0);
    Blynk.virtualWrite(sb3Switch, 0);
    Blynk.virtualWrite(sb4Switch, 0);

  }
}

BLYNK_WRITE(V1)
{
  int i = param.asInt();
  if (i == 1 && genSwitchState == 1) {
    Serial.print("Relay 1 is on");
    led1.on();
  } else {
    Serial.print("Relay 1 is off");
    led1.off();
  }
  //Blynk.virtualWrite(s1OutputPin, s1);
}

BLYNK_WRITE(V2)
{
  int i = param.asInt();
  if (i == 1 && genSwitchState == 1) {
    Serial.print("Relay 2 is on");
    led2.on();
  } else {
    Serial.print("Relay 2 is off");
    led2.off();
  }
  //Blynk.virtualWrite(s1OutputPin, s1);
}

BLYNK_WRITE(V3)
{
  int i = param.asInt();
  if (i == 1 && genSwitchState == 1) {
    Serial.print("Relay 3 is on");
    led3.on();
  } else {
    Serial.print("Relay 3 is off");
    led3.off();
  }
  //Blynk.virtualWrite(s1OutputPin, s1);
}

BLYNK_WRITE(V4)
{
  int i = param.asInt();
  if (i == 1 && genSwitchState == 1) {
    Serial.print("Relay 4 is on");
    led4.on();
  } else {
    Serial.print("Relay 4 is off");
    led4.off();
  }
//  Blynk.virtualWrite(s1OutputPin, s1);
}

void setup()
{  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  
  // Debug console
  Serial.begin(115200);
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 42, 48),8080);
  while (Blynk.connect() == false) {}

  //ipss.setLoad(50);

  // Turn off all virtual leds
  led1.off();led2.off();led3.off();led4.off();

}

void loop()
{
  Blynk.run();
}
