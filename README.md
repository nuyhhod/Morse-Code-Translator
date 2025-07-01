# Morse-Code-Decoder

This project is an interactive **Morse code encoder and decoder** using an **Arduino Uno**, **LCD screen (parallel, non-I2C)**, **LED**, **buzzer** (optional), and **push button**. It allows the user to input Morse code via a button, get real-time visual and audio feedback, and see the decoded characters on the LCD screen and Serial Monitor. You can also type characters via Serial to see them encoded in Morse using LED and sound.

## Demonstration
// Make a Youtube Video on how to make it and demonstration

## Circuit Diagram and Wiring
![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.]("C:\Users\ellio\Downloads\Morse Code Translator.pdf")



## TinkerCAD Link
https://www.tinkercad.com/things/htvYGKYqThV-morse-code-translator 



## Features 
- Encode Morse code by typing text into the **Serial Monitor**
- Decoding Morse code entered via a **push button**
- Real-time **audio (buzzer)** and **visual (LED)** Morse feedback
- **Decoded English characters** displayed on:
  - LCD screen (16x2, parallel mode)
  - Serial monitor
- **Morse encoding**: Type letters/numbers via Serial to see Morse output
- Automatically detects:
  - End of character (pause ≥ 720ms)
  - End of word (pause ≥ 1680ms)
- **LCD screen output**:
  - Uses both rows (up to 32 characters)
  - Clears automatically after reaching full capacity
- **Special actions**:
  - Typing an **invalid character** (e.g., `@`, `#`) clears the LCD
  - Inputting `........` via button also clears the LCD
  - Pressing **Enter** in Serial Monitor inserts a space

## Hardware Components

| Component        | Description                      |
|------------------|----------------------------------|
| Arduino Uno/Nano | Microcontroller board            |
| 16x2 LCD         | Parallel interface (no I2C)      |
| Push Button      | For Morse input                  |
| LED              | Visual Morse signal              |
| Buzzer           | Audio Morse signal               |
| Potentiometer    | LCD contrast control             |
| 220Ω Resistor    | For LED backlight or signal pin  |
| Breadboard + Wires | For connections                |


## Wiring Guide

| LCD Pin | Arduino Pin | Description         |
|---------|-------------|---------------------|
| RS      | 12          | Register Select     |
| RW      | GND         | Write-only mode     |
| E       | 11          | Enable              |
| D4      | 5           | Data 4              |
| D5      | 4           | Data 5              |
| D6      | 3           | Data 6              |
| D7      | 2           | Data 7              |
| VSS     | GND         | Ground              |
| VDD     | 5V          | Power               |
| V0      | Potentiometer middle pin |Controls Visibility|
| A (LED+) | 5V via 220Ω | LCD backlight      |
| K (LED-) | GND         | LCD backlight GND  |
|-----------------------------------------------|
|Components | Arduino Pin | Description         |
|-----------|-------------|---------------------|
| Potentiometer (middle pin) | LCD V0 | Controls Visibility |
| Buzzer     |   10        | Sound               |
| Button     |  8        | On/Off               |
| LED        | 13          | Light to Output Visual      |
## Controls (How to use the )

- **Hold the button**:
  - Short Press (<240ms): **dot (.)**
  - Long Hold Press (≥240ms): **dash (-)**
- **Pause between inputs**:
  - ≥720ms = Letter Complete
  - ≥1680ms = Word Space