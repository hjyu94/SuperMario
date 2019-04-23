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
		//Á×¾úÀ»¶§ 
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

		int Num = (rand() % 15) + 5;
		{
			if (7 == Num)
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CCoin>::Create(m_tInfo.fX, m_tInfo.fY));
			else if (8 == Num)
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CFireFlower>::Create(m_tInfo.fX, m_tInfo.fY));
			else if (9 == Num)
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CGrowMushroom>::Create(m_tInfo.fX, m_tInfo.fY));
			else if (10 == Num)
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CLifeMushroom>::Create(m_tInfo.fX, m_tInfo.fY));
			else if (11 == Num)
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CStar>::Create(m_tInfo.fX, m_tInfo.fY));
			else
			{
				return;
			}
		}
}

