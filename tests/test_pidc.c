#include <stdio.h>
#include <assert.h>
#include "../include/pidc.h"

//
// Test created by vargalaszlo87 on 2024. 09. 28.
//

// test function
void test_PIDc() {
    pidController pid = {0};

    // set parameters
    pid.signal.setPoint = 10.0;
    pid.signal.currentValue = 5.0;
    pid.simulation.dt = 1.0;
    pid.Kp = 1.0;
    pid.Ki = 0.1;
    pid.Kd = 0.0;
    pid.integral = 0.0;
    pid.previousError = 0.0;
    pid.clamping.set = 0;

    // expected value
    double expectedControlSignal = 5.5;

    // PID call
    double result = PIDc(&pid);

    // Assert
    assert(result == expectedControlSignal && "PID calculation failed");
    printf("Test passed!\n");
}

int main() {
    test_PIDc();
    return 0;
}