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
	m_fSpeed = 5.f;
	m_bIsJumping = true;
	m_tInfo.fX = 300.f;///일단 임의NUM ->블럭 위치
	m_tInfo.fY = 400.f;///일단 임의NUM ->블럭 위치

	m_fCreate_Y = m_tInfo.fY;
}

int CCoin::Update()
{
	if (m_bIsDead)
	{
		//죽었을때 
		m_Vel_Y = 0.f;
		return OBJ_DEAD;
	}

	///생성 액션
	if (m_bCreate_Action && m_bIsJumping)
	{
		m_tInfo.fY -= (m_fSpeed - 3.f);
		if (m_tInfo.fY <= m_fCreate_Y - ITEM_MOVE_SIZE)
		{
			m_bCreate_Action = false;
		}
	}
	if (!m_bCreate_Action && m_bIsJumping)
	{
		m_tInfo.fX += m_fSpeed;
	}

	//임시////////////////////////////////////
	//충돌체크
	if (m_tInfo.fX >= 425.f)
	{
		m_bIsJumping = false;
	}
	//자유낙하
	if (!m_bCreate_Action && !m_bIsJumping)
	{
		m_Vel_Y += 0.4f;
		m_tInfo.fY += m_Vel_Y;
	}
	if (m_tInfo.fY >= 100.f)
	{
		m_bIsJumping = true;
	}
	else
	{
		m_Vel_Y = 0.f;
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
