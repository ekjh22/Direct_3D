#include "DXUT.h"
#include "CRenderer2D.h"


CRenderer2D::CRenderer2D()
{
	// 오브젝트 매니저에서 렌더러 해주는 부분의 기능을 해주도록 가입함
	OBJECT.RegisterRenderer2D(this);
}


CRenderer2D::~CRenderer2D()
{
	// 오브젝트 매니저에서 렌더러 해주는 부분의 기능을 해주도록 가입해제함
	OBJECT.UnRegisterRenderer2D(this);
}
