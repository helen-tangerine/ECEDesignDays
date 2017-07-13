int lmotor = 2;
int rmotor = 3;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(lmotor,OUTPUT); 
pinMode(rmotor,OUTPUT); 


}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(lmotor,200);
analogWrite(rmotor,200);

delay(2000);

analogWrite(lmotor,0);
analogWrite(rmotor,0);

}
