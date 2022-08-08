#include <thermistor.h>

int adc = A0; //An analog port number to be attached to the thermistor.
float pullup = 10000.0; //The ohms value of the fixed resistor (based on your hardware setup, usually 10k).
float referenceVoltage = 5.0; //Input voltage (3.3, 5, or something else if you're using a voltage divider).

thermistor therm(adc, pullup, referenceVoltage); // Analog pin which is connected to the thermistor, pullup resistor to setup the voltage divider, finally, reference voltage used as power supply of the voltage divider.

void setup()
{
    Serial.begin(9600); //Serial port initialized at 9600 Bauds.
}

void loop() 
{
    float temp = therm.analog2temp(); // Reading temperature using library methods
    Serial.print("Temperature: ");
    Serial.println(temp); // Printing temperature value in serial port
    delay(2000);
}