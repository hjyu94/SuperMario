#include "stdafx.h"
#include "FlowerMon.h"


CFlowerMon::CFlowerMon()
{
}


CFlowerMon::~CFlowerMon()
{
}

void CFlowerMon::Initialize()
{
	m_tInfo.fCX = FLOWER_MON_FCX;
	m_tInfo.fCY = FLOWER_MON_FCY;
}

int CFlowerMon::Update()
{
	CObj::UpdateRect();
	return 0;
}

void CFlowerMon::LateUpdate()
{
}

void CFlowerMon::Render(HDC hDC)
{
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect)
}

void CFlowerMon::Release()
{
}
