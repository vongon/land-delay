#include <jled.h>
#include <JC_Button.h>

const int PIN_OUT_LED_1 = 8; //D5
const int PIN_OUT_LED_2 = 9; //D6
const int PIN_OUT_LED_3 = 10; //D7
const int PIN_OUT_ECHO1_CTRL = 11; //D8
const int PIN_OUT_ECHO2_CTRL = 12; //D9
const int PIN_OUT_ECHO3_CTRL = 13; //D10
const int PIN_IN_SWITCH1 = 5; //D2
const int PIN_IN_SWITCH2 = 6; //D3
const int PIN_IN_SWITCH3 = 7; //D4

Button SWITCH1(PIN_IN_SWITCH1, 25, true, true); // pin, debounce time (ms), pull up enable, inverted logic enable
Button SWITCH2(PIN_IN_SWITCH2, 25, true, true); // pin, debounce time (ms), pull up enable, inverted logic enable
Button SWITCH3(PIN_IN_SWITCH3, 25, true, true); // pin, debounce time (ms), pull up enable, inverted logic enable

bool DELAY1_STATE = false;
bool DELAY2_STATE = false;
bool DELAY3_STATE = false;

void setup() {
  SWITCH1.begin();
  SWITCH2.begin();
  SWITCH3.begin();
  setupPins();
}

void loop() {
  SWITCH1.read();
  SWITCH2.read();
  SWITCH3.read();
  updateDelays();
  updateState();
}

void setupPins() {
  pinMode(PIN_OUT_ECHO1_CTRL, OUTPUT);
  pinMode(PIN_OUT_ECHO2_CTRL, OUTPUT);
  pinMode(PIN_OUT_ECHO3_CTRL, OUTPUT);
  pinMode(PIN_OUT_LED_1, OUTPUT);
  pinMode(PIN_OUT_LED_2, OUTPUT);
  pinMode(PIN_OUT_LED_3, OUTPUT);
}

void updateDelays(){
  if (DELAY1_STATE) {
    digitalWrite(PIN_OUT_LED_1, HIGH);
    digitalWrite(PIN_OUT_ECHO1_CTRL, HIGH);
  }
  else {
    digitalWrite(PIN_OUT_LED_1, LOW);
    digitalWrite(PIN_OUT_ECHO1_CTRL, LOW);
  }
  if (DELAY2_STATE) {
    digitalWrite(PIN_OUT_LED_2, HIGH);
    digitalWrite(PIN_OUT_ECHO2_CTRL, HIGH);
  }
  else {
    digitalWrite(PIN_OUT_LED_2, LOW);
    digitalWrite(PIN_OUT_ECHO2_CTRL, LOW);
  }
  if (DELAY3_STATE) {
    digitalWrite(PIN_OUT_LED_3, HIGH);
    digitalWrite(PIN_OUT_ECHO3_CTRL, HIGH);
  }
  else {
    digitalWrite(PIN_OUT_LED_3, LOW);
    digitalWrite(PIN_OUT_ECHO3_CTRL, LOW);
  }
}

void updateState(){
  if (SWITCH1.wasPressed()) {
    DELAY1_STATE = !DELAY1_STATE;
  }
  if (SWITCH2.wasPressed()) {
    DELAY2_STATE = !DELAY2_STATE;
  }
  if (SWITCH3.wasPressed()) {
    DELAY3_STATE = !DELAY3_STATE;
  }
}