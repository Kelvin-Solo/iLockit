#include<stdlib.h>
#include"Arduino.h"

const int trigPin = 7;
const int echoPin = 6;

void ultrasonic_init(void){
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

int calculate_distance(void){
	//clear trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	//set trigPin on high state for 10ms
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	int pulseDuration = pulseIn(echoPin, HIGH);

	int distance = pulseDuration * 0.034 / 2;

	

	return distance;
}

void  water_depth(int distance, char depth[3]){
	itoa(distance, depth, 10);
}
