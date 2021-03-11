#pragma once
using Schedule = function<bool()>;

// �����ϰ� �������ڸ� �������� �Լ����� �����س��ٰ� �ش� �ð��� ������ ������� �����Ű�� ���ִ� ���� ���� Ŭ����
class CScheduleAdmin
{
public:
	CScheduleAdmin();
	~CScheduleAdmin();

private:
	list<pair<Schedule, float>> m_listSchedule; // �Լ��� ��Ƶδ� ����Ʈ
	float m_fTime = 0.f; // ���� �ð�
public:
	/// <summary>
	/// ������ �߰�
	/// </summary>
	/// <param name="_Schedule">����Ʈ�� ���� �Լ�</param>
	/// <param name="_fDuraction">������ ���� �ð�</param>
	void Add(Schedule _Schedule, float _fDuraction = 0.f);
	
	// �����찡 ����ִ°� ?
	bool Empty();

	// ������ �ʱ�ȭ
	void Clear();

	// ������ ������ ����
	void Delay(float _fTime);
	
	// �� �����Ӹ��� ����Ǵ� �Լ�
	void Update();

};

