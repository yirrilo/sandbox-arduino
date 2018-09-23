//Import the Adafruit Library to handle NeoPixel Ring
#include <Adafruit_NeoPixel.h>

//Configuration of the ring for the project
#define RING_PIN 10
#define RING_TYPE NEO_GRBW + NEO_KHZ800
#define RING_NB_PIX 15
#define RING_BRIGHTNESS 30

//Configuration of the fire like candle
#define FIRE_RED_VALUE 255
#define FIRE_GREEN_VALUE 75
#define FIRE_BLUE_VALUE 5
#define FIRE_THRESHOLD 50
#define ADJUST_VALUE(value,threshold) (value > threshold)?value-threshold:0; 


//Candle management tool
Adafruit_NeoPixel candle = Adafruit_NeoPixel( RING_NB_PIX, RING_PIN, RING_TYPE);


void setup() {
  // Initialization of the candle
  candle.setBrightness(RING_BRIGHTNESS);
  candle.begin();
  candle.show();
}

void loop() {

  for(int i = 0; i < RING_NB_PIX; i++)
  {
    int threshold = random(0, FIRE_THRESHOLD);
    int redValue = ADJUST_VALUE(FIRE_RED_VALUE, threshold);
    int greenValue = ADJUST_VALUE(FIRE_GREEN_VALUE, threshold);
    int blueValue = ADJUST_VALUE(FIRE_BLUE_VALUE, threshold);
    candle.setPixelColor(i, redValue, greenValue, blueValue);
  }
  candle.show();
  delay(random(50,150));
}
