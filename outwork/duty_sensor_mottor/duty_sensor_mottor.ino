/*
 * Made by = itsmysurport
 * Programming by = Arduino CC
 */

#include <SoftwareSerial.h> // L293D 모터 드라이브 라이브러리
#include <AFMotor.h>          // 서보모터 라이브러리

AF_DCMotor motor_3(3);     // 모터 1 객체         
AF_DCMotor motor_4(4);     // 모터 2 객체 

#define sampling 280
#define waiting 40
float stop_time = 9680;

int dust_sensor = A0;
int sensor_led = 12;

float dust_value = 0;
float dustDensity=0;


void setup() {
  Serial.begin(9600);
  motor_3.setSpeed(300);    // 모터 1 속도 설정          
  motor_3.run(RELEASE);     // 모터 1 돌리지 않는 상태
  motor_4.setSpeed(300);    // 모터 1 속도 설정          
  motor_4.run(RELEASE);     // 모터 1 돌리지 않는 상태
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
      motor_3.run(FORWARD);
      motor_4.run(FORWARD);
      delay(10000);         //GO 10second
      motor_3.run(RELEASE);
      motor_4.run(RELEASE);
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
      motor_3.run(BACKWARD);
      motor_4.run(BACKWARD);
      delay(10000);         //GO 10second
      motor_3.run(RELEASE);
      motor_4.run(RELEASE);
      state = false;
    }
  }
}
