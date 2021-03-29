#include"Arduino.h"

const int relay = 2;

void relay_init(void){
	pinMode(relay, OUTPUT);
}

void relay_off(void){
	digitalWrite(relay, HIGH);
}

void relay_on(void){
	digitalWrite(relay, LOW);
}

