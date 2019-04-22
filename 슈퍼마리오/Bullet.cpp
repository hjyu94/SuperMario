#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 10.f;
	//m_fAngle = 0;
}

int CBullet::Update()
{
	m_tInfo.fX += m_fSpeed * cosf(ToRadian(m_fAngle));
	m_tInfo.fY += m_fSpeed * sinf(ToRadian(m_fAngle));

	CObj::UpdateRect();
	return 0;
}

void CBullet::LateUpdate()
{
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
