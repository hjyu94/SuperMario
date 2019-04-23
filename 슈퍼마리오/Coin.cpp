#include "stdafx.h"
#include "Coin.h"


CCoin::CCoin()
	:m_bCreate_Action(true)
{
}


CCoin::~CCoin()
{
}

void CCoin::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 3.f;
	m_bIsGrounded = true;
	iNum = 1;
}

int CCoin::Update()
{
	if (m_bIsDead)
	{
		//사망시함수구현
		return OBJ_DEAD;
	}

	if (1 == iNum)
	{
		m_fCreate_Y = m_tInfo.fY;
		--iNum;
	}

	///생성 액션
	if (m_bCreate_Action && m_bIsGrounded)
	{
		m_tInfo.fY -= (m_fSpeed);
		if (m_tInfo.fY <= m_fCreate_Y - 80.f)
		{
			m_bCreate_Action = false;
		}
	}
	if (!m_bCreate_Action && m_bIsGrounded)
	{
		return OBJ_DEAD;
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
