int lmotor = 11;
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
  }
//  leftIRSensorReading = analogRead(leftIRSensor);
//  rightIRSensorReading = analogRead(rightIRSensor);
}
