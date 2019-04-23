#include "stdafx.h"
#include "Star.h"


CStar::CStar()
	:m_bCreate_Action(true)
{
}


CStar::~CStar()
{
}

void CStar::Initialize()
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 2.f;
	m_bIsGrounded = true;
	iNum = 1;
}

int CStar::Update()
{
	if (m_bIsDead)
	{
		//죽었을때 
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

void CStar::LateUpdate()
{
}

void CStar::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CStar::Release()
{
}
