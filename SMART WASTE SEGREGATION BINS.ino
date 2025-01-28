#include <Servo.h>


Servo servo1;
Servo servo2;


const int moisturePin = A0;
const int proximityPin = 2;

// Servo Positions
int dryPosition = 0;     
int wetPosition = 90;    
int detectedPosition = 180; 

void setup() {
    Serial.begin(9600);

    // Attach servos
    servo1.attach(9);
    servo2.attach(10);

    
    pinMode(proximityPin, INPUT);
}

void loop() {
    
    int moistureValue = analogRead(moisturePin);
    Serial.print("Moisture Level: ");
    Serial.println(moistureValue);

    
    int proximityStatus = digitalRead(proximityPin);
    Serial.print("Proximity Sensor: ");
    Serial.println(proximityStatus);

    // Moisture Control
    if (moistureValue < 500) {  
        servo1.write(dryPosition);
    } else {  
        servo1.write(wetPosition);
    }

    
    if (proximityStatus == LOW) {  
        servo2.write(detectedPosition);
    } else {
        servo2.write(0);  
    }

    delay(500);
}
