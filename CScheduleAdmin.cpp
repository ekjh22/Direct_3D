#include "DXUT.h"
#include "CScheduleAdmin.h"


CScheduleAdmin::CScheduleAdmin()
{
}


CScheduleAdmin::~CScheduleAdmin()
{
	m_listSchedule.clear();
}

void CScheduleAdmin::Add(Schedule _Schedule, float _fDuraction)
{
	m_listSchedule.push_back({ _Schedule, _fDuraction });
}

bool CScheduleAdmin::Empty()
{
	return m_listSchedule.empty();
}

void CScheduleAdmin::Clear()
{
	m_listSchedule.clear();
}

void CScheduleAdmin::Delay(float _fTime)
{
	Add([]()->bool {return true; }, _fTime);
}

void CScheduleAdmin::Update()
{
	// 만약에 비어있지 않다면
	if (Empty() == false)
	{
		m_fTime += dt;
		// 스케쥴의 가장 앞 부분의 함수를 가져옴
		auto scd = m_listSchedule.front();

		// 해당 함수를 실행시켰을 때 값이 false = 완료이거나 실행시간이 끝나게 되면
		if (scd.first() == false || (scd.second != 0.f && m_fTime > scd.second))
		{
			m_fTime = 0.f; // 시간 초기화
			m_listSchedule.pop_front(); // 스케쥴 빼주기
		}
	}
}
