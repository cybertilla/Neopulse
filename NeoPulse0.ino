//Blik the first two LEDs of a 60 neopixel stripe to your heartbeat.
//cybertilla2020

#include <Adafruit_NeoPixel.h>
#include <PulseSensorPlayground.h>


//variables
int PulseSensorPurplePin = 0;
int LED5 = 5;
#define NUM_LEDS 60
#define PIN 5

//creating NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);


int Signal;
int Threshold = 650;

void setup() {
  pinMode(LED5, OUTPUT);
   Serial.begin(96000);

  //Neopixel configure.
  strip.begin();
  strip.show();
}


void loop() {

  Signal = analogRead(PulseSensorPurplePin);

  Serial.println(Signal);


  if(Signal > Threshold){
//    digitalWrite(LED5, HIGH);
   strip.setPixelColor(0, 255, 0, 0);
   strip.show();
  }else{
//    digitalWrite(LED5, LOW);
    strip.setPixelColor(0, 0, 255, 0);
    strip.show();
  }
}
