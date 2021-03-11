#pragma once

// 추상 클래스 : 해당 클래스가 있다고 가정을 함 자료형과 함수를 사용할 수 있음
class CTransform; 
class CObject;

// Unity에서 사용하는 Component 패턴과 비슷함
// 컴포넌트 패턴은 구글에 "C++ Coponent Pattern"을 검색해보는걸 추천함
class CComponent
{
public:
	CComponent();
	virtual ~CComponent();

public:
	// virtual 과 PURE를 같이 붙이면 순수가상함수로
	// 일반적인 가상함수는 강제성이 붙지않지만 순수가상함수는 강제성이 붙어 PURE키워드가 붙었다면
	// 상속을 했을 때 무조건 생성시켜줘야함

	// 가장 맨처음에 실행되는 함수 ( 사용하는 이유? : 기본적인 변수 셋팅 )
	virtual void Awake() PURE;

	// Awake후에 실행되는 함수 ( 사용하는 이유? : 오브젝트 생성 및 셋팅된 변수를 이용하는 다음 셋팅단계 )
	virtual void Start() PURE;

	// 매 프레임마다 계속 실행되는 함수 ( 사용하는 이유? : 연산적인 부분을 할 떄 사용함 )
	virtual void Update() PURE;
	
	// Update가 호출된 뒤 매 프레임마다 계속 실행되는 함수 ( 사용하는 이유? : Update가 실행된 뒤 사용할 연산적인 부분을 할 때 사용함 )
	virtual void LateUpdate() PURE;

	// 매 프레임마다 계속 실행되는 함수 ( 사용하는 이유 : 그래픽적인 부분을 할 때 사용함 )
	virtual void OnRender() PURE;

	// 파괴될 때 호출되는 함수 ( 사용하는 이유 : 할당된 값을 해제해줄 때 사용 해제해주지 않고 계속 프로그램을 실행시켜주면 메모리 누수가 발생해 프로그램이 고장날 수 있음 )
	virtual void OnDestroy() PURE;

	// 콜라이더가 존재할 경우 해당 _pObj가 해당 오브젝트에 충돌했을 때 사용할 코드를 적는 함수
	virtual void OnCollisionEnter(CObject * _pObj) PURE;

	// 콜라이더가 존재할 경우 해당 _pObj가 해당 오브젝트에 충돌중일 때 사용할 코드를 적는 함수
	virtual void OnCollisionStay(CObject * _pObj) PURE;

	// 콜라이더가 존재할 경우 해당 _pObj가 해당 오브젝트에 충돌이 끝났을 때 사용할 코드를 적는 함수
	virtual void OnCollisionExit(CObject * _pObj) PURE;

public:
	bool m_bEnable = true; // 현재 사용중인가 ?

	CTransform * tf = nullptr; // 컴포넌트의 기본적인 자신의 트랜스폼 위치값 ( Unity에서 빈 오브젝트를 생성하면 기본적으로 트랜스폼 컴포넌트가 있음 )
	CObject * go = nullptr; // 컴포넌트이 기본적인 자기 자신을 가르키는 오브젝트 ( Unity에서 생성하는 모든것들은 오브젝트이기 때문에 존재함 [ C++의 this, Unity의 gameObject와 똑같음 ] )

	// AddComponent : 자신의 컴포넌트를 추가함
	template<class T>
	T* ac()
	{
		return go->ac<T>();
	}

	// GetComponent : 자신의 컴포넌트를 가져옴
	template<class T>
	T* gc()
	{
		return go->gc<T>();
	}
};

