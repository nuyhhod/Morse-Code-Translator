# Documentation 

## 06/30/2025
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
#### Comment: I forgot I put a tester to verify that the buzzer and LEDs were working and it is no longer needed as it works as expected. 

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