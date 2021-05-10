#include"Arduino.h"

const int red_light_pin = 11;
const int green_light_pin = 10;
const int blue_light_pin = 9;

void rgb_init(void){
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
//   Serial.println("RGB Complete");
}

void rgb_disp(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void rgb_warning(int distance, int min_level, int max_level){
	if(distance < min_level){
		rgb_disp(255,0,0);
    Serial.println("red light");
    delay(1000);
		/*printStringXY(0,0, "iLockit Limited");
		printStringXY(0,1, "Depth");
		printStringXY(0,2, "Water Level Low");
		printStringXY(0,3, "Pump ON");*/
	}
	else if((distance >= min_level) && (distance <= max_level)){
		rgb_disp(0,255,0);
    Serial.println("green light");
    delay(1000);
		/*printStringXY(0,0, "iLockit Limited");
        printStringXY(0,1, "Depth");
        printStringXY(0,2, "Water Level Safe");
        printStringXY(0,3, "Pump OFF");*/
     }
	else{
		rgb_disp(0,0,255);
    Serial.println("blue light");
    delay(1000);
		/*printStringXY(0,0, "iLockit Limited");
		printStringXY(0,1, "Depth");
		printStringXY(0,2, "Water Level High");
		printStringXY(0,3, "Pump OFF");*/
	}
}
