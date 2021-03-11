#include "DXUT.h"
#include "CObject.h"
#include "CComponent.h"

CObject::CObject()
{
	sa = new CScheduleAdmin();
}


CObject::~CObject()
{
	SAFE_DELETE(sa);
	for (auto iter : m_listComponent)
	{
		iter->OnDestroy();
	}
	for (auto iter : m_listComponent)
	{
		SAFE_DELETE(iter);
	}
}
