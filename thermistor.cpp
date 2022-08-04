#include <Arduino.h>
#include <math.h>
#include <thermistor.h>

/**
 * This function sets the pin mode to input, sets the pin number, sets the pullup resistor value, and
 * sets the reference voltage
 * 
 * @param pin The pin number that the thermistor is connected to.
 * @param pullup The value of the pullup resistor in ohms.
 * @param referenceVoltage The voltage of the power supply that the thermistor is connected to.
 */

thermistor::thermistor(int pin, float pullup, float referenceVoltage) 
{
    pinMode(pin, INPUT);
    _pin = pin;
    _pullup = pullup;
    _referenceVoltage = referenceVoltage;
}

/**
 * Read the analog value from the pin, convert it to a voltage, convert the voltage to a resistance,
 * convert the resistance to a temperature
 * 
 * @return The temperature in degrees Celsius.
 */

float thermistor::analog2temp() 
{
    int raw = 0;
    for (int i = 0; i < 10; i++) for(int j = 0; j < samples; j++) raw += analogRead(_pin);
    raw = (raw / 10);
    raw = raw >> decimation;
    float voltage = raw * (5.0 / adcResolution);
    float thermistorResistance = (_pullup * voltage) / (_referenceVoltage - voltage);
    float celsius = (1 / ((log(thermistorResistance / defaultResistance) / beta) + (1 / (defaultTemp + 273.15)))) - 273.15;
    return celsius;
}