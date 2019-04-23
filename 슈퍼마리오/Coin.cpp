#include "stdafx.h"
#include "Coin.h"


CCoin::CCoin()
{
}


CCoin::~CCoin()
{
}

void CCoin::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 11.f;

	m_tInfo.fX = 300.f;///일단 임의NUM ->블럭 위치
	m_tInfo.fY = 400.f;///일단 임의NUM ->블럭 위치

	m_fCreate_Y = m_tInfo.fY;

	m_bIsGrounded = false;
	m_bIsDead = false;
	m_bCreate_Action = true;
}

int CCoin::Update()
{
	if (m_bIsDead)
	{
		return OBJ_DEAD;
	}

	if (m_bCreate_Action)
	{
		m_tInfo.fY -= m_fSpeed;
		if ((m_fCreate_Y - 100.f) >= m_tInfo.fY)
		{
			m_bCreate_Action = false;
		}
	}
	if (!m_bCreate_Action)
	{
		m_tInfo.fY += m_fSpeed;
		if (m_fCreate_Y <= m_tInfo.fY)
		{
			return OBJ_DEAD;
		}
	}

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
