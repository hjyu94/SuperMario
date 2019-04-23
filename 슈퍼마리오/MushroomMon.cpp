#include "stdafx.h"
#include "MushroomMon.h"
#include "Player.h"

CMushroomMon::CMushroomMon()
{
}


CMushroomMon::~CMushroomMon()
{
}

void CMushroomMon::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fSpeed = 3.f;
}

int CMushroomMon::Update()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	float fy = 0.f;
	bool bIsColl = CLineMgr::Get_Instance()->LineCollision(m_tInfo.fX, m_tInfo.fY, &fy);
	
	if (!m_bIsGrounded)
	{
		m_Vel_Y += 0.4f;
		m_tInfo.fY += m_Vel_Y;

		if (bIsColl && m_tInfo.fY > fy)
		{
			m_bIsGrounded = true;
			m_Vel_Y = 0.f;
			m_tInfo.fY = fy - m_tInfo.fCY / 2;
		}
	}
	else if (bIsColl)
		m_tInfo.fY = fy - m_tInfo.fCY / 2;
		
	m_tInfo.fX += m_fSpeed;

	CObj::UpdateRect();
	return 0;
}

void CMushroomMon::LateUpdate()
{
}

void CMushroomMon::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left+10, m_tRect.top+8, m_tRect.right-10, m_tRect.bottom);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.top + 20);
}

void CMushroomMon::Release()
{
}

void CMushroomMon::Collision_Proc(CObj * pCounterObj)
{
	RECT rc = {};
	if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
	{
		float fIntersectedX = rc.right - rc.left;
		float fIntersectedY = rc.bottom - rc.top;

		if (fIntersectedX < fIntersectedY)
		{
			m_fSpeed *= -1;
		}

		if (dynamic_cast<CPlayer*>(pCounterObj) != nullptr)
		{
			if (fIntersectedX > fIntersectedY)
			{
				m_bIsDead = true;
			}
		}
	}
}
