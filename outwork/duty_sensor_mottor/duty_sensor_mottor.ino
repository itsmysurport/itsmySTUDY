/*
 * Made by = itsmysurport
 * Programming by = Arduino CC
 */

#include <SoftwareSerial.h> // L293D 모터 드라이브 라이브러리
#include <AFMotor.h>          // 서보모터 라이브러리

AF_Stepper motor(20, 2);

int sampling = 280;
int waiting = 40;
float stop_time = 9680;

int dust_sensor = A0;
int sensor_led = 12;

float dust_value = 0;
float dustDensity=0;


void setup() {
  Serial.begin(9600);
  motor.setSpeed(100);
  motor.release();
  pinMode(sensor_led, OUTPUT);
}

void loop() {
  bool state = false;
  digitalWrite(sensor_led, LOW);    //  LED ON
  delayMicroseconds(sampling);      //  Sampling ...

  dust_value = analogRead(dust_sensor);
  delayMicroseconds(waiting);
  
  digitalWrite(sensor_led, HIGH);
  delayMicroseconds(stop_time);

  dustDensity = (0.17 * (dust_value * (5.0 / 1024)) - 0.1) * 1000;

  Serial.println(dustDensity);

  if(dustDensity >= 100.0)
  {
    if(state == false)
    {
      Serial.println("*******");
      Serial.println("WARNING");
      Serial.println("*******");
      motor.step(100, FORWARD, MICROSTEP);
      delay(10000);         //GO 10second
      motor.release();
      state = true;
    }
  }
  else
  {
    if(state)
    {
      Serial.println("*******");
      Serial.println("WARNING OUT");
      Serial.println("*******");
      motor.step(100, BACKWARD, MICROSTEP);
      delay(10000);         //GO 10second
      motor.release();
      state = false;
    }
  }
}
