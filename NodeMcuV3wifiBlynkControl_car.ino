
#define BLYNK_PRINT Serial
#include<Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>




//Motor A
const int inputPin1  = D1;
const int inputPin2  = D0;

//Motor B
const int inputPin3  = D2;
const int inputPin4  = D3;

int EN1 = D6;
int EN2 = D5;

// LED Light Pin
const int Ledpin = 10;

//---------------------------------

char auth[] = "Your Token";

char ssid[] = "Your wifi name";
char pass[] = "Your wifi password";


BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();

 Serial.print("X = ");
 Serial.print(x);
 Serial.print("Y = ");
 Serial.println(y);


 if (y>350)
 {
  Serial.print("forward");
  forward();
 }

 if (y<170)
 {
  Serial.print("backward");
  backward();
  }

  if (x<132)
 {
  Serial.print("left");
  left();
  }

  if (x>380)
 {
  Serial.print("right");
  right();
  }

  if ((y==256) && (x==256))
  {
    Serial.print("stop");
    stop();
    }

  }


BLYNK_WRITE(V2)
{
  int speed = param.asInt();
    analogWrite(EN1, speed);
    analogWrite(EN2, speed);
  }
//-------------------------------

void setup()
{
    pinMode(EN1, OUTPUT);
    pinMode(EN2, OUTPUT);     
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);  
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    pinMode(Ledpin, OUTPUT); 

    Serial.begin(115200);

    Blynk.begin(auth, ssid, pass);
}

void loop()
{

  Blynk.run();
  
}

void left(void)
{
  digitalWrite(inputPin1,HIGH);
  digitalWrite(inputPin2,LOW);
  digitalWrite(inputPin3,HIGH);
  digitalWrite(inputPin4,LOW);

  }


void right(void)
{
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,HIGH);
  digitalWrite(inputPin3,LOW);
  digitalWrite(inputPin4,HIGH);

  }


void stop(void)
{
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,LOW);
  digitalWrite(inputPin3,LOW);
  digitalWrite(inputPin4,LOW);

  }

void backward (void)
{
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,HIGH);
  digitalWrite(inputPin3,HIGH);
  digitalWrite(inputPin4,LOW);

  }

void forward(void)
{
  digitalWrite(inputPin1,HIGH);
  digitalWrite(inputPin2,LOW);
  digitalWrite(inputPin3,LOW);
  digitalWrite(inputPin4,HIGH);

  }
