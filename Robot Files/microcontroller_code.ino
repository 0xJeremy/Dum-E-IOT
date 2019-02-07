#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Define pins for servos
#define gripperPin 5
#define wristPin 4
#define elbowPin 0
#define shoulderPin 2
#define basePin 14

// Define parameters for each servo
#define minPulse180 400
#define maxPulse180 2400
#define minPulseShoulder 800
#define maxPulseShoulder 2200
#define minPulseCont 700
#define maxPulseCont 2300
#define timeWaitAngle 25
#define timeWaitSpeed 50

// Define constants for wifi
const char* ssid = "iPhone";
const char* password = "Artemis9698";

// Define servo objects
Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

// setServoAngle - Sets angle of servo
void setServoAngle(Servo &thisServo, int minPulse, int maxPulse, int angle, int minAngle, int maxAngle){
  int pulse = map(angle, minAngle, maxAngle, minPulse, maxPulse);
  thisServo.writeMicroseconds(pulse);
  delay(timeWaitAngle);
}

// turnContServo - turns continuous servo 
void turnContServo(Servo &thisServo, bool cw, int minPulse, int maxPulse){
  if(cw){
    thisServo.writeMicroseconds(minPulse);
    delay(timeWaitSpeed);
  }else{
    thisServo.writeMicroseconds(maxPulse);
    delay(timeWaitSpeed);
  }
}

// get_action - get action command from website
String get_action() {
  String payload = "error";
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin("http://makeharvard-mk1.herokuapp.com/get_friday");  //Change per robot
      int httpCode = http.GET();
      if (httpCode > 0) {
        payload = http.getString();
        Serial.println(payload);
    }
    http.end();
  }
  return payload;
}

void setup() {
  // Attach servos to pins
  gripper.attach(gripperPin, minPulse180, maxPulse180);
  wrist.attach(wristPin, minPulse180, maxPulse180);
  elbow.attach(elbowPin, minPulse180, maxPulse180);
  shoulder.attach(shoulderPin, minPulseShoulder, maxPulseShoulder);
  base.attach(basePin, minPulseCont, maxPulseCont);
  
  Serial.begin(9600);

  // Connect to wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected");
}

void loop() {
  
  String action = get_action();

  switch (action[0]){

    case 'g':
      // Move gripper
      if(action[1] == 'o'){
        setServoAngle(gripper, minPulse180, maxPulse180, 180, 0, 180);
      }else{
        setServoAngle(gripper, minPulse180, maxPulse180, 0, 0, 180);
      }
      break;

    case 'w':
      // Move wrist
      if(action[1] == '0'){
        setServoAngle(wrist, minPulse180, maxPulse180, 0, 0, 180);
      }
      else if(action[1] == '4'){
        setServoAngle(wrist, minPulse180, maxPulse180, 45, 0, 180);
      }
      else if(action[1] == '9'){
        setServoAngle(wrist, minPulse180, maxPulse180, 90, 0, 180);
      }
      else if(action[2] == '3'){
        setServoAngle(wrist, minPulse180, maxPulse180, 135, 0, 180);
      }
      else if(action[2] == '8'){
        setServoAngle(wrist, minPulse180, maxPulse180, 180, 0, 180);
      }
      break;

    case 'e':
      // Move elbow
      if(action[1] == '0'){
        setServoAngle(elbow, minPulse180, maxPulse180, 0, 0, 180);
      }
      else if(action[1] == '4'){
        setServoAngle(elbow, minPulse180, maxPulse180, 45, 0, 180);
      }
      else if(action[1] == '9'){
        setServoAngle(elbow, minPulse180, maxPulse180, 90, 0, 180);
      }
      else if(action[2] == '3'){
        setServoAngle(elbow, minPulse180, maxPulse180, 135, 0, 180);
      }
      else if(action[2] == '8'){
        setServoAngle(elbow, minPulse180, maxPulse180, 180, 0, 180);
      }
      break;

    case 's':
      // Move shoulder
      if(action[1] == '0'){
        setServoAngle(shoulder, minPulse180, maxPulse180, 0, 0, 180);
      }
      else if(action[1] == '4'){
        setServoAngle(shoulder, minPulse180, maxPulse180, 45, 0, 180);
      }
      else if(action[1] == '9'){
        setServoAngle(shoulder, minPulse180, maxPulse180, 90, 0, 180);
      }
      break;

    case 'b':
      // Turn base
      if(action[1] == 'f'){
        turnContServo(base, true, minPulseCont, maxPulseCont);
      }
      else if(action[1] == 'r'){
        turnContServo(base, false, minPulseCont, maxPulseCont);
      }
      break;

    case 'E':
      //command
      Serial.println("ERROR: Something went wrong!");
      break;
    
    default:
      Serial.println("No command received.");
      break;
    
  }

}
