#include <threadedtimer.h>

ThreadedTimer::ThreadedTimer()
{	
	_timer_queue = new EventQueue(MAX_TIMERS * EVENTS_EVENT_SIZE);
	_event_thread.start(callback(_timer_queue, &EventQueue::dispatch_forever));
}

int ThreadedTimer::every(long ms, void(*f_ptr)(void))
{
	return _timer_queue->call_every(ms, f_ptr);
}

int ThreadedTimer::in(long ms, void(*f_ptr)(void))
{
	return _timer_queue->call_in(ms, f_ptr);
}

int ThreadedTimer::time_left(int id)
{
	return _timer_queue->time_left(id);
}

bool ThreadedTimer::cancel(int id)
{
	return _timer_queue->cancel(id);
}

ThreadedTimer::~ThreadedTimer()
{
	_timer_queue->break_dispatch();
	_event_thread.join();
}