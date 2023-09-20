# Motion Sensor Control System

This Arduino project is designed to create a motion-activated control system using two buttons, a motion sensor, a buzzer, and a display. The project provides two main functionalities: a motion-activated light switch and a motion detector alarm.

## Table of Contents

- [Project Overview](#project-overview)
- [Components Needed](#components-needed)
- [Wiring Diagram](#wiring-diagram)
- [Libraries Used](#libraries-used)
- [Instalattion](#instalattion)
- [Usage](#usage)
- [License](#license)

## Project Overview
Have you ever wanted a light to automatically turn on when you enter a room or an alarm to sound when someone enters a restricted area? This Arduino project enables you to accomplish just that. The system presents two options on an attached display:

1. **Light Switch**: When this option is selected, the system will use a motion sensor to detect movement. If motion is detected, it will turn on a connected LED (connected to pin 7) to provide illumination. This is perfect for spaces like bathrooms, hallways, or closets, where you only want the light to be on when motion is detected.
2. **Motion Detector Alarm**: Choosing this option activates the motion sensor as well. If any motion is detected, a buzzer is triggered, functioning as an alarm. This feature can be used to secure an area and receive immediate alerts when someone enters.

## Components Needed

To build this project, you will need the following components:

- Arduino Uno board
- PIR (Passive Infrared) Motion Sensor
- Two Push Buttons
- Three LEDs
- Three 220Ω resistors
- Active buzzer
- NPN trasistor
- 1kΩ resistor
- Monochrome 0.96" OLED Graphic Display
- Jumper wires
- Breadboard or custom PCB for circuit assembly

## Wiring Diagram

[wiring diagram](./diagram.jpg)

There are a few details about how to connect the components:
- Every LED need to be wired with one 220Ω resistor
- Two LEDs will be used to show the choice, and one for light switch
- The buzzer will be connect with NPN trasistor and 1kΩ resistor
- All black wires are for ground, and all red wires are for 5V output

Pin connections:
- LED on pin 7
- one button on pin 9, other one on pin 10
- buzzer on pin 8
- sensor on pin 12
- OLED display on pins A0 and A1

## Libraries Used

This Arduino project utilizes several libraries to simplify the development process. Make sure to install these libraries in your Arduino IDE before uploading the sketch to your Arduino board.

- **SPI Library**: This library is used for communication with the OLED display via the Serial Peripheral Interface (SPI) protocol.

- **Wire Library**: The Wire library is essential for communication between the Arduino board and various I2C devices, such as the motion sensor and the OLED display.

- **Adafruit_GFX Library**: Adafruit's Graphics Library is used to draw text and graphics on the OLED display. It provides a range of functions for drawing shapes, text, and more.

- **Adafruit_SSD1306 Library**: The Adafruit SSD1306 library is designed specifically for OLED displays based on the SSD1306 controller. It makes it easy to initialize and interact with the display.

## Installation

1. Clone this repository to your local machine or download the project files as a ZIP archive.
2. Open the Arduino IDE and load the .ino sketch file from the project directory.
3. Ensure you have the necessary libraries installed (e.g., LiquidCrystal for the display).
4. Connect your Arduino board to your computer and select the correct board and port in the Arduino IDE.
5. Upload the sketch to your Arduino board.

## Usage

1. Connect all the components as per the [wiring diagram](#wiring-diagram).
Power up the Arduino board.

2. The display will show two options: "Light Switch" and "Motion Detector." Use the buttons to select your desired mode.

3. In "Light Switch" mode, the LED connected to pin 7 will turn on when motion is detected and turn off when no motion is detected.

5. In "Motion Detector" mode, the buzzer will sound when motion is detected, serving as an alarm.

6. Experiment with different settings and customize the project to suit your needs.

## License
This project is licensed under the MIT License - see the [LICENSE.md](./LICENSE.md) file for details.


