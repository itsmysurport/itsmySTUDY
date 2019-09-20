#include <Wire.h>                        // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 1602 I2C용 라이브러리
#include <AFMotor.h>          // 서보모터 라이브러리

AF_Stepper motor(48, 2);
LiquidCrystal_I2C lcd(0x27,16,2);     // 접근주소: 0x3F or 0x27 1602 Display

int dust_sensor = A0;   // 미세먼지 핀 번호
int rgb_red = 5;    // rgb 핀 빨간색 핀
int rgb_green = 6;  // rgb핀 녹색 핀
int rgb_blue = 7;  // rgb핀 파란색 핀
 
float dust_value = 0;  // 센서에서 입력 받은 미세먼지 값
float dustDensityug=0;  // ug/m^3 값을 계산
 
int sensor_led = 12;      // 미세먼지 센서 안에 있는 적외선 led 핀 번호
int sampling = 280;    // 적외선 led를 키고, 센서 값을 읽어 들여 미세먼지를 측정하는 샘플링 시간
int waiting = 40;    
float stop_time = 9680;   // 센서를 구동하지 않는 시간

int status1 = 0;

void setup(){
  lcd.init();                     // LCD 초기화
  lcd.backlight();                // 백라이트 켜기
  
  Serial.begin(9600);   // 시리얼 모니터 시작, 속도는 9600
  motor.setSpeed(10);
  motor.release();
  pinMode(sensor_led,OUTPUT); // 미세먼지 적외선 led를 출력으로 설정
  pinMode(4, OUTPUT);
 
  pinMode(rgb_red, OUTPUT);     // 3색 LED 모듈 출력으로 설정, 붉은색
  pinMode(rgb_green, OUTPUT);   // 녹색
  pinMode(rgb_blue, OUTPUT);    // 파란색
}
 
void loop(){
  digitalWrite(sensor_led, LOW);    // LED 켜기
  delayMicroseconds(sampling);   // 샘플링해주는 시간. 
 
  dust_value = analogRead(dust_sensor); // 센서 값 읽어오기
  
  delayMicroseconds(waiting);  // 너무 많은 데이터 입력을 피해주기 위해 잠시 멈춰주는 시간. 
 
  digitalWrite(sensor_led, HIGH); // LED 끄기
  delayMicroseconds(stop_time);   // LED 끄고 대기  
 
  dustDensityug = 20 + (0.17 * (dust_value * (5.0 / 1024)) - 0.1) * 1000;    // 미세먼지 값 계산
  Serial.print("Dust Density [ug/m3]: ");            // 시리얼 모니터에 미세먼지 값 출력
  Serial.print(dustDensityug);
  
  if(dustDensityug <= 30.0){       // 대기 중 미세먼지가 좋음 일 때 파란색 출력
     analogWrite(rgb_red, 0);
     analogWrite(rgb_green, 0);
     analogWrite(rgb_blue, 255);
     Serial.print("   ");
     Serial.println("blue");
      if(status1 == 1)
     {
      Serial.print("A");
      motorRunb();
      status1 = 0;
     }
     
  }else if(30.0 < dustDensityug && dustDensityug <= 80.0){      // 대기 중 미세먼지가 보통 일 때 녹색 출력
     analogWrite(rgb_red, 0);
     analogWrite(rgb_green, 255);
     analogWrite(rgb_blue, 0);
     Serial.print("   ");
     Serial.println("green");
     if(status1 == 1)
     {
      Serial.print("B");
      motorRunb();
      status1 = 0;
     }
  }else if (80.0 < dustDensityug && dustDensityug <= 150.0){    // 대기 중 미세먼지가 나쁨 일 때 노란색 출력
     analogWrite(rgb_red, 255);
     analogWrite(rgb_green, 155);
     analogWrite(rgb_blue, 0);
     Serial.print("   ");
     Serial.println("yellow");
     if(status1 == 0)
     {
      Serial.print("C");
      motorRunn();
      status1 = 1;
     }
  }else{                                                     // 대기 중 미세먼지가 매우 나쁨 일 때 빨간색 출력
     analogWrite(rgb_red, 255);
     analogWrite(rgb_green, 0);
     analogWrite(rgb_blue, 0);    
     Serial.print("   ");
     Serial.println("red");
     if(status1 == 0)
     {
      Serial.print("D");
      motorRunn();
      status1 = 1;
     }
  }
  lcd.setCursor(1,0);             // 2번째, 1라인
  lcd.print("Dust Density : ");            // 시리얼 모니터에 미세먼지 값 출력  
  lcd.setCursor(2,1);             // 3번째, 2라인
  lcd.print(dustDensityug);             // 먼지 출력
  lcd.setCursor(8,1);            // 10번째, 2라인
  lcd.print("[ug/m3]");                 // "[ug/m3] 출력
  
  delay(1000);               // 1초 간격 측정
}

void motorRunn()
{
  motor.step(500, FORWARD, DOUBLE);
      delay(2000);
      motor.release();
 }
void motorRunb()
{
  motor.step(500, BACKWARD, SINGLE);
  delay(2000);
  motor.release();
}
