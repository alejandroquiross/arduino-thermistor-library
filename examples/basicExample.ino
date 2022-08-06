#include <Thermistor.h>

Thermistor therm(A0, 10000.0, 5.0); // Analog pin which is connected to the thermistor, pullup resistor to setup the voltage divider, finally, reference voltage used as power supply of the voltage divider.

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