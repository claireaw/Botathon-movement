#include <ArduinoJson.h>

StaticJsonDocument<200> doc;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor3pin2 = 7;

//
int motor4pin3 = 8;
int motor4pin4 = 9;

String incomingByte = "";

//
int motor2pin3 = 4;
int motor2pin4 = 5;

//
int motor3pin1 = 6;
void setup() {

Serial.begin(115200);
Serial.setTimeout(100);

    //if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.print(incomingByte);

    DeserializationError error = deserializeJson(doc, incomingByte);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
  
  // put your setup code here, to run once:

pinMode(motor1pin1, OUTPUT);
pinMode(motor1pin2, OUTPUT);
pinMode(motor2pin3, OUTPUT);
pinMode(motor2pin4, OUTPUT);

pinMode(motor3pin1, OUTPUT);
pinMode(motor3pin2, OUTPUT);
pinMode(motor4pin3, OUTPUT);
pinMode(motor4pin4, OUTPUT);

//pinMode(X, INPUT);
//pinMode(Y, INPUT);
//pinMode(LBUMPER, INPUT);
//pinMode(RBUMPER, INPUT);
//pinMode(XBUTTON, INPUT);
//pinMode(BBUTTON, INPUT);
}

void loop() {
// put your main code here, to run repeatedly:
//Serial.begin(9600);

  //if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.print(incomingByte);

    DeserializationError error = deserializeJson(doc, incomingByte);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

//want to read controller inputs (not inplementated)
//Using DPAD, L/R Bumpers, and X and B buttons

//DPAD scheme (x,y): 
// UP: 0,1
// DOWN: 0,-1
// LEFT: -1,0 -1,1 -1,-1
// RIGHT: 1,0 1,-1 1,1
// TUPLE?

// L/R Bumpers use T/F

// X/B buttons use T/F

   String key = doc["input"]["key"];
    float value = doc["input"]["value"].as<float>();
    
    Serial.print("KEY:");
    Serial.print(key);
    Serial.print(", VAL:");
    Serial.println(value);

//boolean LBUMPER = doc["input"]["value"]["LEFT_BUMPER"].as<boolean>();
//boolean RBUMPER = doc["input"]["value"]["RIGHT_BUMPER"].as<boolean>();
//boolean XBUTTON = doc["input"]["value"]["X_BUTTON"].as<boolean>();
//boolean BBUTTON = doc["input"]["value"]["B_BUTTON"].as<boolean>();
int x = doc["input"]["value"]["x"].as<int>();
int y = doc["input"]["value"]["y"].as<int>();

// UP CASE
if (x == 0 && y == 1) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, HIGH);
  digitalWrite(motor4pin4, LOW);
}

// DOWN CASE
if (x == 0 && y == -1) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, HIGH);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, HIGH);
}

// LEFT CASE
if ((x == -1 && y == 0)||(x == -1 && y == 1)||(x == -1 && y == -1)) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, HIGH);
}

// RIGHT CASE
if ((x == 1 && y == 0)||(x == 1 && y == -1)||(x == 1 && y == 1)) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, HIGH);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin3, HIGH);
  digitalWrite(motor4pin4, LOW);
}

// UPPER LEFT CASE
if (key == "LEFT_BUMPER" && (x == 0 && y == 1)) {
    if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, LOW);
    }
}

// UPPER RIGHT CASE
    if (key == "RIGHT_BUMPER" && (x == 0 && y == 1)) {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, HIGH);
  digitalWrite(motor4pin4, LOW);
      }
}

// DOWN LEFT CASE
// COULD BE WRONG
    if (key == "LEFT_BUMPER" && (x == 0 && y == -1)) {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, HIGH);
      }
}

// DOWN RIGHT CASE
// COULD BE WRONG
    if (key == "RIGHT_BUMPER" && (x == 0 && y == -1)) {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, HIGH);
  digitalWrite(motor4pin4, LOW);
      }
}

// ROTATECW CASE
    if (key == "B_BUTTON") {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, HIGH);
      }
}

// ROTATECCW CASE
    if (key == "X_BUTTON") {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin3, HIGH);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin3, HIGH);
  digitalWrite(motor4pin4, LOW);
      }
}

// STOP CASE
    if (key == "Y_BUTTON") {
      if (value == true) {
  //analogWrite(speedPinA, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin3, LOW);
  digitalWrite(motor2pin4, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin3, LOW);
  digitalWrite(motor4pin4, LOW);
      }
}

}
