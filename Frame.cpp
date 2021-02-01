#include "DXUT.h"
#include "Frame.h"

Frame::Frame()
{
}

Frame::~Frame()
{
}

bool Frame::Update()
{
	if (!isDone)
	{
		duration<double> sec = GetNowTime - timePoint;
		if (sec.count() > delay)
		{
			timePoint = GetNowTime;
			if (++curFrame > endFrame)
			{
				curFrame = startFrame;
				return true;
			}
		}
		return false;
	}
	else
	{
		milliseconds sec = duration_cast<milliseconds>(GetNowTime - timePoint);
		if (sec.count() > delay)
		{
			timePoint = GetNowTime;
			if (++curFrame > endFrame)
			{
				curFrame = startFrame;
				return true;
			}
		}
		return false;
	}
}
