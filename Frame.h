#pragma once
class Frame
{
public:
	int curFrame   = 0;
	int startFrame = 0;
	int endFrame   = 0;
	double delay   = 0.f;

	Time timePoint;

	bool isDone = true;

public:
	void SetFrame(int _start, int _end, double _delay)
	{
		curFrame  = startFrame = _start;
		endFrame  = _end;
		delay	  = _delay;
		timePoint = GetNowTime;
	}
	bool Update();
	void operator()()
	{
		Update();
	}

public:
	Frame();
	virtual ~Frame();
};

