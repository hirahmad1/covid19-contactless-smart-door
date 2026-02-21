Smart Door Access System, Contactless.

Project Description
The project was produced in 2021 amidst COVID -19, in order to display it at the Islamabad Science Fair Festival.
It is a noncontact smart door automation device that employs a Raspberry Pi. The system will be able to identify movement, scan temperature without touching body and control the door access in an automated manner to safeguard.

Project Objective
- Develop a contactless access system.
- Demonstrate how embedded systems are automatable.
- Offer a safety-based technology.
- How to integrate sensors in real-time.

Components Used
- Raspberry Pi
- MLX90614 infrared Thermometer unit.
- PIR motion sensor
- Servo motor
- WiringPi library
- C++ programming language

Working Principle
- The sensor comprises of the PIR that detects human movement close to the door.
- The IR temperature sensor senses the body temperature.
- The door opens automatically when the temperature is lower than 37.5 0 C.
- In the event of high temperature, access is refuse.
- The identity of the servo motor is the door opening and closing.

Software Requirements
- Raspberry Pi OS
- WiringPi library
- C++ compiler (g++)

Hardware Connections
- PIR sensor → GPIO Pin 17
- Servo motor → GPIO Pin 18
- MLX90614 sensor → I²C SDA and SCL pins

Setup Instructions
Enable the I²C interface

sudo raspi-config

Then turn on I 2c on the interface.

Install Required Libraries

sudo apt-get update
apt-get sudo apt-get install wiringpi

Compile Code

g++ main.cpp -o smartdoor -lwiringPi

Run Program

sudo ./smartdoor

Features
- Contactless entry system
- Temperature controllers in real time.
- Automatic door control
- Embedded system based automation.

Future Improvements
- Add face recognition interface.
- Install a mobile monitoring system.
- Log data to a cloud database
- Use AI for authentication

Developer Note
In 2021, embedded systems and C++ were used to create the system at the science fair at PNCA.