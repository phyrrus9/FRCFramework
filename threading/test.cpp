#include "WPILib.h"
#include "thread.h"

class test_thread : public thread
{
	void Entry(long _1, long _2, long _3, long _4, long _5, long _6, long _7, long _8, long _9, long _10)
	{
		DriverStationLCD *lcd;
		lcd = DriverStationLCD::GetInstance();
		lcd->Clear();
		lcd->Printf(DriverStationLCD::kUserLine1, "Hello from thread %d!" _1);
		lcd->UpdateLCD();
	}
};

class robot : public SimpleRobot
{
public:
	robot()//: (dont use heap vars in examples)
	{
	}

	void Autonomous()
	{
	}

	void OperatorControl()
	{
	}

	void Test()
	{
		test_thread test1("test1");
		test_thread test2("test2");
		test1.SetArg(1, 1);
		test2.SetArg(1, 2);
		test1.Run();
		Sleep(1); //wait so we dont go over
		test2.Run();
	}
};

START_ROBOT_CLASS(robot);
