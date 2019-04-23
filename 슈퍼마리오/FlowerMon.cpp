#include "stdafx.h"
#include "FlowerMon.h"
#include "PlantBlock.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Bullet.h"
#include "MonsterBullet.h"
#include "Player.h"
CFlowerMon::CFlowerMon()
{
}


CFlowerMon::~CFlowerMon()
{
}

void CFlowerMon::Initialize()
{
	m_tInfo.fCX = FLOWER_MON_FCX;
	m_tInfo.fCY = FLOWER_MON_FCY;
	m_fSpeed = 3.f;
	m_Time = GetTickCount();
	BulletCoolTime = GetTickCount();
	m_isStop = true;
	m_pTarget = CObjMgr::Get_Instance()->Get_Player();
}

int CFlowerMon::Update()
{
	int i = 0;
	if (!m_bInit)
	{
		m_tInfo.fY = m_tInfo.fY - PLANT_BLOCK_FCY / 2 + FLOWER_MON_FCY / 2;
		m_fCenter_x = m_tInfo.fX;
		m_fCenter_y = m_tInfo.fY;
		m_bInit = true;
	}

	if ((m_Time + 4000 < GetTickCount()) && m_isStop)
	{
		m_isStop = false;
	}

	if (!m_isStop)
		m_tInfo.fY += m_fSpeed;

	if ((m_tInfo.fY < m_fCenter_y - 70 || m_tInfo.fY > m_fCenter_y + 70 )&& !m_isStop)
	{
		m_fSpeed *= -1;
		m_isStop = true;
		m_Time = GetTickCount();
		BulletCoolTime = GetTickCount();
	}

	// ¸ØÃç ÀÖ´Âµ¥, À§ÂÊ¿¡¼­ ¸ØÃá °æ¿ì
	if (m_isStop && m_tInfo.fY < m_fCenter_y)
	{
		if (BulletCoolTime + 500 < GetTickCount())
		{
			// ÃÑ¾Ë ½î±â
			float fDeltaX = m_pTarget->Get_Info().fX - m_tInfo.fX;
			float fDeltaY = m_pTarget->Get_Info().fY - m_tInfo.fY;
			float fTheta = ToDegree(atan2(fDeltaY, fDeltaX)); // ¶óµð¾È
			CMonsterBullet* pBullet = CAbstractFactory<CMonsterBullet>::Create(m_tInfo.fX, m_tInfo.fY, fTheta);
			CObjMgr::Get_Instance()->AddObject(OBJID::MONSTER_BULLET, pBullet);
			
			BulletCoolTime = GetTickCount();
		}
	}
	CObj::UpdateRect();
	return 0;
}

void CFlowerMon::LateUpdate()
{
}

void CFlowerMon::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY + 70);
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Ellipse(hDC, m_tRect.left+3, m_tRect.top+3, m_tRect.right-3, m_tRect.bottom-3);
}

void CFlowerMon::Release()
{
}

