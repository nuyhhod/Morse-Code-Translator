//Morse Code Decoder and Encoder
/* This Arduino-based project converts text to Morse code and vice versa using an LED, speaker, and button input. 
Users can type letters via the serial monitor to see Morse code signals or input Morse via a button to decode messages. 
Decoded output is displayed on an LCD screen. */

  #include <LiquidCrystal.h>  //uses an LC Display with no I2C  

  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Pins for LCD display
  int buttonPin = 8; // Pin for button input 
  int tonePin = 10; // Pin for speaker or buzzer
  int toneFreq = 1000;
  int ledPin = 13; // Pin for LED light used a 220 Ohm resistor
  int debounceDelay = 30; //time delay used to filter out unwanted fluctuations in input signal

  int dotLength = 240;
  int dotSpace = dotLength;
  int dashLength = dotLength * 3;
  int letterSpace = dotLength * 3;
  int wordSpace = dotLength * 7;
  float wpm = 1200. / dotLength;

  int t1, t2, onTime, gap;
  bool newLetter, newWord, letterFound, keyboardText;
  int lineLength = 0;
  int maxLineLength = 20;
  bool buzzerEnabled = true;

  char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
  };


  char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",  //0-4
  ".....", "-....", "--...", "---..", "----."   //5-9
  };


  String dashSeq = "";
  char keyLetter, ch;
  int i, index;


void setup() {
  delay(500);
  pinMode(ledPin, OUTPUT);
  pinMode(tonePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println();
  lcd.begin(16, 2);  // 16 columns, 2 rows
  lcd.clear();

  Serial.println("Click field in Serial Monitor,");
  Serial.println("type text and press Enter, or");
  Serial.println("Key in Morse Code to decode:");
  Serial.println("-------------------------------");


  newLetter = false;  //if false, do NOT check for end of letter gap
  newWord = false;    //if false, do NOT check for end of word gap
  keyboardText = false;
}


void loop() {
    if (Serial.available() > 0) {
      if (keyboardText == false) {
        Serial.println();
        Serial.println("-------------------------------");
      }
      keyboardText = true;
      ch = Serial.read();

      // Convert lowercase to uppercase
      if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;
      }

      if (ch >= 'A' && ch <= 'Z') {
        Serial.print(ch);
        Serial.print(" ");
        Serial.println(letters[ch - 'A']);
        flashSequence(letters[ch - 'A']);

        lcd.setCursor(lineLength % 16, lineLength / 16);
        lcd.print(ch);
        lineLength++;

        if (lineLength >= 32) { // utilizes both rows on the LCD screen
          lcd.clear();
          lcd.setCursor(0, 0);
          lineLength = 0;
        }
      }

      else if (ch >= '0' && ch <= '9') {
        Serial.print(ch);
        Serial.print(" ");
        Serial.println(numbers[ch - '0']);
        flashSequence(numbers[ch - '0']);

        lcd.setCursor(lineLength % 16, 0);
        lcd.print(ch);
        lineLength++;

        if (lineLength >= 16) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lineLength = 0;
        }
      }

      else if (ch == ' ') {
        Serial.println("_");
        lcd.print(" ");
        lineLength++;

        if (lineLength >= 16) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lineLength = 0;
        }
      }

      else {
        // Unknown character entered
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.print("[Unknown char: ");
        Serial.print(ch);
        Serial.println("] LCD cleared.");
        lineLength = 0;
      }

      // After finishing input
      if (Serial.available() <= 0) {
        Serial.println();
        Serial.println("Enter text or Key in:");
        Serial.println("-------------------------------");
        keyboardText = false;
      }
  }
}

void flashSequence(char* sequence) {
  int i = 0;
  while (sequence[i] == '.' || sequence[i] == '-') {
    flashDotOrDash(sequence[i]);
    i++;
  }
}

void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  tone(tonePin, toneFreq);
  if (dotOrDash == '.') {
    delay(dotLength);
  } 
  else {
    delay(dashLength);
  }
  digitalWrite(ledPin, LOW);
  noTone(tonePin);
  delay(dotLength);
}