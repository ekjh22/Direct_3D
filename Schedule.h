#pragma once
using Sc = function<bool()>;
class Schedule
{
public:
	queue<Sc> qSchedule;
public:
	Schedule() {}
	virtual ~Schedule()
	{
	}

	void AddSc(Sc sc)
	{
		qSchedule.push(sc);
	}

	void Update()
	{
		if (!qSchedule.empty())
		{
			if (qSchedule.front()() == false)
			{
				qSchedule.pop();
			}
		}
	}
};