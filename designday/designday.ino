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
  pinMode(4, INPUT);
  pinMode(5, INPUT);
//  desiredRPM = -1;
//  attachInterrupt(digitalPinToInterrupt(2), rpm_fan, FALLING);
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
//  if (millis() - lastmillis > 1000) {
//    
//    detachInterrupt(0);//Disable interrupt when calculating
//    rpm = half_revolutions * 60; // Convert frecuency to RPM, note: this works for one interruption per full rotation. For two interrups per full rotation use half_revolutions * 30.
//    if (i > 9) {
//      Serial.print("RPM=\t"); //print the word "RPM" and tab.
//      Serial.print(rpm); // print the rpm value.
//      Serial.print("\t Rotation speed=\t");
//      Serial.print(rpm*2);
//      Serial.print("PI rad/s");
//      Serial.print("\t Hz=\t"); //print the word "Hz".
//      Serial.print(half_revolutions); //print revolutions per second or Hz. And print new line or enter.
//      Serial.print("\t Current=\t");
//      Serial.println(current);
//      i = 0;
//    }
//    half_revolutions = 0; // Restart the RPM counter
//    lastmillis = millis(); // Uptade lasmillis
//    attachInterrupt(digitalPinToInterrupt(2), rpm_fan, FALLING); //enable interrupt
//    if (desiredRPM != -1 && desiredRPM != rpm) {
//      if (rpm > desiredRPM) {
//        speedInput -= 10;
//      } else {
//        speedInput += 10;
//      }
//      setMotors(speedInput);
//    }
//  }
}
