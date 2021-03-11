#pragma once
#include "CSingleton.h"

// Unity�� SceneManagement�� �����
// ���� ������ ������ �� �� �� �Žñ� ���� ���� ( ex : Title, Loading, InGame, Ending ) �̷������� ������ �ܰ踦 �����ֵ��� �����ִ� �Ŵ���
class CSceneManager :
	public CSingleton< CSceneManager>
{
public:
	CSceneManager();
	~CSceneManager();

private:
	map<string, CScene *> m_mapScene; // �� ���� Ű ���� �Բ� ��Ƶδ� �� ����

	CScene * m_pCurScene = nullptr; // ���� ��
	CScene * m_pNextScene = nullptr; // ���� ��
public:
	// �� �����Ӹ��� ����Ǵ� �Լ�
	void Update();

	// �� �����Ӹ��� ����Ǵ� �Լ�
	void Render();

	/// <summary>
	/// �� ������ ���� �߰����ִ� �Լ�
	/// </summary>
	/// <param name="_Key">Ű �� (ex : Title, Loading)</param>
	/// <param name="_pScene">�� �� (ex : new CLoadScene())</param>
	void AddScene(string _Key, CScene * _pScene);

	/// <summary>
	/// Ű ���� �°� ���� ��ü���ִ� �Լ�
	/// </summary>
	/// <param name="_Key">Ű �� (ex : Title, Loading)</param>
	void ChangeScene(string _Key);
};

#define SCENE (*CSceneManager::GetInstance())