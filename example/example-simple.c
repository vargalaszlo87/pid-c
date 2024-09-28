#include <stdio.h>
#include "../include/pidc.h"

double exampleSimpleMotorFunction(double controlSignal, double currentValue) {
    double resistance = 0.1;
    double inertia = 1.0;
    double acceleration = (controlSignal - resistance * currentValue) / inertia;
    return acceleration;
}

int main()
{

    /* simple example
     *
     * The PIDc controller is given a set point and a process to control
     * and must reach it.
     *
     * */

    pidController pid = {1.0, 0.1, 0.5};
    pid.clamping.set = true;
    pid.clamping.highest = 1.0;
    pid.clamping.lowest = -1.0;

    pid.signal.setPoint = 10.0;
    pid.signal.currentValue = 0.0;

    pid.simulation.time = 0.0;
    pid.simulation.dt = 0.1;
    pid.simulation.endTime = 20.0;

    while (pid.simulation.time < pid.simulation.endTime) {

        double controlSignal = PIDc(&pid);
        pid.signal.currentValue += exampleSimpleMotorFunction(controlSignal, pid.signal.currentValue);
        printf ("%lf\n",pid.signal.currentValue);

        pid.simulation.time += pid.simulation.dt;
    }

    return 0;
}
