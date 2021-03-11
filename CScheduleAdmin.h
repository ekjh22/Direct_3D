#pragma once
using Schedule = function<bool()>;

// 간단하게 설명하자면 여러개의 함수들을 저장해놨다가 해당 시간이 지나면 순서대로 실행시키게 해주는 아주 편리한 클래스
class CScheduleAdmin
{
public:
	CScheduleAdmin();
	~CScheduleAdmin();

private:
	list<pair<Schedule, float>> m_listSchedule; // 함수를 담아두는 리스트
	float m_fTime = 0.f; // 현재 시간
public:
	/// <summary>
	/// 스케쥴 추가
	/// </summary>
	/// <param name="_Schedule">리스트에 넣을 함수</param>
	/// <param name="_fDuraction">스케쥴 지속 시간</param>
	void Add(Schedule _Schedule, float _fDuraction = 0.f);
	
	// 스케쥴가 비어있는가 ?
	bool Empty();

	// 스케쥴 초기화
	void Clear();

	// 스케쥴 딜레이 셋팅
	void Delay(float _fTime);
	
	// 매 프레임마다 실행되는 함수
	void Update();

};

