#pragma once

// CSceneManager�� �����ϴ� ���� ����� ���ؼ� ������� �θ� Ŭ����
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	// �⺻������ ó���� ����Ǵ� �Լ�
	virtual void Init() PURE;
	
	// �� �����Ӹ��� ����Ǵ� �Լ�
	virtual void Update() PURE;

	// �� �����Ӹ��� ����Ǵ� �Լ�
	virtual void Render() PURE;

	// �ı��� �� ����Ǵ� �Լ�
	virtual void Release() PURE;
};

