#pragma once
#include "Arduino.h"

void ultrasonic_init(void);
int calculate_distance(void);
void water_depth(int distance,char depth[3]);
