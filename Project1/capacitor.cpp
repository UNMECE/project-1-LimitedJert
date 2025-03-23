#include "capacitor.h"
#include <iostream>
#include <iomanip>

void simulateConstantCurrent(Capacitor &cap, double I, double dt, int numSteps) {
    for (int i = 1; i < numSteps; ++i) {
        cap.time[i] = cap.time[i-1] + dt;
        cap.voltage[i] = cap.voltage[i-1] + I * dt / cap.C;
        cap.current[i] = I;  // Constant current
    }
}

void simulateConstantVoltage(Capacitor &cap, double V0, double R, double dt, int numSteps) {
    double RC = R * cap.C;
    for (int i = 1; i < numSteps; ++i) {
        cap.time[i] = cap.time[i-1] + dt;
        cap.current[i] = cap.current[i-1] - (cap.current[i-1] / RC) * dt;
        cap.voltage[i] = cap.voltage[i-1] + cap.current[i] * dt / cap.C;
    }
}

void printResults(const Capacitor &cap, int numSteps, int printInterval) {
    std::cout << std::setw(10) << "Time (s)" << std::setw(15) << "Voltage (V)" << std::setw(15) << "Current (A)" << std::endl;
    for (int i = 0; i < numSteps; i += printInterval) {
        std::cout << std::setw(10) << cap.time[i] 
                  << std::setw(15) << cap.voltage[i] 
                  << std::setw(15) << cap.current[i] << std::endl;
    }
}