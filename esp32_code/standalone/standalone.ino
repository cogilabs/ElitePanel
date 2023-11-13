#include <BleKeyboard.h>
BleKeyboard bleKeyboard("Elite Panel");

#define R1 18     // Y1 LB LG LW LY LR Y4
#define R2 5      // B1                Y5
#define R3 17     // B2  Y2 B5   R3 R6 W1
#define R4 16     // B3  R1 R2   R4 B6 G3
#define R5 4      // B4  G1 G2   R5 Y3 Y6
#define R6 2

#define G1 25
#define G2 26
#define G3 27

#define VIT 36
#define B5 14
#define B6 12

#define Y1 23
#define Y2 22
#define Y3 1
#define Y4 3
#define Y5 21
#define Y6 19

#define W1 15

#define LB 39
#define LG 34
#define LW 35
#define LY 32
#define LR 33

boolean R1S = LOW;
boolean R2S = LOW;
boolean R3S = LOW;
boolean R4S = LOW;
boolean R5S = LOW;
boolean R6S = LOW;

boolean G1S = LOW;
boolean G2S = LOW;
boolean G3S = LOW;

boolean B1S = LOW;
boolean B2S = LOW;
boolean B3S = LOW;
boolean B4S = LOW;
boolean B5S = LOW;
boolean B6S = LOW;

boolean Y1S = LOW;
boolean Y2S = LOW;
boolean Y3S = LOW;
boolean Y4S = LOW;
boolean Y5S = LOW;
boolean Y6S = LOW;

boolean W1S = LOW;

boolean LBS = LOW;
boolean LGS = LOW;
boolean LWS = LOW;
boolean LYS = LOW;
boolean LRS = LOW;

int B1Min = 3800;
int B1Max = 4100;
int B2Min = 3650;
int B2Max = 3750;
int B3Min = 3450;
int B3Max = 3500;
int B4Min = 3250;
int B4Max = 3295;

boolean started = LOW;

void setup() {

  //Serial.begin(115200);
 
  //Serial.println("Starting BLE");
  bleKeyboard.begin();
  //Serial.println("BLE Started");
  
  pinMode(R1, INPUT_PULLDOWN);
  pinMode(R2, INPUT);
  pinMode(R3, INPUT_PULLDOWN);
  pinMode(R4, INPUT_PULLDOWN);
  pinMode(R5, INPUT_PULLDOWN);
  pinMode(R6, INPUT_PULLDOWN);
  
  pinMode(G1, INPUT_PULLDOWN);
  pinMode(G2, INPUT_PULLDOWN);
  pinMode(G3, INPUT_PULLDOWN);
  
  pinMode(VIT, INPUT);
  pinMode(B5, INPUT_PULLDOWN);
  pinMode(B6, INPUT_PULLDOWN);
  
  pinMode(Y1, INPUT_PULLDOWN);
  pinMode(Y2, INPUT_PULLDOWN);
  pinMode(Y3, INPUT);
  pinMode(Y4, INPUT);
  pinMode(Y5, INPUT_PULLDOWN);
  pinMode(Y6, INPUT_PULLDOWN);
  
  pinMode(W1, INPUT_PULLDOWN);
  
  pinMode(LB, INPUT);
  pinMode(LG, INPUT);
  pinMode(LW, INPUT_PULLDOWN);
  pinMode(LY, INPUT_PULLDOWN);
  pinMode(LR, INPUT_PULLDOWN);
}

void loop() {
  speedManagement();
  fightersManagement();
  targetingManagement();
  fsdManagement();
  mapManagement();
  lightsManagement();
  leversManagement();
  landingAuthorization(Y1, &Y1S);
}

void speedManagement() {
  anaLink(VIT, B1Min, B1Max, &B1S, 0x30);    // à/0  +/- 100%
  anaLink(VIT, B2Min, B2Max, &B2S, 0x39);    // ç/9  +/- 75%
  anaLink(VIT, B3Min, B3Max, &B3S, 0x38);    // _/8  +/- 50%
  anaLink(VIT, B4Min, B4Max, &B4S, 0x78);    // x    0%
}

void fightersManagement() {
  keyLink(Y2, &Y2S, 0xE5);    // Num5 Maintain position
  keyLink(B5, &B5S, 0xEA);    // Num0 Call fighter back
  keyLink(R1, &R1S, 0xE2);    // Num2 Fire at will
  keyLink(R2, &R2S, 0xE3);    // Num3 Attack the target
  keyLink(G1, &G1S, 0xE1);    // Num1 Defend me
  keyLink(G2, &G2S, 0xE6);    // Num6 Follow me
}

