    /*
    Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
    */
     
    int latchPin = 5;
    int clockPin = 6;
    int dataPin = 4;
     
    byte leds = 0;
     
    void setup() 
    {
      pinMode(latchPin, OUTPUT);
      pinMode(dataPin, OUTPUT);  
      pinMode(clockPin, OUTPUT);
      Serial.begin(9600);
    }
     
    void loop() 
    {
      leds = 0;
      updateShiftRegister();
      delay(500);
      for (int i = 0; i < 8; i++)
      {
        bitSet(leds, i);
        Serial.println(leds);
        updateShiftRegister();
        delay(500);
      }
    }
     
    void updateShiftRegister()
    {
       digitalWrite(latchPin, LOW);
       shiftOut(dataPin, clockPin, LSBFIRST, leds);
       digitalWrite(latchPin, HIGH);
    }
