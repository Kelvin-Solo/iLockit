#pragma once

#include"Arduino.h"

void rgb_init(void);

void rgb_warning(int distance, int min_level, int max_level);

void rgb_disp(int red_light_value, int green_light_value, int blue_light_value);
