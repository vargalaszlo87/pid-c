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

```
gcc -c src/main.c -o build/main.o -I"include"
gcc -c src/signals.c -o build/signals.o -I"include" 
gcc -c src/operands.c -o build/operands.o -I"include" 
gcc -c src/outputs.c -o build/outputs.o -I"include" 
gcc -c src/adjust.c -o build/adjust.o -I"include"
gcc -c src/create.c -o build/create.o -I"include"
gcc build/main.o build/signals.o build/outputs.o build/adjust.o build/create.o -o bin/fGen.exe
```
