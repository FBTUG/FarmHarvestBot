#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
Servo servo_5;



void setup(){
    
    pinMode(9,OUTPUT);
    pinMode(9,INPUT);
    pinMode(13,OUTPUT);
    servo_5.attach(5); // init pin
}

void loop(){
    
    digitalWrite(9,0);
    if(((digitalRead(9))==(1))){
        digitalWrite(13,1);
        _delay(0.5);
        digitalWrite(13,0);
        for(int __i__=0;__i__<1;++__i__)
        {
            servo_5.write(26); // write to servo
            _delay(1.3);
            servo_5.write(145); // write to servo
            _delay(1);
        }
    }else{
        digitalWrite(13,0);
        servo_5.write(145); // write to servo
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

