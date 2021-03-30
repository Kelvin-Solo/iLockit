#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void oled_init(void){
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
		Serial.println(F("SSD1306 allocation failed"));
		for(;;);
	}
}

void oled_display(int X, int Y, int size, char text[20]){
	display.setTextSize(size);
	display.setTextColor(WHITE);
	display.setCursor(X,Y);
	display.println(text);
	display.display();
}

void clear_screen(void){
	display.clearDisplay();
}

