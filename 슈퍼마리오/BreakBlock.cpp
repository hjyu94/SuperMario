#include "stdafx.h"
#include "BreakBlock.h"

#include "ObjMgr.h"
#include "AbstractFactory.h"

#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"
#include "Player.h"

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
	if (!m_bInit)
	{
		CObj::UpdateRect();
		CLineMgr::Get_Instance()->AddLine(m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top);
		m_bInit = true;
	}
	CObj::UpdateRect();


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
	
	MoveToEx(hDC, m_tRect.left+12, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.left+12, m_tRect.bottom);

	MoveToEx(hDC, m_tRect.right - 12, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right - 12, m_tRect.bottom);

	Rectangle(hDC, m_tRect.left, m_tRect.top+10, m_tInfo.fX, m_tRect.top+20);
	Rectangle(hDC, m_tInfo.fX, m_tRect.top+10, m_tRect.right, m_tRect.top+20);
	
	Rectangle(hDC, m_tRect.left, m_tRect.top + 30, m_tInfo.fX, m_tRect.top + 40);
	Rectangle(hDC, m_tInfo.fX, m_tRect.top + 30, m_tRect.right, m_tRect.top + 40);


	//MoveToEx(hDC, m_tRect.left, m_tRect.top + 20, nullptr);
	//LineTo(hDC, m_tRect.right, m_tRect.top + 20);
	//MoveToEx(hDC, m_tRect.left, m_tRect.top + 30, nullptr);
	//LineTo(hDC, m_tRect.right, m_tRect.top + 30); 
	//MoveToEx(hDC, m_tRect.left, m_tRect.top + 40, nullptr);
	//LineTo(hDC, m_tRect.right, m_tRect.top + 40);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CBreakBlock::Release()
{
}

void CBreakBlock::Collision_Proc(CObj * pCounterObj)
{
}

void CBreakBlock::CreateCoin()
{
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CreateItem<CCoin>());
}

void CBreakBlock::CreateFireFlower()
{
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CreateItem<CFireFlower>());
}

void CBreakBlock::CreateGrowMush()
{
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CreateItem<CGrowMushroom>());
}


