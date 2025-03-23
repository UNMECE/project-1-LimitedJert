#include "capacitor.h"
#include <iostream>

int main() {
    const double dt = 1e-10;          // Time step
    const double finalTime = 5e-6;    // Final time
    const int numSteps = finalTime / dt;  // Number of timesteps
    const double R = 1e3;             // Resistance
    const double C = 100e-12;         // Capacitance
    const double I = 1e-2;            // Constant current
    const double V0 = 10.0;           // Constant voltage

    // Allocate memory for the capacitor
    Capacitor cap;
    cap.time = new double[numSteps];
    cap.voltage = new double[numSteps];
    cap.current = new double[numSteps];
    cap.C = C;

    // Initialize arrays
    cap.time[0] = 0.0;
    cap.voltage[0] = 0.0;
    cap.current[0] = I;  // Initial current for constant current case

    // Simulate constant current case
    simulateConstantCurrent(cap, I, dt, numSteps);
    std::cout << "Constant Current Case:" << std::endl;
    printResults(cap, numSteps, 200);

    // Re-initialize arrays for constant voltage case
    cap.time[0] = 0.0;
    cap.voltage[0] = 0.0;
    cap.current[0] = V0 / R;  // Initial current for constant voltage case

    // Simulate constant voltage case
    simulateConstantVoltage(cap, V0, R, dt, numSteps);
    std::cout << "\nConstant Voltage Case:" << std::endl;
    printResults(cap, numSteps, 200);

    // Free allocated memory
    delete[] cap.time;
    delete[] cap.voltage;
    delete[] cap.current;

    return 0;
}