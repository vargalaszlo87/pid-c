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

    /* example with reference values
     *
     * The PID controller is given a more reference values to for example
     * a control and must reach it.
     *
     * */

    pidController pid = {1.0, 0.1, 0.01};
    pid.clamping.set = true;
    pid.clamping.highest = 1;
    pid.clamping.lowest = -1;

    pid.signal.setPoint = 10.0;
    pid.signal.currentValue = 0.0;

    pid.simulation.time = 0.0;
    pid.simulation.dt = 0.1;
    pid.simulation.endTime = 10.0;

    // for example reference values for control
    double inputs[] = {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,
        9,9,9,9,9,9,9,9,9,9,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1
    };

    int i = 0;
    while (pid.simulation.time < pid.simulation.endTime) {

        pid.signal.setPoint = inputs[i];

        double controlSignal = PIDc(&pid);
        pid.signal.currentValue += exampleSimpleMotorFunction(controlSignal, pid.signal.currentValue);
        printf ("%lf -> %lf\n",pid.signal.setPoint, pid.signal.currentValue);

        pid.simulation.time += pid.simulation.dt;
        i++;
    }

    return 0;
}
