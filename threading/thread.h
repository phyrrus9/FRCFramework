#include "Task.h"
#ifndef __thread_h__
#define __thread_h__
	class thread : public Task
	{
		int args[10];
		int numargs;
		char tname[30];
		public:
			thread();
			void SetArg(int arg, int value); //set args
			void Run(); //start the thread
		private:
			virtual void Entry(long, long, long, long, long, long, long, long, long, long); //overload this with your function
	};
#endif
