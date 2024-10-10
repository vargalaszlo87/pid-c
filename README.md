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
