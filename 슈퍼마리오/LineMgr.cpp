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

void CLineMgr::Initialize()
{
	LINEPOS tPosArr[2] = {
		{0, WINCY-100}, {1000, WINCY-100}
	};

	for (int i = 0; i < 2 - 1; ++i)
	{
		m_listLine.emplace_back(new CLine(LINEINFO(tPosArr[i], tPosArr[i+1])));
	}
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
