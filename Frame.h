#pragma once
class Frame
{
public:
	int curF = 0;
	int startF = 0;
	int endF = 0;
	double fDelay;

	system_clock::time_point timePoint;

	bool isF = false;

public:
	Frame();
	virtual ~Frame();

	void SetFrame(int start, int end, double delay)
	{
		curF = startF = start;
		endF = end;
		fDelay = delay;
		timePoint = GetNowTime;
	}
	bool Update();
	void operator()()
	{
		Update();
	}
};

