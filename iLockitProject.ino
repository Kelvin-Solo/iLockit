
//#include"display.h"
//#include"rgb.h"
#include"ultrasonic.h"
int max_level = 20;
int min_levl = 5;
int distance = 0;
char depth[3];

void setup() {

  ultrasonic_init();
 
  Serial.begin(9600);
  

  Serial.println("ILockit initializing...");
  
}

void loop() {

  distance = calculate_distance();
  water_depth(distance, depth);

  Serial.print("distance is ");
  Serial.print(depth);
  Serial.println(" cm");
}
