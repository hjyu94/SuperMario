#include "stdafx.h"
#include "ItemBlock.h"


CItemBlock::CItemBlock()
{
}


CItemBlock::~CItemBlock()
{
}

void CItemBlock::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
}

int CItemBlock::Update()
{
	if (!m_bInit)
	{
		CObj::UpdateRect();
		CLineMgr::Get_Instance()->AddLine(m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top);
		m_bInit = true;
	}
	CObj::UpdateRect();


	return 0;
}

void CItemBlock::LateUpdate()
{
}

void CItemBlock::Render(HDC hDC)
{

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;

	myBrush = (HBRUSH)CreateSolidBrush(RGB(153, 56, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CItemBlock::Release()
{
}
