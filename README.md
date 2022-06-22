# uart
Simple C library to enable creating ang manipulating circular buffers.

# Build
To build and install the library on your system, just use:
```console
foo@bar:~$ make clean;make; sudo make install
```
You can skip the make install part and copy the .a output file as well as the header file to your project to link it statically with your code
# Usage
Once the library is installed on your system or after adding the header file and the .a file to your project, you can use it like this.

First import the header files
```c
#include <circular_buffer.h>
```
if you are using c++, make sure you add extern "C" protection
```cpp
#ifdef __cplusplus
extern "C"
{
#endif
    // circular_buffer library
    #include <circular_buffer.h>
#ifdef __cplusplus
}
#endif
```
For now we support two kinds of circular buffers. The first one is integer circular buffer. The second one is float circular buffer.

To declare an integer circular buffer, you can use:
```c
// UART configuration
iCircularBuffer icb;
```
To declare a float circular buffer, you can use:
```c
// UART configuration
fCircularBuffer fcb;
```

This declaration is not sufficient as you need to initialize the buffer (allocate the required memory and initialize buffer pointers).
We use this for ints:
```c
icb_init(&icb, 100);// the second parameter is the  size of the buffer
```
We use this for floats:
```c
fcb_init(&icb, 100);// the second parameter is the  size of the buffer
```

For the rest of this file, we will use only the float version. For the integer just change the fcb_ to icb_.

To push data to the buffer, use:

```c
fcb_push(&icb, 100);// the second parameter is the value to push to the buffer
```

To access a value at a position (time position and not just the position in the buffer). Use:

```c
fcb_get_at(&icb, 5)
```

We can compute the minimal, maximal and mean value of the content of the buffer just by using


```c
//print the minimal value
printf("min value %f", icb_min(&fcb));
//print the maximal value
printf("min value %f", icb_max(&fcb));
//print the mean value
printf("min value %f", icb_mean(&fcb));
```


We can also compute the position of minimal and maximal value

To remove a value from the buffer, use this:

```c
icb_remove_at_timeindex(&fcb,1);// The second value is the time index (in the order of pushes at the current window) 
```
# Complete example
You can find a full example in examples folder.

# Information
This is one of multiple libraries I have developed to simplify some tasks we do with C on linux. The objective is for it to be open source, eazy to use and compatible with both c and cpp. The build system is make and is compatible with gcc building system. It is very eazy to use this with cmake or other build systems. All these libraries have been tested on raspberry pi with raspbian. They help starting a new application that requires configuration, communication with arduino tools and spreading information between multiple services on the raspberry pi.

The licence is MIT, so you can use this code in your projects without worrying about licence contamination that could happen when using GPL licences. So you still can use it for free in commercial applications.

Tests and bugfixes are welcome. Just clone it, repare it and send a pull request. I want to keep this code as clean and simple as possible so please avoid feature creaping.

# Useful links
Check out my [cfg library](https://github.com/ParisNeo/cfg) built in the same spirit as this library.
Check out my [udp library](https://github.com/ParisNeo/udp) built in the same spirit as this library.
Check out my [uart library](https://github.com/ParisNeo/uart) built in the same spirit as this library.



