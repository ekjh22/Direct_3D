#pragma once
#include "CScene.h"

// ȿ�������� �����͵��� �ε��ϱ� ���ؼ� ���� ��
struct LoadData
{
public:
	string m_Key;		// �������� Ű ��
	string m_Path;		// �������� �ּ� ��
	int m_Type;			// �������� Ÿ��
};

class CLoadScene :
	public CScene
{
public:
	CLoadScene();
	~CLoadScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	list<LoadData> m_listLoadData; // �ε��� �����͵�

private:
	/// <summary>
	/// ��������Ʈ �ε����ִ� �Լ�
	/// </summary>
	/// <param name="_Key">Ű ��</param>
	/// <param name="_Path">�ּ� �� (ex : Player)</param>
	/// <param name="_iCount">���� (�ִϸ��̼� �ϰ�� ���� �߰�)</param>
	void LoadSprite(string _Key, string _Path, int _iCount = 0);
};

