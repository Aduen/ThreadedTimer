# ThreadedTimer
Threaded Timer is a mbed os wrapper for EventQueue and Thread for usage on mbed Arduino boards like the 
* Nano 33 Ble
* Nano 33 Ble Sense


Usage of the library is much like other Timing libraries on the Arduino community network. The big advantage of using the mbed os based implementation is Threading. A single ThreadedTimer runs in its own Thread and multiple Threaded Timers can run parallel without delaying each other. The 'basic' example shows the benefit ot this approach.

```c++
#include <threadedtimer.h>

ThreadedTimer t1;

int task1;

//executing in Timer Thread
void hello()
{
	Serial.println("hello");
}

void setup()
{
	Serial.begin(115200);
	delay(200);
  
  	//execute hello() function every 1000 milliseconds
	task1 = t1.every(1000, hello);
}

void loop()
{
	delay(5000); //main loop delay does not affect the running Timers
  	Serial.println("hello again");
}
```
