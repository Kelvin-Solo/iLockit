
//#include"display.h"
#include"rgb.h"
#include"ultrasonic.h"
int max_level = 10;
int min_level = 5;
int distance = 0;
char depth[3];

void setup() {

  ultrasonic_init();
  rgb_init();
 
  Serial.begin(9600);
  

  Serial.println("ILockit initializing...");
  delay(1000);
  
}

void loop() {

  distance = calculate_distance();
  rgb_warning(distance, min_level, max_level);
  water_depth(distance, depth);

  Serial.print("distance is ");
  Serial.print(depth);
  Serial.println(" cm");
  delay(1000);
}
