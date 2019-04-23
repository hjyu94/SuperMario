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
	m_tInfo.fCX = BULLET_FCX;
	m_tInfo.fCY = BULLET_FCY;
	m_fSpeed = 10.f;
	//m_fAngle = 0; // 플레이어가 총알 만들 때 값 넣어준다.
	m_fBoundary = 30.f;
}

int CBullet::Update()
{
	if (m_bIsGrounded)
	{
		if (m_fAngle == 30) m_fAngle = -30;
		else if (m_fAngle == -30) m_fAngle = 30;
		else if (m_fAngle == 150) m_fAngle = 210;
		else if (m_fAngle == 210) m_fAngle = 150;
		m_bIsGrounded = false;
	}

	m_tInfo.fX += m_fSpeed * cosf(ToRadian(m_fAngle));
	m_tInfo.fY += m_fSpeed * sinf(ToRadian(m_fAngle));
	
	if (m_tInfo.fY >= 500)
	{
		m_bIsGrounded = true;
	}
	if (m_tInfo.fY <= 500 - m_fBoundary)
	{
		m_bIsGrounded = true;
	}

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

//void CBullet::Set_Boundary(float _boundary)
//{
//	m_fBoundary = _boundary;
//}
