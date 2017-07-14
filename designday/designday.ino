#include <SoftwareSerial.h>

SoftwareSerial Genotronex(6,7);
int lmotorSpeedPin = 11;
int rmotorSpeedPin = 3;

int currentSensor = A0;
int current = 0;

String serialInput;
int speedInput;

int desiredRPM;

// read RPM
int half_revolutions = 0;
int i=0;
int rpm = 0;
int rotational_speed;
unsigned long lastmillis = 0;
 
int BluetoothData; // the data given from Computer
  
 // this code will be executed every time the interrupt 0 (pin2) gets low.
 void rpm_fan(){
  half_revolutions++;
 }

 void setMotors(int speedInput) {
   analogWrite(lmotorSpeedPin, speedInput);
   analogWrite(rmotorSpeedPin, speedInput);
 }
 
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(lmotorSpeedPin,OUTPUT); 
  pinMode(rmotorSpeedPin,OUTPUT); 
//  desiredRPM = -1;
//  attachInterrupt(digitalPinToInterrupt(2), rpm_fan, FALLING);

  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
}

void loop() {
//  Handle any serial inputs
  if (Serial.available() > 0) {
    serialInput = Serial.readStringUntil(' ');
    if (serialInput == "start") {
      speedInput = Serial.parseInt();
      setMotors(speedInput);
      Serial.print("starting motor with speed ");
      Serial.println(speedInput);
      desiredRPM = -1;
    }
    
    if (serialInput == "stop") {
      setMotors(0);
      desiredRPM = -1;
    }

    if (serialInput == "setrpm") {
      desiredRPM = Serial.parseInt();
      speedInput = desiredRPM/100;
      setMotors(speedInput);
    }

  }

  current = analogRead(currentSensor);
  // put your main code here, to run repeatedly:
  if (Genotronex.available() > 0){
    serialInput = Genotronex.readStringUntil(' ');
    if (serialInput == "start") {
      speedInput = Genotronex.parseInt();
      setMotors(speedInput);
      Genotronex.print("starting motor with speed ");
      Genotronex.println(speedInput);
      desiredRPM = -1;
    }
    
    if (serialInput == "stop") {
      setMotors(0);
      desiredRPM = -1;
    }

  }
}
