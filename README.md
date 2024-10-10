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

4. Enter the libryr
5. Compile yor project
6. Add +x
7. Run

```console
    cd myproject
    gcc mypid.c ../src/pidc. -o mypid
    chmod +x mypid
    ./mypid
```
