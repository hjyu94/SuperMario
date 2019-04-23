#include "stdafx.h"
#include "TileBlock.h"


CTileBlock::CTileBlock()
{
}


CTileBlock::~CTileBlock()
{
}

void CTileBlock::Initialize()
{
	m_tInfo.fCX = TILE_BLOCK_FCX;
	m_tInfo.fCY = TILE_BLOCK_FCY;

}

int CTileBlock::Update()
{
	CObj::UpdateRect();
	return 0;
}

void CTileBlock::LateUpdate()
{
}

void CTileBlock::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Rectangle(hDC, m_tRect.left+3, m_tRect.top + 3, m_tRect.right - 3, m_tRect.bottom - 3);
}

void CTileBlock::Release()
{
}
