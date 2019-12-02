#ifndef THREADED_TIMER
#define THREADED_TIMER

#include <Arduino.h>

#ifndef MBED_THREAD_H
	static_assert(false, "Threaded Timer is only supported on mbed based Arduinos");
#else
	using namespace rtos;
	using namespace events;
#endif // MBED_THREAD_H

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
		Thread _event_thread;
		EventQueue *_timer_queue;

};

#endif // THREADED_TIMER