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
	// ���࿡ ������� �ʴٸ�
	if (Empty() == false)
	{
		m_fTime += dt;
		// �������� ���� �� �κ��� �Լ��� ������
		auto scd = m_listSchedule.front();

		// �ش� �Լ��� ��������� �� ���� false = �Ϸ��̰ų� ����ð��� ������ �Ǹ�
		if (scd.first() == false || (scd.second != 0.f && m_fTime > scd.second))
		{
			m_fTime = 0.f; // �ð� �ʱ�ȭ
			m_listSchedule.pop_front(); // ������ ���ֱ�
		}
	}
}
