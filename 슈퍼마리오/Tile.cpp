#include "stdafx.h"
#include "Tile.h"


CTile::CTile()
{
}


CTile::~CTile()
{
}

void CTile::Initialize()
{
	m_tInfo.fCX = TILE_FCX;
	m_tInfo.fCY = TILE_FCY;
}

int CTile::Update()
{
	CObj::UpdateRect();
	return 0;
}

void CTile::LateUpdate()
{
}

void CTile::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CTile::Release()
{
}
