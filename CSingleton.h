#pragma once

// Singleton Pattern�̶�� ������ ������ �����
// �Ƹ� ����Ƽ ����ϴ� �ֵ��� ��κ� �غôٰ� ������
// �ش� Ŭ������ �������� ���� �޸� ���� ��ġ�� ���α׷��� ������ �� �ı��Ǵ� ������ �ٲ㼭 �ٸ� Ŭ����������
// public ������ ���� �� �Լ����� ����� �� �ֵ��� ���ִ� Ŭ����
// ��� : �ش� Ŭ������ ������ָ� �� Ŭ������ public ������ ���� �� �Լ��� ����� �� ���� 
// ��ſ� Instance�� �������� ���ϰ� ��밡��
// ����ϴ� �� : class CCameraManager : public CSingleton< CCameraManager>
// �ν��Ͻ� ����� �� : #define CAMERA (*CCameraManager::GetInstance())
// �ν��Ͻ� ���� : CAMERA.Update() �̷��� !
template <class T>
class CSingleton
{
public:
	CSingleton(){}
	virtual ~CSingleton(){}

public:
	static T* p; 

public:
	// T Ŭ������ ��ü ���� ������
	static T * GetInstance()
	{
		if (!p)
			p = new T();
		return p;
	} 
	// T Ŭ������ ������� ��ü ���� �ʱ�ȭ
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
};

// p ���� �ʱ�ȭ (�̰� �ʼ���)
template <class T>
T * CSingleton<T>::p = nullptr;