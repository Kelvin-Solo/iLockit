#include"Arduino.h"
#include"relay.h"
#include"ultrasonic.h"
#include"rgb.h"
#include"oled.h"

void pump_status(int level,int max_level, int min_level){
	if(level < min_level){
    while(level <= max_level){
      relay_on();
      level = calculate_distance();
      rgb_warning(level, min_level, max_level);

      char depth[20];

      water_depth(level, depth);
      oled_display(0,0,1,"Capacity: ");
      oled_display(82,0,1, depth);
      oled_display(0,12,1,"Pump Status: ON");
      clear_screen();
      Serial.print("level is ");
      Serial.print(depth);
      Serial.println(" cm, pump on");
    }
	}
	else{
      relay_off();
      level = calculate_distance();
      rgb_warning(level, min_level, max_level);

      char depth[20];

      water_depth(level, depth);
      oled_display(0,0,1,"Capacity: ");
      oled_display(82,0,1, depth);
      oled_display(0,12,1,"Pump Status: OFF");
      clear_screen();
      
      Serial.print("local level is ");
      Serial.print(depth);
      Serial.println(" cm, pump off");
    }
    
    clear_screen();
}
