#include "stdafx.h"
#include "PlantBlock.h"


CPlantBlock::CPlantBlock()
{
}


CPlantBlock::~CPlantBlock()
{
}

void CPlantBlock::Initialize()
{
	m_tInfo.fCX = PLANT_BLOCK_FCX;
	m_tInfo.fCY = PLANT_BLOCK_FCY;
}

int CPlantBlock::Update()
{
	CObj::UpdateRect();
	if (!m_bInit)
	{
		CLineMgr::Get_Instance()->AddLine(m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top);
		m_bInit = true;
	}
	return 0;
}

void CPlantBlock::LateUpdate()
{
}

void CPlantBlock::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top + 40);
	Rectangle(hDC, m_tRect.left + 10, m_tRect.top + 40, m_tRect.right - 10, m_tRect.bottom);
}

void CPlantBlock::Release()
{
}
