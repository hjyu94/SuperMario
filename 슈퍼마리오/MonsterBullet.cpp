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
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
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
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonsterBullet::Release()
{
}
