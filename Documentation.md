# Documentation 

## 06/30/2025
#### Created project on Github and started on project planning.

### 3:16 PM PST
#### Completed project planning and started wiring.
#### Writing down parts list and searching documentation for each component. 

### 6:03 PM PST
#### Wired all pins to LCD screen successfully. 
#### Wired all pins to LED lights, push button, and potentiometer successfully.
#### Note to buy buzzer for audio output for morse code. 

### 6:32 PM PST 
#### Started code using Arduino IDE.

### 9:56 PM PST 
#### Completed code. 
#### Searching for bugs and working towards optimization.

### 10:22 PM PST
Added:
    else {
        // Unknown character entered
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.print("[Unknown char: ");
        Serial.print(ch);
        Serial.println("] LCD cleared.");
        lineLength = 0;
    }

#### Comment: I wanted to make it so that if I input a symbol in the Serial Monitor such as a colon, or period, or hashtag. The LCD screen would clear, rather than pressing the button 8 times. 

### 11:43 PM PST
Removed: 
In: 
void setup() {
    // Test the LED and tone
    tone(tonePin, toneFreq);
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    noTone(tonePin);
    delay(600);
.... }
#### Comment: I forgot I put a tester to verify that the buzzer and LEDs were working and it is no longer needed as it works as expected. *Tested Buzzer using TinkerCAD because I don't have a buzzer on me right now. 

## 07/01/2025
### 12:01 AM PST
#### Added to README.md document

### 12:37 AM PST
Changed:
    if (lineLength >= 16) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lineLength = 0;
    }

To: 
    if (lineLength >= 32) { // utilizes both rows on the LCD screen
      lcd.clear();
      lcd.setCursor(0, 0);
      lineLength = 0; 
    }
#### Comment: Previously, I was only using the first row of the LCD screen. My next implementation is to make a scrolling LCD screen to have a better user experience.

### 12:57 AM PST 
#### Completed README.md document
