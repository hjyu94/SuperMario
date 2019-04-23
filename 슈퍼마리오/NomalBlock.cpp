#include "stdafx.h"
#include "NomalBlock.h"


CNomalBlock::CNomalBlock()
{
}


CNomalBlock::~CNomalBlock()
{
}

void CNomalBlock::Initialize()
{
	m_tInfo.fCX = BLOCK_SIZE;
	m_tInfo.fCY = BLOCK_SIZE;
	///임의 위치
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 395.f;
}

int CNomalBlock::Update()
{
	if (m_bIsDead)
	{
		//죽었을때 
		return OBJ_DEAD;
	}
	return OBJ_ALIVE;
}

void CNomalBlock::LateUpdate()
{
}

void CNomalBlock::Render(HDC hDC)
{
	CObj::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CNomalBlock::Release()
{
}
