#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>

using namespace std;

// ---------------- GPIO Definitions ----------------
#define PIR_PIN    0      // GPIO17 (wiringPi numbering)
#define SERVO_PIN  1      // GPIO18
#define MLX_ADDR   0x5A   // MLX90614 I2C address

int tempSensorFD;

// ---------------- Read Temperature ----------------
float readTemperature()
{
    int data = wiringPiI2CReadReg16(tempSensorFD, 0x07);
    
    if (data == -1)
    {
        cout << "Error reading temperature!" << endl;
        return -1;
    }

    float temperature = (data * 0.02) - 273.15;
    return temperature;
}

// ---------------- Open Door ----------------
void openDoor()
{
    cout << "Door Opening..." << endl;
    softPwmWrite(SERVO_PIN, 20);  // rotate to open
    delay(3000);
}

// ---------------- Close Door ----------------
void closeDoor()
{
    cout << "Door Closing..." << endl;
    softPwmWrite(SERVO_PIN, 5);   // rotate back
    delay(2000);
}

// ---------------- Main Program ----------------
int main()
{
    // Setup WiringPi
    wiringPiSetup();

    // Setup PIR
    pinMode(PIR_PIN, INPUT);

    // Setup Servo
    softPwmCreate(SERVO_PIN, 0, 200);

    // Setup Temperature Sensor (I2C)
    tempSensorFD = wiringPiI2CSetup(MLX_ADDR);

    if (tempSensorFD == -1)
    {
        cout << "Failed to initialize MLX90614 sensor!" << endl;
        return -1;
    }

    cout << "Contactless Smart Door System Started..." << endl;

    while (true)
    {
        if (digitalRead(PIR_PIN) == HIGH)
        {
            cout << "Motion Detected!" << endl;

            float temp = readTemperature();
            cout << "Measured Temperature: " << temp << " C" << endl;

            if (temp > 0 && temp < 37.5)
            {
                cout << "Access Granted" << endl;
                openDoor();
                closeDoor();
            }
            else if (temp >= 37.5)
            {
                cout << "High Temperature! Access Denied." << endl;
            }

            delay(3000);
        }

        delay(500);
    }

    return 0;
}