#include "stdafx.h"
#include "FireFlower.h"


CFireFlower::CFireFlower()
	:m_bCreate_Action(true), m_fCreate_Y(0.f)
{
}


CFireFlower::~CFireFlower()
{
}

void CFireFlower::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 5.f;
	m_bIsGrounded = true;
	m_tInfo.fX = 400.f;///일단 임의NUM ->블럭 위치
	m_tInfo.fY = 400.f;///일단 임의NUM ->블럭 위치

	m_fCreate_Y = m_tInfo.fY;
}

int CFireFlower::Update()
{
	if (m_bIsDead)
	{
		//죽었을때 
		m_Vel_Y = 0.f;
		return OBJ_DEAD;
	}

	///생성 액션
	if (m_bCreate_Action && m_bIsGrounded)
	{
		m_tInfo.fY -= (m_fSpeed - 3.f);
		if (m_tInfo.fY <= m_fCreate_Y - ITEM_MOVE_SIZE)
		{
			m_bCreate_Action = false;
		}
	}
	if (!m_bCreate_Action && m_bIsGrounded)
	{
	}

	return OBJ_ALIVE;
}

void CFireFlower::LateUpdate()
{
}

void CFireFlower::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CFireFlower::Release()
{
}
