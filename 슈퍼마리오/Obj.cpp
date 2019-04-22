#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	:m_bIsDead(false)
	, m_fAngle(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
}

void CObj::UpdateRect()
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (int(m_tInfo.fCY) >> 1));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (int(m_tInfo.fCY) >> 1));
}

void CObj::Set_Pos(float fx, float fy)
{
	m_tInfo.fX = fx;
	m_tInfo.fY = fy;
}

void CObj::Set_Angle(float _angle)
{
	m_fAngle = _angle;
}

void CObj::Set_Dead()
{
	m_bIsDead = true;
}
