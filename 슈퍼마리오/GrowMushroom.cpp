#include "stdafx.h"
#include "GrowMushroom.h"


CGrowMushroom::CGrowMushroom()
	:m_bCreate_Action(true)
{
}


CGrowMushroom::~CGrowMushroom()
{
}

void CGrowMushroom::Initialize()
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 3.f;
	m_bIsGrounded = true;
	iNum = 1;
}

int CGrowMushroom::Update()
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

void CGrowMushroom::LateUpdate()
{
}

void CGrowMushroom::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(250, 100, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CGrowMushroom::Release()
{
}
