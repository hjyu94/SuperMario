#include "stdafx.h"
#include "Coin.h"


CCoin::CCoin()
	:m_bCreate_Action(true), m_fCreate_Y(0.f)
{
}


CCoin::~CCoin()
{
}

void CCoin::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 15.f;

	m_tInfo.fX = 300.f;///�ϴ� ����NUM ->�� ��ġ
	m_tInfo.fY = 400.f;///�ϴ� ����NUM ->�� ��ġ

	m_bIsGrounded = true;

	m_fCreate_Y = m_tInfo.fY;
	m_bIsDead = false;
}

int CCoin::Update()
{
	if (m_bIsDead)
	{
		return OBJ_DEAD;
	}

	///���� �׼�
	if (m_bCreate_Action && m_bIsGrounded)
	{
		m_tInfo.fY -= m_fSpeed;

		if (m_tInfo.fY <= m_fCreate_Y - (ITEM_MOVE_SIZE+50))
		{
			m_tInfo.fY += m_fSpeed;
		}
	}


	////////////////////////////////////////

	return OBJ_ALIVE;
}

void CCoin::LateUpdate()
{
}

void CCoin::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CCoin::Release()
{
}
