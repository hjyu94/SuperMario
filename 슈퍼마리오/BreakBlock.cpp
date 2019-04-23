#include "stdafx.h"
#include "BreakBlock.h"

#include "ObjMgr.h"
#include "AbstractFactory.h"

#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"

CBreakBlock::CBreakBlock()
{
}


CBreakBlock::~CBreakBlock()
{
}

void CBreakBlock::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	///임의 위치
	m_tInfo.fX = 500.f;
	m_tInfo.fY = 395.f;
}

int CBreakBlock::Update()
{
	CObj::UpdateRect();

	if (!m_bInit)
	{
		CLineMgr::Get_Instance()->AddLine(m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top);
		m_bInit = true;
	}

	if (m_bIsDead)
	{
		//죽었을때 
		return OBJ_DEAD;
	}

	return OBJ_ALIVE;
}

void CBreakBlock::LateUpdate()
{
	
}

void CBreakBlock::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(242, 203, 97));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CBreakBlock::Release()
{
}


