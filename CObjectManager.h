#pragma once
#include "CSingleton.h"

// �߻� Ŭ����
class CRenderer2D;
class CRenderer3D;
class CCollider;
// �߻� Ŭ����

// ���� ���α׷��� �ִ� ������Ʈ���� ���� �� �浹ó���� ���ִ� �Ŵ���
class CObjectManager :
	public CSingleton< CObjectManager>
{
public:
	CObjectManager();
	~CObjectManager();

public:

	// list�� �ϴ� ���� ObjectPool ������ ������� �ʾƼ� ������ �ϴµ� ���� ����� �Һ��ϱ� ������
	// ���� STL���� ������ ���� list�� ����ؼ� ���� ����� ���̴� ��
	// list�� ������ ���� ������ �߰� ������ ����
	list<CObject *> m_listObject; // ��� ������Ʈ��
	list<CRenderer2D *> m_listRenderer2D; // ������ ���ִ� ������Ʈ��
	list<CCollider *> m_listCollider; // �浹ó�� ���ִ� ������Ʈ��

public:
	// �ش� ������Ʈ�� ������ �ִ� ������Ʈ�� ������Ʈ �Ŵ������� ������ ���� �� �ֵ��� ������
	void RegisterRenderer2D(CRenderer2D * _pRenderer) { m_listRenderer2D.push_back(_pRenderer); }

	// �ش� ������Ʈ�� ������ �ִ� ������Ʈ�� ������Ʈ �Ŵ������� ������ ���� �� ������ ����������
	void UnRegisterRenderer2D(CRenderer2D * _pRenderer) { m_listRenderer2D.remove(_pRenderer); }

	// �ش� ������Ʈ�� ������ �ִ� ������Ʈ�� ������Ʈ �Ŵ������� �浹ó�� ���� �� �ֵ��� ������
	void RegisterCollider(CCollider * _pCollider);

	// �ش� ������Ʈ�� ������ �ִ� ������Ʈ�� ������Ʈ �Ŵ������� �浹ó�� ���� �� ������ ����������
	void UnRegisterCollider(CCollider * _pCollider);

	// ���� _pPrev�� _pNext�� �浹�ߴ°� ? �� �Ǵ��ϴ� �Լ�
	bool IsCollision(CCollider * _pPrev, CCollider * _pNext);

public:
	// �±׿� �´� ������Ʈ�� �߰���
	CObject * AddObject(Tag _Tag = Tag::Untagged);
	
	// �±׿� �´� ������Ʈ�� ã��
	CObject * Find(Tag _Tag);

	// �±׿� �´� ������Ʈ���� ã��
	list<CObject *> Finds(Tag _Tag);

public:
	// �� �����Ӹ��� �����Ű�� �Լ�
	void Update();

	// �� �����Ӹ��� �����Ű�� �Լ�
	void Render();

	// ������Ʈ �ʱ�ȭ
	void ClearObjects();
};
#define OBJECT (*CObjectManager::GetInstance())

