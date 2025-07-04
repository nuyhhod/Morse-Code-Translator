# Morse-Code-Decoder
- Project Start: 06/30/2025
- Project Completion: Ongoing

This project is an interactive **Morse code encoder and decoder** using an **Arduino Uno**, **LCD screen (parallel, non-I2C)**, **LED**, **buzzer** (optional), and **push button**. It allows the user to input Morse code via a button, get real-time visual and audio feedback, and see the decoded characters on the LCD screen and Serial Monitor. You can also type characters via Serial to see them encoded in Morse using LED and sound.

## Demonstration
// Youtube video on how to make this project and circuit demonstration.

## Circuit Diagram and Wiring
![Schematic of Circuit](https://github.com/nuyhhod/Morse-Code-Translator/blob/9d123ddded6b811785c06bc755c62aac9147b610/image_2025-07-01_003110124.png)  

![TinkerCAD Diagram of Wiring of Arduino and All Components](https://github.com/nuyhhod/Morse-Code-Translator/blob/c11989aae97acd99fd560e3365566f5302199113/Copy%20of%20Slide%20Switch.png)

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


## Wiring Guide for LCD Pins

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

## Wiring Guide for Electronic Components

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

## Author 
Elliot Kang 
- Education: Electrial Engineering at Virginia Tech 
- Linkedin: https://www.linkedin.com/in/elliotkang
