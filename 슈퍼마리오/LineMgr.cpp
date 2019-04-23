#include "stdafx.h"
#include "LineMgr.h"
#include "Line.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::ScrollToRight(float _fSpeed)
{
	for (auto& pLine : m_listLine)
	{
		pLine->Get_LineInfo().tLeftPoint.fX -= _fSpeed;
		pLine->Get_LineInfo().tRightPoint.fX -= _fSpeed;
	}
}

void CLineMgr::AddLine(float x1, float y1, float x2, float y2)
{
	LINEPOS tPoint1{ x1, y1 };
	LINEPOS tPoint2{ x2, y2 };
	m_listLine.emplace_back(new CLine(LINEINFO(tPoint1, tPoint2)));
}

void CLineMgr::Initialize()
{
	LINEPOS tPosArr[] = {
		{0, 540}, {2850,540} 
		, {2930, 540}, {3545,540}
		,{ 3670, 540 },{ 6310,540 }
		,{ 6400, 540 },{ 8750,540 }
	};

	
	
	m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[0], tPosArr[1])));
	m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[2], tPosArr[3])));
	m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[4], tPosArr[5])));
	m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[6], tPosArr[7])));
}

void CLineMgr::Render(HDC hDC)
{
	for (auto& pLine : m_listLine)
	{
		pLine->Render(hDC);
	}
}

void CLineMgr::Release()
{
	for (auto& pLine : m_listLine)
	{
		if (pLine)
		{
			delete pLine;
			pLine = nullptr;
		}
	}
	m_listLine.clear();
}

bool CLineMgr::LineCollision(float fInX, float * pOutY)
{
	if (m_listLine.empty())
		return false;

	CLine* pTarget = nullptr;

	for (auto& pLine : m_listLine)
	{
		if (fInX >= pLine->Get_LineInfo().tLeftPoint.fX
			&& fInX < pLine->Get_LineInfo().tRightPoint.fX)
		{
			pTarget = pLine;
		}
	}

	if (nullptr == pTarget)
		return false;

	float x1 = pTarget->Get_LineInfo().tLeftPoint.fX;
	float y1 = pTarget->Get_LineInfo().tLeftPoint.fY;
	float x2 = pTarget->Get_LineInfo().tRightPoint.fX;
	float y2 = pTarget->Get_LineInfo().tRightPoint.fY;

	*pOutY = ((y2 - y1) / (x2 - x1)) * (fInX - x1) + y1;
	return true;
}
