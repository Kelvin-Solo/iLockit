#include"Arduino.h"
#include"relay.h"
#include"ultrasonic.h"
#include"rgb.h"
//int status = 1;

void pump_status(int level,int max_level, int min_level){
	if(level < min_level){
    while(level <= max_level){
      relay_on();
      level = calculate_distance();
      rgb_warning(level, min_level, max_level);

      char depth[3];

      water_depth(level, depth);
      Serial.print("level is ");
      Serial.print(depth);
      Serial.println(" cm, pump on");
    }
	}
	else{
      relay_off();
      level = calculate_distance();
      rgb_warning(level, min_level, max_level);

      char depth[3];

      water_depth(level, depth);
      Serial.print("local level is ");
      Serial.print(depth);
      Serial.println(" cm, pump off");
    }
	/*	relay_on();
		p_status = true;
    
		Serial.println("pump on, status true");
		//int local_level = calculate_distance();
		rgb_warning(local_level, min_level, max_level);

		char depth[3];

		water_depth(local_level, depth);
		Serial.print("local level is ");
		Serial.print(depth);
		Serial.println(" cm");

	}
 
 //code doesnt enter here!!!
	else if((level <= max_level) && (p_status)){
		relay_on();
		Serial.println("pump on, status true");

    int local_level = calculate_distance();
    rgb_warning(local_level, min_level, max_level);

    char depth[3];

    water_depth(local_level, depth);
    Serial.print("local level is ");
    Serial.print(depth);
    Serial.println(" cm");
    
		if(local_level == max_level){
			Serial.println("tank full");
			delay(1000);
			p_status = false;
		}
	}
	else{
		relay_off();
    
    int local_level = calculate_distance();
    rgb_warning(local_level, min_level, max_level);

    char depth[3];

    water_depth(local_level, depth);
    Serial.print("local level is ");
    Serial.print(depth);
    Serial.println(" cm");
    
		Serial.println("pump off, status false");
	}*/
}
