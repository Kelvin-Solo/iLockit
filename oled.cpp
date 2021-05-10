#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4		// Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void oled_init(void)
{
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			; // Don't proceed, loop forever
	}
	else{
		Serial.println(F("SSD1306 allocation Success"));
	}

	Serial.println("OLED Complete");
}

void oled_display(int X, int Y, int size, char text[20])
{
	display.setTextSize(size);
	display.setTextColor(WHITE);
	display.setCursor(X, Y);
	display.println(text);
	display.display();
}

void clear_screen(void)
{
	display.clearDisplay();
}
