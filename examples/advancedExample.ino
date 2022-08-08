#include <thermistor.h>

int adc0 = A0; //An analog port number to be attached to the thermistor.
int adc1 = A1;
float pullup = 10000.0; //The ohms value of the fixed resistor (based on your hardware setup, usually 10k).
float referenceVoltage = 5.0; //Input voltage (3.3, 5, or something else if you're using a voltage divider).

thermistor therm1(adc0, pullup, referenceVoltage); // Analog pin which is connected to the thermistor, pullup resistor to setup the voltage divider, finally, reference voltage used as power supply of the voltage divider.
thermistor therm2(adc1, pullup, referenceVoltage);

void setup()
{
    Serial.begin(9600); //Serial port initialized at 9600 Bauds.
}

void loop() 
{
    float temp1 = therm1.analog2temp(); // Reading temperature using library methods
    float temp2 = therm2.analog2temp();
    Serial.print("Thermistor 1 temperature: ");
    Serial.println(temp1); // Printing temperature value in serial port
    Serial.print("Thermistor 2 temperature: ");
    Serial.println(temp2);
    delay(2000);
}