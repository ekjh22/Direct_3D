#include "DXUT.h"
#include "CRenderer2D.h"


CRenderer2D::CRenderer2D()
{
	// ������Ʈ �Ŵ������� ������ ���ִ� �κ��� ����� ���ֵ��� ������
	OBJECT.RegisterRenderer2D(this);
}


CRenderer2D::~CRenderer2D()
{
	// ������Ʈ �Ŵ������� ������ ���ִ� �κ��� ����� ���ֵ��� ����������
	OBJECT.UnRegisterRenderer2D(this);
}
