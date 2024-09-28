/*
 * PID-c v0.9.0 beta
 *
 * pidc.h
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
#include <stdlib.h>
#include <stdbool.h>

#ifndef PIDC_H
#define PIDC_H

// variables
typedef struct {
    double
        Kp,
        Ki,
        Kd,
        integral,
        previousError;
    struct {
        size_t size;
        double
                setPoint,
                currentValue,
                dt,
                output;
    } signal;
    struct {
        double
                dt,
                time,
                endTime;
    } simulation;
    struct {
        bool set;
        double highest;
        double lowest;
    } clamping;
} pidController;

// core
double PIDc(pidController*);

#endif // PIDC_H
