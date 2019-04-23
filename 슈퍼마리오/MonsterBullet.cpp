#include "stdafx.h"
#include "MonsterBullet.h"


CMonsterBullet::CMonsterBullet()
{
}


CMonsterBullet::~CMonsterBullet()
{
}

void CMonsterBullet::Initialize()
{
	m_tInfo.fCX = BULLET_FCX;
	m_tInfo.fCY = BULLET_FCY;
	m_fSpeed = 10.f;
}

int CMonsterBullet::Update()
{
	m_tInfo.fX += m_fSpeed*cosf(ToRadian(m_fAngle));
	m_tInfo.fY += m_fSpeed*sinf(ToRadian(m_fAngle));

	CObj::UpdateRect();
	return 0;
}

void CMonsterBullet::LateUpdate()
{
}

void CMonsterBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonsterBullet::Release()
{
}
