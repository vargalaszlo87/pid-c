/*
 * PID-c v0.9.0 beta
 *
 * pidc.c
 *
 * PID controller in pure C.
 *
 * Copyright (C) 2024 Varga Laszlo
 *
 * https://github.com/vargalaszlo87/pid-c
 * http://vargalaszlo.com
 * http://ha1cx.hu
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Date: 2024-09-27
 */

#include <stdio.h>
#include <stdbool.h>

#include "../include/pidc.h"

// core
double PIDc(pidController* p) {
    // pid
    double error = p->signal.setPoint - p->signal.currentValue; // calc error
    p->integral += error * p->simulation.dt; // integrate error
    double derivative = (error - p->previousError) / p->simulation.dt; // derive error
    p->previousError = error; // refresh last error
    double controlSignal = p->Kp * error + p->Ki * p->integral + p->Kd * derivative;;

    // clamping
    if (p->clamping.set) {
        controlSignal = (controlSignal > p->clamping.highest) ? p->clamping.highest : controlSignal;
        controlSignal = (controlSignal < p->clamping.lowest) ? p->clamping.lowest : controlSignal;
    }

    return controlSignal;
}
