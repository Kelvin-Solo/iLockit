
//#include"display.h"
#include"rgb.h"
#include"ultrasonic.h"
#include"relay.h"
#include"pump_status.h"

int max_level = 10;
int min_level = 4;
int level = 0;
char depth[3];
bool p_status = false;

void setup() {

  ultrasonic_init();
  rgb_init();
  relay_init();
 
  Serial.begin(9600);
  

  Serial.println("ILockit initializing...");
  delay(1000);

  level = calculate_distance();
  water_depth(level, depth);
  rgb_warning(level, min_level, max_level);
  
  Serial.print("starting level is ");
  Serial.print(depth);
  Serial.println(" cm");
  delay(5000);
}

void loop() {
  //p_status = true;
 
  pump_status(level, max_level, min_level);

  //level = calculate_distance();
  //rgb_warning(level, min_level, max_level);
  //water_depth(level, depth);

  //Serial.print("distance is ");
  //Serial.print(depth);
  //Serial.println(" cm");
  delay(1000);
  Serial.print("END... ");
  level = calculate_distance();
  
}
