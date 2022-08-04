#include <thermistor.h>

thermistor therm1(A0, 10000.0, 5.0); // Analog pin which is connected to the thermistor, pullup resistor to setup the voltage divider, finally, reference voltage used as power supply of the voltage divider.
thermistor therm2(A1, 10000.0, 5.0);

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