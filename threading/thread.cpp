#include "thread.h"

thread::thread(const char * name)
{
	for (int i = 0; i < 10; i++)
		args[i] = 0;
	sprintf(tname, "%s", name);
}

void thread::SetArg(int arg, int value)
{
	args[arg] = value;
}

void thread::Run()
{
	void (*func)(long, long, long, long, long, long, long, long, long, long) = &Entry;
	Task((const char *)tname, func, kDefaultPriority, 20000);
	Start(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
}
	
