#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}

CLine::CLine(LINEINFO & rLineInfo)
	: m_tInfo(rLineInfo)
{
}


CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.tLeftPoint.fX, m_tInfo.tLeftPoint.fY, nullptr);
	LineTo(hDC, m_tInfo.tRightPoint.fX, m_tInfo.tRightPoint.fY);
}
