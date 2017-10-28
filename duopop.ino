#include <cmdline_defs.h>
#include <ProTrinketKeyboard.h>
#include <ProTrinketKeyboardC.h>
#include <usbconfig.h>

/* Pro Trinket Duo Pop Receiver IR decoder sketch!
 
 This sketch/program uses the Arduino and a Duo Pop Receiver IR board to 
 decode IR received data from 4 of the Poppers and translate the received data
 into keystrokes. This can be used to make a IR receiver
 (by looking for a particular code)
 or transmitter (by pulsing an IR LED at ~38KHz for the
 durations detected.  This sketch leveraged tutorials from www.ladyada.net and adafruit.com.
 
 Created by: www.itaparcade.com
 Twitter: @iTapArcade
 e-mail: info@itaparcade.com
 Date created: 9/20/2014
 Date updated: 9/20/2014
 
 For preassembled Duo Pop kit information, contact us at info@itaparcade.com
 
 */
//#include <SendOnlySoftwareSerial.h>
//#include "TrinketKeyboard.h"

// We need to use the 'raw' pin reading methods
// because timing is very important here and the digitalRead()
// procedure is slower!
//uint8_t IRpin = 2;
// Digital pin #2 is the same as Pin D2 see
// http://arduino.cc/en/Hacking/PinMapping168 for the 'raw' pin mapping
#define IRpin_PIN      PINC
#define IRpin          PINC5  // Connect to A5 on Pro Trinket

#define ledPin         13 

// the maximum pulse we'll listen for - 1 milliseconds based on Duo Pop pulses

#define MAXPULSE 1000

// what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20 

#define FUZZINESS 45

// we will store up to 100 pulse pairs (this is -a lot-)
uint16_t pulses[100][2];  // pair is high and low pulse 
uint8_t currentpulse = 0; // index for pulses we're storing

// Red Code

int DUOPOPsignalRed[] = { // ON, OFF (in 10's of microseconds) 
140, 50, 
100, 50, 
100, 100, 
50, 50, 
100, 50, 
100, 50, 
100, 100,  
50, 50,  
100, 50,  
100};

int DUOPOPsignalBlue[] = { // ON, OFF (in 10's of microseconds) 
140, 50, 
100, 50, 
100, 50, 
100, 100, 
50, 50, 
100, 50, 
100, 50,  
100, 100,  
50, 50,  
100};


int DUOPOPsignalYellow[] = { // ON, OFF (in 10's of microseconds) 
140, 
100, 50, 
50, 100, 
100, 50, 
50, 100, 
100, 50, 
50, 100, 
100, 50, 
50, 100, 
50, 100};

int DUOPOPsignalOrange[] = {
  140,
  100, 50,
  50, 100,
  50, 100,
  50, 100,
  100, 50,
  50, 100,
  50, 100,
  50, 100,
  50, 100
};

int DUOPOPsignalPink[] = {
  140,
  100, 58,
  100, 54, 
  100, 54, 
  46, 100,
  100, 48,
  100, 56,
  100, 54,
  48, 100,
  48, 100
};

int DUOPOPsignalGreen[] = { // ON, OFF (in 10's of microseconds) 
140, 
50, 100, 
100, 50, 
50, 100,
100, 50, 
50, 100, 
100, 50, 
50, 100, 
100, 50, 
50, 100};

//SendOnlySoftwareSerial Serial(0);

void setup(void) {
  // initialize the LED pin as an output.
  // Serial.begin(9600);
  // Serial.println("Ready to decode IR!");  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(IRpin, INPUT); 
  //  pinMode(Pwrpin, OUTPUT);
  //  digitalWrite (Pwrpin, HIGH);
  // Serial.begin(9600);
  // Serial.println("Ready to decode IR!");

 
   // Disable timer0 since it can mess with the USB timing. Note that
  // this means some functions such as delay() will no longer work.
  //TIMSK0&=!(1<<TOIE0);

  // Clear interrupts while performing time-critical operations
  //cli();

  // Force re-enumeration so the host will detect us
  //usbDeviceDisconnect();
  //delayMs(250);
  //usbDeviceConnect();

  // Set interrupts again
  //sei();

  // start USB stuff
  TrinketKeyboard.begin();
}

// What percent we will allow in variation to match the same code \\ #define FUZZINESS 20
 
