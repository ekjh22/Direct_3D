#pragma once

// Singleton Pattern이라는 디자인 패턴을 사용함
// 아마 유니티 사용하는 애들은 대부분 해봤다고 생각함
// 해당 클래스를 정적으로 만들어서 메모리 저장 위치를 프로그램이 끝났을 때 파괴되는 것으로 바꿔서 다른 클래스에서도
// public 범위인 변수 및 함수들은 사용할 수 있도록 해주는 클래스
// 요약 : 해당 클래스를 상속해주면 그 클래스의 public 범위인 변수 및 함수를 사용할 수 있음 
// 대신에 Instance를 만들어줘야 편하게 사용가능
// 상속하는 법 : class CCameraManager : public CSingleton< CCameraManager>
// 인스턴스 만드는 법 : #define CAMERA (*CCameraManager::GetInstance())
// 인스턴스 사용법 : CAMERA.Update() 이런식 !
template <class T>
class CSingleton
{
public:
	CSingleton(){}
	virtual ~CSingleton(){}

public:
	static T* p; 

public:
	// T 클래스의 객체 값을 가져옴
	static T * GetInstance()
	{
		if (!p)
			p = new T();
		return p;
	} 
	// T 클래스의 만들어진 객체 값을 초기화
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
};

// p 변수 초기화 (이거 필수임)
template <class T>
T * CSingleton<T>::p = nullptr;