/*
 Name:		Led_strip_for_room.ino
 Created:	9/26/2021 10:46:19 PM
 Author:	Zachary Bagshaw
*/


// the setup function runs once when you press reset or power the board

#include <Adafruit_NeoPixel.h>

#define BUTTON 26
#define LED_PIN 27
#define LED_COUNT 600

int NeopixelCount = LED_COUNT;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int red = 255;
int green = 0;
int blue = 0;
int mode = 2;
int old_mode = 0;
int speed = 10;
int z = 0;


#define MODE_OFF 1
#define MODE_RAINBOW 2
#define MODE_COLORWIPE 3
#define MODE_LAST 3


void setup() 
{
		Serial.begin(115200);
		strip.begin();           
		strip.show();        
		strip.setBrightness(200);
        pinMode(BUTTON, INPUT_PULLUP);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
    CheckButton();
    // Only action if mode changed
    if (mode != old_mode)
    {
        old_mode = mode;
        Serial.printf("Mode: %d\n",mode);

        switch (mode)
        {
            case MODE_OFF:
            {
                strip.clear();
                strip.setBrightness(0);
                strip.show();
                Serial.println("clear");
                break;
            }
            case MODE_RAINBOW:
            {
                strip.setBrightness(200);
                Rainbow(speed);
                break;
            }
            case MODE_COLORWIPE:
            {
                while (mode == MODE_COLORWIPE)
                {
                    strip.setBrightness(200);
                    ColorWipe(strip.Color(255, 0, 0), 50); // Red

                    if (mode != MODE_COLORWIPE) break;
                    ColorWipe(strip.Color(0, 255, 0), 50); // Green

                    if (mode != MODE_COLORWIPE) break;
                    ColorWipe(strip.Color(0, 0, 255), 50); // Blue
                }
                break;
            }
        } 
    }
}

void CheckButton()
{
    int ButtonState = digitalRead(BUTTON);
    if (ButtonState == LOW)
    {
        delay(400);
        ButtonState = digitalRead(BUTTON);
        if (ButtonState == LOW)
        {
            Serial.println("Button-Press");
            mode++;
            if (mode > MODE_LAST) mode = 1;
            
        }
    }
    
}

