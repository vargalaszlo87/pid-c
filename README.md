# pid-c
PID-c is a native PID controller in pure C.


## Features

The data struct of this project is flexible, you can with simple data or for example measured datas.

**`CLAMPING`** 
-  Unfortunately, the output of the PID controller can increase beyond all limits (because of D member) , so you can use up and down limit.

```C
    pid.clamping.highest = 1.0;
    pid.clamping.lowest = -1.0;
```

## Getting started

#### Clone source

```
git clone https://github.com/vargalaszlo87/fGen.git
```

#### Self compiling

1. Make a work directory
2. Copy the src and include directories to the working directory.
3. Make a (for example) myproject directory and .c file inside it.


Folder system:

```properties
│
├── src/
│   └── pidc.c
│
├── include/
│   └── pidc.h
│
└── myproject/
    └── mypid.c
```

mypid.c for example:

```c
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
```

4. Enter the library
5. Compile your project
6. Add +x
7. Run

```console
    cd myproject
    gcc mypid.c ../src/pidc. -o mypid
    chmod +x mypid
    ./mypid
```

#### Self compiling with static library


1. Make a work directory
2. Copy the **pidc.h** (from include) and the **pidc.a** to the working directory.
3. Make a mypid.c file.

Folder system:

```properties
│
└── myproject/
    └── mypid.c
    └── pidc.a
    └── pidc.h
```

4. Enter the library
5. Compile your project
6. Add +x
7. Run

```console
    cd myproject
    gcc -o mypid mypid.c -L. libpidc.a
    chmod +x mypid
    ./mypid
```