void loop(void) {
   
  int numberpulses;
    
  numberpulses = listenForIR();
 
  //  Serial.print("Heard ");
  //  Serial.print(numberpulses);
  //  Serial.println("-pulse long IR signal");
  if (numberpulses == 10) {  
    // Serial.println("Received IR!"); 
    // digitalWrite(LED, HIGH);
    //   delay(50);
    //  digitalWrite(LED, LOW);
    if (IRcompare(numberpulses, DUOPOPsignalRed)) {
      //  Serial.println("RED Buzzed In");
      // TrinketKeyboard.pressKey(0, KEY_A);
      // TrinketKeyboard.pressKey(0, 0);
      //    digitalWrite(ledPin, LOW); // Toggle status LED
      //  delayMs(500);
      TrinketKeyboard.pressKey(0, KEYCODE_1);
      TrinketKeyboard.pressKey(0, 0);
      digitalWrite(ledPin, HIGH); // Toggle status LED
      delayMs(500);
    }
    if (IRcompare(numberpulses, DUOPOPsignalBlue)) {
      // Serial.println("BLUE Buzzed In");
  
      TrinketKeyboard.pressKey(0, KEYCODE_3);
      TrinketKeyboard.pressKey(0, 0);
      digitalWrite(ledPin, HIGH); // Toggle status LED
      delayMs(500);
    }
      if (IRcompare(numberpulses, DUOPOPsignalYellow)) {
     // Serial.println("Yellow Buzzed In");
       TrinketKeyboard.pressKey(0, KEYCODE_2);
       TrinketKeyboard.pressKey(0, 0);
       digitalWrite(ledPin, HIGH); // Toggle status LED
      delayMs(500);
  
    }

      if (IRcompare(numberpulses, DUOPOPsignalOrange)) {
        TrinketKeyboard.pressKey(0, KEYCODE_6);
        TrinketKeyboard.pressKey(0, 0);
        digitalWrite(ledPin, HIGH);
        delayMs(500);
      }

      if (IRcompare(numberpulses, DUOPOPsignalPink)) {
        TrinketKeyboard.pressKey(0, KEYCODE_7);
        TrinketKeyboard.pressKey(0, 0);
        digitalWrite(ledPin, HIGH);
        delayMs(500);
      }
      
     if (IRcompare(numberpulses, DUOPOPsignalGreen)) {
     // Serial.println("Green Buzzed In");
       TrinketKeyboard.pressKey(0, KEYCODE_4);
       TrinketKeyboard.pressKey(0, 0);
       digitalWrite(ledPin, HIGH); // Toggle status LED
      delayMs(500);
  
    }
  }
  // Show Trigger Status via LED
digitalWrite(ledPin, LOW); 
 
}

int listenForIR(void) {
  currentpulse = 0;
 
  while (1) {
  
    uint16_t highpulse, lowpulse;  // temporary storage timing
    highpulse = lowpulse = 0; // start out with no pulse length
//  while (digitalRead(IRpin)) { // this is too slow!
   // while (IRpin_PIN & (1 << IRpin)) {
     while (IRpin_PIN & _BV(IRpin)) {
       
       // Need to poll USB periodically while waiting for popper responses
       TrinketKeyboard.poll();
       
       // count off another few microseconds
       highpulse++;
       delayMicroseconds(RESOLUTION);
 
       // If the pulse is too long, we 'timed out' - either nothing
       // was received or the code is finished, so print what
       // we've grabbed so far, and then reset
       if (((highpulse >= MAXPULSE) && (currentpulse != 0)) || (currentpulse == 10)) {
         return currentpulse;
       }
    }
    // we didn't time out so lets stash the reading
    pulses[currentpulse][0] = highpulse;
 
    // same as above
    while (! (IRpin_PIN & _BV(IRpin))) {
       // pin is still LOW
       lowpulse++;
       delayMicroseconds(RESOLUTION);
       if (((lowpulse >= MAXPULSE)  && (currentpulse != 0)) || (currentpulse == 10)) {
         return currentpulse;
       }
    }
    pulses[currentpulse][1] = lowpulse;
 
    // we read one high-low pulse successfully, continue!
    currentpulse++;
  }
}


boolean IRcompare(int numpulses, int Signal[]) {
 
  for (int i=0; i< numpulses-1; i++) {
    int oncode = pulses[i][1] * RESOLUTION / 10;
    int offcode = pulses[i+1][0] * RESOLUTION / 10;
 
    
 //   Serial.print(oncode); // the ON signal we heard
 //   Serial.print(" - ");
 //   Serial.print(Signal[i*2 + 0]); // the ON signal we want 
    
 
    // check to make sure the error is less than FUZZINESS percent
    if ( abs(oncode - Signal[i*2 + 0]) <= (Signal[i*2 + 0] * FUZZINESS / 100)) {
  //    Serial.print(" (ok)");
    
      
    } else {
  //    Serial.print(" (x)");
      // we didn't match perfectly, return a false match
      return false;
    }
 
    
 //   Serial.print("  \t"); // tab
 //   Serial.print(offcode); // the OFF signal we heard
 //   Serial.print(" - ");
 //   Serial.print(Signal[i*2 + 1]); // the OFF signal we want 
    
 
    if ( abs(offcode - Signal[i*2 + 1]) <= (Signal[i*2 + 1] * FUZZINESS / 100)) {
  //    Serial.print(" (ok)");
    } else {
  //    Serial.print(" (x)");
      // we didn't match perfectly, return a false match
      return false;
    }
 
   // Serial.println();
  }
  // Everything matched!
  return true;
}

/**
 * Define our own delay function so that we don't have to rely on
 * operation of timer0, the interrupt used by the internal delay()
 */
void delayMs(unsigned int ms)
{
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
