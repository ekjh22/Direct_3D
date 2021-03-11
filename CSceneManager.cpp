#include "DXUT.h"
#include "CSceneManager.h"


CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
	// ������ ������ �Ҵ�����
	for (auto iter : m_mapScene)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapScene.clear();
}

void CSceneManager::Update()
{
	// ���� ���� ���� ������ ��� ������Ʈ �Լ� ȣ��
	if (m_pCurScene)
		m_pCurScene->Update();

	// ���� ���� ���� ������ ���
	if (m_pNextScene)
	{
		// ������� �ʱ�ȭ����
		if (m_pCurScene)
			m_pCurScene->Release();
		OBJECT.ClearObjects(); // ���� ���� ������Ʈ�� �ʱ�ȭ
		m_pNextScene->Init();  // ���� ���� ��������
		m_pCurScene = m_pNextScene; // ���� ���� ���� �� ������ �Ҵ�����
		m_pNextScene = nullptr; // ���� �� �� �ʱ�ȭ
	}
}

void CSceneManager::Render()
{
	// ���� ���� ���� ������ ��� ���� �Լ� ȣ��
	if (m_pCurScene)
		m_pCurScene->Render();
}

void CSceneManager::AddScene(string _Key, CScene * _pScene)
{
	// �� ������ �� �߰� ~
	m_mapScene.insert(make_pair(_Key, _pScene));
}

void CSceneManager::ChangeScene(string _Key)
{
	// Ű ���� �´� �� �� ���� �� ���� �־���
	m_pNextScene = m_mapScene[_Key];
}
