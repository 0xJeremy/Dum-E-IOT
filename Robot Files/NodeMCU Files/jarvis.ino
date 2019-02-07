#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Servo.h>

const char* ssid = "iPhone";
const char* password = "Artemis9698";

Servo base;
Servo pjoint;
Servo grip;

void setup() {
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected");

  base.attach(4, 800, 2200);     //Need to add pins
  pjoint.attach(2, 800, 2200);   //Need to add pins
  grip.attach(3, 800, 2200);     //Need to add pins
}

String get_action() {
  String payload = "error";
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin("http://makeharvard-mk1.herokuapp.com/get_jarvis");  //Change per robot
      int httpCode = http.GET();
      if (httpCode > 0) {
        payload = http.getString();
        Serial.println(payload);
    }
    http.end();
  }
  return payload;
}

void base_write(int angle) {
  base.write(angle);
  Serial.println("Base Writing");
}

void pjoint_write(int angle) {
  pjoint.write(angle);
  Serial.println("Primary Joint Writing");
}

void grip_write(int angle) {
  grip.write(angle);
  Serial.println("Grip Writing");
}


void loop() {
  String action = get_action();

  // BASE CONTROLS
  if(action[0] == 'b') {
    if(action[1] == 'n'){ 
      if(action[2] == '9'){ base_write(-90);}
      else{ base_write(-180); }
    }
    else {
      if(action[1] == '9'){ base_write(90);}
      else{ base_write(180); }
    }
  }

  // PRIMARY JOINT CONTROLS
  else if(action[0] == 'p') {
    if(action[1] == '0'){ pjoint_write(0); }
    else if(action[1] == '4'){ pjoint_write(45); }
    else{ pjoint_write(90); }
  }

  // GRIPPER CONTROLS
  else if(action[0] == 'g') {
    if(action[1] == 'o'){ grip_write(0); }
    else{ grip_write(90); }
  }

}
