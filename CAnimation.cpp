#include "DXUT.h"
#include "CAnimation.h"


CAnimation::CAnimation()
{
}


CAnimation::~CAnimation()
{
}

void CAnimation::Awake()
{
}

void CAnimation::Start()
{
	m_pRenderer = gc<CSpriteRenderer>(); // Animation 컴포넌트를 사용하는 오브젝트에 있는 스프라잍 렌더러 컴포넌트를 가져옴
}

void CAnimation::Update()
{
	// 프레임 사이클
	m_fTime += dt; // 현재 시간에 델타 타임 값을 추가해줌 (한 마디로 1초가 지나가면 m_fTime값은 1임)
	if (m_fTime > m_fDelay) // m_fTime 값이 아직 딜레이보다 커지면 (프레임을 넘길 시간이 됨)
	{
		m_fTime = 0.f; // 변수 초기화
		m_iCurFrame++; // 현재 프레임 넘겨줌

		if (m_iCurFrame == m_iMaxFrame) // 현재 프레임이 끝에 도달했다면
		{
			if (m_bRepeat) // 반복일 경우
			{
				m_iCurFrame = 0; // 다시 프레임을 0으로 초기화해줌
			}
			else // 아닐경우
			{
				m_iCurFrame--; // 프레임을 하나 뺴줌
				m_bEnable = false; // 해당 컴포넌트를 종료 시켜줌
			}
		}
	}
	// 프레임 사이클

	// 현재 프레임에 맞게 렌더러에 있는 스프라이트를 교체해줌
	m_pRenderer->m_pSprite = m_vecSprite[m_iCurFrame];
}

void CAnimation::LateUpdate()
{
}

void CAnimation::OnRender()
{
}

void CAnimation::OnDestroy()
{
}

void CAnimation::OnCollisionEnter(CObject * _pObj)
{
}


void CAnimation::OnCollisionStay(CObject * _pObj)
{
}

void CAnimation::OnCollisionExit(CObject * _pObj)
{
}

void CAnimation::Init(string _Key, float _fDelay, bool _bRepeat)
{
	m_fDelay = _fDelay; // 딜레이 셋팅
	m_bRepeat = _bRepeat; // 반복 셋팅
	int i = 1;
	while (1)
	{
		CSprite * pSprite = GRAPHICS.FindSprite(_Key + " (" + to_string(i) + ")"); // 스프라이트 찾기 (ex : _Key 네임이 Test라면 Test(0), Test(1) ... 이런식으로 파일이름 해줘야함)
		if (pSprite == nullptr) // 스프라이트가 없으면 break
			break;

		m_vecSprite.push_back(pSprite); // 스프라이트 추가
		i++;;
	}
	m_iCurFrame = 0; // 프레임 초기화
	m_iMaxFrame = m_vecSprite.size(); // 스프라이트를 담아준 벡터 크기에 맞게 최대 프레임 셋팅
}
