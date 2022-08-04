#ifndef _THERMISTOR_H_
#define _THERMISTOR_H_

#include <math.h>

class thermistor
{
    public:
        thermistor(int pin, float pullup, float referenceVoltage);
        float analog2temp();
    private:
        int _pin;
        int decimation = 4;
        int samples = (int)(pow(4, (float) decimation) + .5);
        float adcResolution = pow(2, (float)(10 + decimation));
        float _pullup;
        float _referenceVoltage;
        float beta = 3950.0;
        float defaultTemp = 25.0;
        float defaultResistance = 100000.0;
};

#endif