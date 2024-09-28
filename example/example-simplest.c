#include <stdio.h>
#include "../include/pidc.h"

int main()
{

    /* the simplest example
     *
     * The PIDc controller get a set point and must reach it.
     *
     * */

    pidController pid = {1.0, 0.1, 0.5};

    pid.signal.setPoint = 10.0;
    pid.signal.currentValue = 0.0;

    pid.simulation.time = 0.0;
    pid.simulation.dt = 0.1;
    pid.simulation.endTime = 10.0;

    while (pid.simulation.time < pid.simulation.endTime) {

        double controlSignal = PIDc(&pid);
        pid.signal.currentValue += controlSignal * pid.simulation.dt;
        printf ("%lf\n",pid.signal.currentValue);

        pid.simulation.time += pid.simulation.dt;
    }

    return 0;
}
