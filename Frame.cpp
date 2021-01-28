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
	if (isF)
	{
		duration<double> sec = GetNowTime - timePoint;
		if (sec.count() > fDelay)
		{
			timePoint = GetNowTime;
			if (++curF > endF)
			{
				curF = startF;
				return true;
			}
		}
		return false;
	}
	else
	{
		milliseconds sec = duration_cast<milliseconds>(GetNowTime - timePoint);
		if (sec.count() > fDelay)
		{
			timePoint = GetNowTime;
			if (++curF > endF)
			{
				curF = startF;
				return true;
			}
		}
		return false;
	}
}
