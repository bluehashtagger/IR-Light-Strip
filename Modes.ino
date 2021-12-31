


void Rainbow(int wait)
{
    int z = 5;
    for (long firstPixelHue = 0; z == 5 ; firstPixelHue += 256)
    {
        // check for mode change
        CheckButton();
        if (mode != MODE_RAINBOW) break;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            CheckButton();
            if (mode != MODE_RAINBOW) break;
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        }
        strip.show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
    } 
}


void ColorWipe(uint32_t color, int wait) 
{
    for (int i = 0; i < strip.numPixels(); i++)// For each pixel in strip...
    {                                      
        CheckButton();
        if (mode != MODE_COLORWIPE) break;
        strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
        strip.show();                          //  Update strip to match
        delay(wait);                           //  Pause for a moment
    }
}


void FullWack()
{

    int i = 0;
    while (i < LED_COUNT)
    {
        strip.setPixelColor(i, 255, 255, 255);
        ++i;
    }
    strip.show();
}
