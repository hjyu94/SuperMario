#include "stdafx.h"
#include "BreakBlock.h"


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
	///���� ��ġ
	m_tInfo.fX = 500.f;
	m_tInfo.fY = 395.f;
}

int CBreakBlock::Update()
{
	if (m_bIsDead)
	{
		//�׾����� 
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
