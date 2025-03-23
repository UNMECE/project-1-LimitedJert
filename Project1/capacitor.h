#ifndef CAPACITOR_H
#define CAPACITOR_H

struct _capacitor {
    double *time;       // time array
    double *voltage;    // voltage array
    double *current;    // current array
    double C;           // capacitance value
};
typedef struct _capacitor Capacitor;

// Function prototypes
void simulateConstantCurrent(Capacitor &cap, double I, double dt, int numSteps);
void simulateConstantVoltage(Capacitor &cap, double V0, double R, double dt, int numSteps);
void printResults(const Capacitor &cap, int numSteps, int printInterval);

#endif // CAPACITOR_H