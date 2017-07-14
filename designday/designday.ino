int lmotor = 11;
int rmotor = 3;
int leftIRSensor = A2;
int rightIRSensor = A3;

int currentSensor = A0;
int current = 0;

String serialInput;
int speedInput;
int leftIRSensorReading;
int rightIRSensorReading;

 // read RPM
 int half_revolutions = 0;
 int rpm = 0;
 unsigned long lastmillis = 0;
 

  
 }
 // this code will be executed every time the interrupt 0 (pin2) gets low.
 void rpm_fan(){
  half_revolutions++;
 }
 
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(lmotor,OUTPUT); 
  pinMode(rmotor,OUTPUT); 

   attachInterrupt(digitalPinToInterrupt(2), rpm_fan, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    serialInput = Serial.readStringUntil(' ');
    if (serialInput == "start") {
      speedInput = Serial.parseInt();
      analogWrite(lmotor, speedInput);
      analogWrite(rmotor, speedInput);
      Serial.print("starting motor with speed ");
      Serial.println(speedInput);
    }
    
    if (serialInput == "stop") {
      analogWrite(lmotor, 0);
      analogWrite(rmotor, 0);
    }
    
    Serial.println(serialInput);
  }
//  leftIRSensorReading = analogRead(leftIRSensor);
//  rightIRSensorReading = analogRead(rightIRSensor);
}int lmotor = 11;
int rmotor = 3;
int leftIRSensor = A2;
int rightIRSensor = A3;

String serialInput;
int speedInput;
int leftIRSensorReading;
int rightIRSensorReading;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(lmotor,OUTPUT); 
  pinMode(rmotor,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    serialInput = Serial.readStringUntil(' ');
    if (serialInput == "start") {
      speedInput = Serial.parseInt();
      analogWrite(lmotor, speedInput);
      analogWrite(rmotor, speedInput);
      Serial.print("starting motor with speed ");
      Serial.println(speedInput);
    }
    
    if (serialInput == "stop") {
      analogWrite(lmotor, 0);
      analogWrite(rmotor, 0);
    }
    
    Serial.println(serialInput);

    
 detachInterrupt(0);//Disable interrupt when calculating
 rpm = half_revolutions * 60; // Convert frecuency to RPM, note: this works for one interruption per full rotation. For two interrups per full rotation use half_revolutions * 30.
 Serial.print("Rotational Speed =\t"); //print the word "RPM" and tab.
 Serial.print(rpm); // print the rpm value.
 Serial.print("\t Hz=\t"); //print the word "Hz".
 Serial.println(half_revolutions); //print revolutions per second or Hz. And print new line or enter.
 half_revolutions = 0; // Restart the RPM counter
 lastmillis = millis(); // Uptade lasmillis
 attachInterrupt(digitalPinToInterrupt(2), rpm_fan, FALLING); //enable interrupt

current = analogRead(currentsensor);
Serial.println(current);
  }
//  leftIRSensorReading = analogRead(leftIRSensor);
//  rightIRSensorReading = analogRead(rightIRSensor);
}
