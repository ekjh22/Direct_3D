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
	m_pRenderer = gc<CSpriteRenderer>(); // Animation ������Ʈ�� ����ϴ� ������Ʈ�� �ִ� ������� ������ ������Ʈ�� ������
}

void CAnimation::Update()
{
	// ������ ����Ŭ
	m_fTime += dt; // ���� �ð��� ��Ÿ Ÿ�� ���� �߰����� (�� ����� 1�ʰ� �������� m_fTime���� 1��)
	if (m_fTime > m_fDelay) // m_fTime ���� ���� �����̺��� Ŀ���� (�������� �ѱ� �ð��� ��)
	{
		m_fTime = 0.f; // ���� �ʱ�ȭ
		m_iCurFrame++; // ���� ������ �Ѱ���

		if (m_iCurFrame == m_iMaxFrame) // ���� �������� ���� �����ߴٸ�
		{
			if (m_bRepeat) // �ݺ��� ���
			{
				m_iCurFrame = 0; // �ٽ� �������� 0���� �ʱ�ȭ����
			}
			else // �ƴҰ��
			{
				m_iCurFrame--; // �������� �ϳ� ����
				m_bEnable = false; // �ش� ������Ʈ�� ���� ������
			}
		}
	}
	// ������ ����Ŭ

	// ���� �����ӿ� �°� �������� �ִ� ��������Ʈ�� ��ü����
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
	m_fDelay = _fDelay; // ������ ����
	m_bRepeat = _bRepeat; // �ݺ� ����
	int i = 1;
	while (1)
	{
		CSprite * pSprite = GRAPHICS.FindSprite(_Key + " (" + to_string(i) + ")"); // ��������Ʈ ã�� (ex : _Key ������ Test��� Test(0), Test(1) ... �̷������� �����̸� �������)
		if (pSprite == nullptr) // ��������Ʈ�� ������ break
			break;

		m_vecSprite.push_back(pSprite); // ��������Ʈ �߰�
		i++;;
	}
	m_iCurFrame = 0; // ������ �ʱ�ȭ
	m_iMaxFrame = m_vecSprite.size(); // ��������Ʈ�� ����� ���� ũ�⿡ �°� �ִ� ������ ����
}