void targetingManagement() {
  keyLink(R3, &R3S, KEY_F8);  // F8 Previous hostile target
  keyLink(R6, &R6S, KEY_F7);  // F7 Next hostile target
  keyLink(R4, &R4S, 0x68);    // h  Biggest threat
  keyLink(R5, &R5S, 0x76);    // v  Heat sink
  keyLink(B6, &B6S, 0x3D);    // =  Next GPS Target
}

void fsdManagement() {
  keyLink(Y3, &Y3S, 0x6B);    // k  Hyperspeed
  keyLink(Y6, &Y6S, 0x75);    // u  Jump
}

void mapManagement() {
  keyLink(Y4, &Y4S, 0x6D);    // m    Galaxy map
  keyLink(Y5, &Y5S, 0x36);    // -/6  System map
}

void lightsManagement() {
  keyLink(W1, &W1S, 0x6C);    // l  Headlights
  keyLink(G3, &G3S, 0x69);    // i  Night vision
}

void leversManagement() {
  leverLink(LB, &LBS, 0x2F);          // !    Prop inversion
  //leverLink(LG, &LGS, 0x);            // Not yet implemented
  //leverLink(LW, &LWS, 0x);            // Not yet implemented
  leverToggleLink(LY, &LYS, KEY_F5);  // F5   Weapons deployment
  emergencyStop(LR, &LRS, 0x6A);      // JJ   Emergency stop
}

void emergencyStop(int pin, boolean *pinState, uint8_t key) {
  if (digitalRead(pin) == HIGH) {
    if (*pinState == LOW) {
      //Serial.print("Emergency stop : ");
      bleKeyboard.write(key);
      //Serial.print(key, HEX);
      //Serial.print(", ");
      delay(100);
      bleKeyboard.write(key);
      //Serial.println(key, HEX);
    }
    *pinState = HIGH;
    delay(10);
  } else {
    *pinState = LOW;
  }
}

void landingAuthorization(int pin, boolean *pinState) {
  if (digitalRead(pin) == HIGH) {
    if (*pinState == LOW) {
      //Serial.println("Landing authorization : ");
      maintainedPress(KEY_LEFT_SHIFT, 150); // Left Shift
      delay(150);
      maintainedPress(0x65, 150); // e
      delay(150);
      maintainedPress(0x65, 150); // e
      delay(150);
      maintainedPress(0x61, 150); // a
      delay(150);
      maintainedPress(0x64, 150); // d
      delay(150);
      maintainedPress(0x20, 150); // space
      delay(150);
      maintainedPress(0x61, 150); // a
      delay(150);
      maintainedPress(0x71, 150); // q
      delay(150);
      maintainedPress(0x71, 150); // q
      delay(150);
      maintainedPress(KEY_ESC, 150); // Escape
      delay(150);
    }
    *pinState = HIGH;
    delay(10);
  } else {
    *pinState = LOW;
  }
}

void keyLink(int pin, boolean *pinState, uint8_t key) {
  if (digitalRead(pin) == HIGH) {
    if (*pinState == LOW) {
      bleKeyboard.write(key);
      //Serial.println(key, HEX);
    }
    *pinState = HIGH;
    delay(10);
  } else {
    *pinState = LOW;
  }
}

void anaLink(int pin, int valMin, int valMax, boolean *pinState, uint8_t key){
  if (valMin <= analogRead(pin) && analogRead(pin) < valMax) {
    delay(50);
    if (valMin <= analogRead(pin) && analogRead(pin) < valMax) {
      if (*pinState == LOW) {
        bleKeyboard.write(key);
        //Serial.println(key, HEX);
      }
      *pinState = HIGH;
      delay(100);
    }
  } else {
    *pinState = LOW;
  }
}

void leverLink(int pin, boolean *pinState, uint8_t key) {
  if (digitalRead(pin) == HIGH) {
    if (*pinState == LOW) {
      bleKeyboard.press(key);
      //Serial.print("pressing ");
      //Serial.println(key, HEX);
    }
    *pinState = HIGH;
    delay(10);
  } else {
    if (*pinState == HIGH) {
      bleKeyboard.release(key);
      //Serial.print("releasing ");
      //Serial.println(key, HEX);
    }
    *pinState = LOW;
    delay(10);
  }
}

void maintainedPress(uint8_t key, int del) {
  bleKeyboard.press(key);
  //Serial.print("pressing ");
  //Serial.println(key, HEX);
  delay(del);
  bleKeyboard.release(key);
  //Serial.print("releasing ");
  //Serial.println(key, HEX);
}

void leverToggleLink(int pin, boolean *pinState, uint8_t key) {
  if (digitalRead(pin) == HIGH) {
    if (*pinState == LOW) {
      bleKeyboard.write(key);
      //Serial.println(key, HEX);
    }
    *pinState = HIGH;
    delay(10);
  } else {
    if (*pinState == HIGH) {
      bleKeyboard.write(key);
      //Serial.println(key, HEX);
    }
    *pinState = LOW;
    delay(10);
  }
}