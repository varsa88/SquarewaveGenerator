# SquarewaveGenerator
A simple Arduino program for generating square wave signals with adjustable frequency via serial input using Timer1.

## Description
This project generates a square wave signal using Timer1 on an Arduino. The frequency of the square wave can be adjusted via serial input, making it a versatile tool for signal generation and testing.

## Features
- Adjustable square wave frequency via serial input.
- Uses Timer1 library for PWM signal generation.
- Easy-to-configure pin and frequency settings.

## Getting Started

### Prerequisites
- Arduino IDE installed on your computer.
- TimerOne library installed in the Arduino IDE.

### Installation
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/varsa88/SquarewaveGenerator.git
   ```
2. Open the `SquarewaveGenerator` project in the Arduino IDE.
3. Ensure the TimerOne library is installed. If not, install it via the Arduino Library Manager.

## Usage
1. Connect your Arduino to your computer.
2. Open the `main.cpp` file in the Arduino IDE.
3. Upload the code to your Arduino board.
4. Open the Serial Monitor in the Arduino IDE and set the baud rate to `9600`.
5. Enter a frequency value (in Hz) in the Serial Monitor and press Enter. The square wave signal will adjust to the specified frequency.

## File Structure
- `src/main.cpp`: Main program file for generating square wave signals.
- `lib/TimerTwo-master/`: Contains the TimerTwo library (optional alternative to TimerOne).
- `platformio.ini`: Configuration file for PlatformIO.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## License
This project is licensed under the MIT License. See the LICENSE file for details.