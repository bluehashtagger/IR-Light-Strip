/*
 Name:		Led_strip_for_room.ino
 Created:	9/26/2021 10:46:19 PM
 Author:	Zachary Bagshaw
*/

#define LED_PIN 27
#define LED_COUNT 600

int NeopixelCount = LED_COUNT;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
	strip.begin();
	strip.show();
	strip.setBrightness(50);
}

void loop()
{
	int i = 0;
	while (i < LED_COUNT)
	{
		strip.setPixelColor(i, 255, 255, 255);
		++i;
	}
}