/**
* This examples uses two timers, each timer executes in its own thread. For more 
* information on Threading in mbed os, visit the documentation on https://os.mbed.com/
**/

#include <threadedtimer.h>

#define PWM_PIN 10

ThreadedTimer t1;
ThreadedTimer t2;

String name = "threaded-timer";
int thing = 0;

int task1, task2, longtask3;

//executing in Timer Thread 1
void hello()
{
	Serial.println("hello ");
	thing++;
}

//executing in Timer Thread 2
void dim_led()
{
	digitalWrite(PWM_PIN, LOW);
	for (int i = 0; i < 255; i++)
	{
		analogWrite(PWM_PIN, i);
		delay(10);
	}
}

//executing in Timer Thread 1
void hello_you()
{
	Serial.print(name);
	Serial.println(thing);
}

void setup()
{
	Serial.begin(115200);
	delay(200);
	
	pinMode(PWM_PIN, OUTPUT);

	task1 = t1.every(1000, hello);
	task2 = t1.every(1000, hello_you);

	//this task takes 2550ms to complete, move to seperate timer thread
	longtask3 = t2.every(3000, dim_led);
}

void loop()
{
	delay(2000); //main loop delay does not affect the running Timers
	Serial.println(thing);
}
