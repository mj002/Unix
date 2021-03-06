#include "task.h"

timer::timer(int d)
{
	s_state = IDLE;
	insert(d, (object*)this);
}

timer::~timer()
{
	if (s_state != TERMINATED) task_error(E_TIMERDEL);
}

void
timer::reset(int d)
{
	remove();
	insert(d, (object*)this);
}

void
timer::print(int n, int baseClass)
{
	if (!baseClass)
		printf("timer %ld == clock+%ld\n",s_time,s_time-clock);

	sched::print(n, 1);
}

void
timer::resume()  // time is up; "delete" timer & schedule next task
{
	s_state = TERMINATED;
	alert();
	schedule();
}

void
timer::setwho(object*)
{
}

int timer::o_type()
{
	return TIMER;
}

