#ifndef THREADED_TIMER
#define THREADED_TIMER

#include <Arduino.h>

#ifndef ARDUINO_ARCH_MBED
#	error "ThreadedTimer only runs on Mbed OS based boards"
#else
	using namespace rtos;
	using namespace events;
#endif // ARDUINO_ARCH_MBED

#define MAX_TIMERS 12

class ThreadedTimer
{
    public:
		ThreadedTimer();
        virtual ~ThreadedTimer();
        
        int every(long ms, void(*f_ptr)(void));
		int in(long ms, void(*f_ptr)(void));

		bool cancel(int id);
		int time_left(int id);

    private:
#ifdef MBED_THREAD_H
		Thread _event_thread;
		EventQueue *_timer_queue;
#endif // MBED_THREAD_H
};


#endif // THREADED_TIMER