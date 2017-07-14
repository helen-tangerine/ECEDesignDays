/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo steering;
Servo moving;
Servo rotating;

int currentPos = 40;    // variable to store the servo position

void setup() {
  steering.attach(2);  // attaches the servo on pin 9 to the servo object
  steering.write(currentPos);

  moving.attach(7);
  moving.write(100);

  rotating.attach(4);
  rotating.write(100);
  
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    char command = input.charAt(0);
    int target = input.substring(2).toInt();
    
    switch(command) {
      case 's': {
        int targetPos = target;
        int increment = 1;
    
        if (targetPos < currentPos) {
          increment*= -1;
        }
        
        for (int pos = currentPos; pos != targetPos; pos += increment) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          steering.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
    
        currentPos = targetPos;
      }
        break;
        
      case 'm': {
        moving.write(target);
      }
        break;

      case 'r': {
        rotating.write(target);
      }

      case 'x': {
        steering.write(40);
        moving.write(100);
        rotating.write(100);
      }
        break;
    }
  }
}
