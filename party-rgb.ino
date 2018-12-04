#include <Adafruit_NeoPixel.h>

#define PIN 9
#define LED_COUNT 2
#define buttonLedPin 10
#define buttonBuzzerPin 3
#define buzzerPin A5

int length = 28; // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int tempo = 150;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void playTone(int tone, int duration) {

for (long i = 0; i < duration * 1000L; i += tone * 2) {

   digitalWrite(buzzerPin, HIGH);
   leds.setPixelColor(0, 255, 0, 0); 
  leds.setPixelColor(1, 0, 255, 0); 
  leds.show(); //Display the colors
   delayMicroseconds(tone);

   digitalWrite(buzzerPin, LOW);
   leds.setPixelColor(0, 0, 0, 0); 
  leds.setPixelColor(1, 0, 0, 0);
  leds.show();
   delayMicroseconds(tone);

}

}

void playNote(char note, int duration) {

char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

int SPEE = 5;

// play the tone corresponding to the note name

for (int i = 0; i < 17; i++) {

   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);

   }

}

}


// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...


void setup()
{
 leds.begin();  // Start up the LED strip
 //leds.show();   // LEDs don't actually update until you call this function
 pinMode(buzzerPin, OUTPUT);
 pinMode(buttonBuzzerPin, INPUT_PULLUP);
 pinMode(buttonLedPin, INPUT_PULLUP);
}

void loop()
{
  
    for (int i = 0; i < length; i++) {

   if (notes[i] == ' ') {

     delay(beats[i] * tempo); // rest

   } else {

     playNote(notes[i], beats[i] * tempo);

   }

   // pause between notes

   delay(tempo);

}

  //}
}
