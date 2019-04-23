#include "stdafx.h"
#include "Player.h"

#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "LineMgr.h"

#include "Bullet.h"
#include "Monster.h"
#include "BreakBlock.h"
#include "MonsterBullet.h"
#include "Block.h"
#include "BreakBlock.h"
#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tInfo.fCX = PLAYER_FCX;
	m_tInfo.fCY = PLAYER_FCY;
	m_tInfo.fX = -10;
	m_tInfo.fY = 540 - PLAYER_FCY / 2;

	m_fSpeed = 5.f;
	m_eState = PLAYER::PS_IDLE;
	m_fAngle = 0; // ó�� ���� ����: ������: 0��

	m_iLife = 3;
}

int CPlayer::Update()
{
	// ���ʿ��� ������ ��Ʈ��
	if (!m_bInit)
	{
		m_tInfo.fX += m_fSpeed*0.5f;
		CObj::UpdateRect();

		if(m_tInfo.fX > 100)
			m_bInit = true;

		return 0;
	}

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
			m_tInfo.fY = fy - PLAYER_FCY /2;
		}
	}
	else if (bIsColl)
		m_tInfo.fY = fy - PLAYER_FCY / 2;


	// Ű �Է�
	if (GetAsyncKeyState(VK_SPACE) && m_bIsGrounded)
	{
		m_Vel_Y = -12.f;
		m_bIsGrounded = false;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		// IDLE: ���� ���ǵ�
		// ����: ���� ���ǵ� * 1.2
		// �޸���: ���� ���ǵ� * 1.2
		// �����϶� �޸���: ���� ���ǵ� * 1.2 * 1.2
		// ���� ���� ����� �ȵ�.

		m_fAngle = 180;

		float Speed = m_fSpeed;


		if (GetAsyncKeyState(VK_SHIFT))
		{
			m_tInfo.fX -= Speed * 1.2;
			m_eState = PLAYER::PS_RUNNING;
		}
		else
		{
			m_tInfo.fX -= Speed;
		}
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fAngle = 0;

		if (GetAsyncKeyState(VK_SHIFT))
		{
			m_tInfo.fX += m_fSpeed * 1.5;
			m_eState = PLAYER::PS_RUNNING;
	
			if(m_tInfo.fX > 400)
				CObjMgr::Get_Instance()->ScrollToRight(m_fSpeed * 1.5);
		}
		else
		{
 			m_tInfo.fX += m_fSpeed;
			//m_eCurState = PLAYER::PS_IDLE;
			if (m_tInfo.fX > 400)
			{
				CObjMgr::Get_Instance()->ScrollToRight(m_fSpeed);
				CLineMgr::Get_Instance()->ScrollToRight(m_fSpeed);
			}
		}
	}

	if ((GetAsyncKeyState('Z') & 0001) && m_eState == PLAYER::PS_ANGRY) // �Ѿ� �߻�
	{
		CObjMgr::Get_Instance()->AddObject(OBJID::BULLET, Create_Bullet());
	}

	// ġƮŰ, ���¿� ���� �÷��̾� �� ����
	if (GetAsyncKeyState('A') & 0x0001)
	{
		m_eState = PLAYER::STATE(int(m_eState) + 1);
		if (m_eState > PLAYER::STATE::PS_END)
		{
			m_eState = PLAYER::STATE::PS_IDLE;
		}
	}


	CObj::UpdateRect();
	return 0;
}

void CPlayer::LateUpdate()
{

}

void CPlayer::Render(HDC hDC)
{
	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;

	switch (m_eState)
	{
	case PLAYER::PS_IDLE: // ���
		break;
	case PLAYER::PS_RUNNING: // �Ķ��� 212, 244, 250
		myBrush = (HBRUSH)CreateSolidBrush(RGB(212, 244, 250));
		break;
	case PLAYER::PS_ANGRY: // ��Ȳ�� 255, 204, 151
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 204, 151));
		break;
	case PLAYER::PS_POWERFUL: // ������ 0, 0, 0
		myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		break;
	}
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
	

	// ���°� ǥ��
	WCHAR lpOut[1024] = L"";
	wsprintf(lpOut, L"Life: %d", m_iLife);
	TextOut(hDC, 100, 100, lpOut, lstrlen(lpOut));
}

void CPlayer::Release()
{
	
}

void CPlayer::Collision_Proc(CObj * pCounterObj)
{
	RECT rc = {};
	
	if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
	{
		float fX = m_tInfo.fX;
		float fY = m_tInfo.fY;

		float fIntersectedX = rc.right - rc.left;
		float fIntersectedY = rc.bottom - rc.top;

		if (fIntersectedX > fIntersectedY)
		{
			if (fY < pCounterObj->Get_Info().fY)
				fIntersectedY *= -1.f;

			this->Set_Pos(fX, fY + fIntersectedY);
		}
		else
		{
			if (fX < pCounterObj->Get_Info().fX)
				fIntersectedX *= -1.f;

			this->Set_Pos(fX + fIntersectedX, fY);
			//if (m_tInfo.fX < pCounterObj->Get_Info().fX) // �÷��̾ ���ʿ��� �ٰ�����
			//	m_tInfo.fX -= rc.right - rc.left;
			//if (m_tInfo.fX > pCounterObj->Get_Info().fX) // �÷��̾ �����ʿ��� �ٰ�����
			//	m_tInfo.fX += rc.right - rc.left;
		}
	}

	// this(�÷��̾)�� ���Ϳ� �ε�����
	if (nullptr != dynamic_cast<CMonster*>(pCounterObj))
	{
		if(IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if(m_tInfo.fX < pCounterObj->Get_Info().fX) // �÷��̾ ���ʿ��� �ٰ�����
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // �÷��̾ �����ʿ��� �ٰ�����
				m_tInfo.fX += rc.right - rc.left;
			--m_iLife;
		}
	}

	// �÷��̾ ���� �Ѿ˰� �浹�� ���
	if (nullptr != dynamic_cast<CMonsterBullet*>(pCounterObj))
	{
		--m_iLife;
	}

	if (nullptr != dynamic_cast<CFireFlower*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if (m_tInfo.fX < pCounterObj->Get_Info().fX) // �÷��̾ ���ʿ��� �ٰ�����
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // �÷��̾ �����ʿ��� �ٰ�����
				m_tInfo.fX += rc.right - rc.left;
		}
	}
 
	// �÷��̾ Ŭ�� �ν����� ��Ͽ� �浹�� ���
	if (nullptr != dynamic_cast<CBreakBlock*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if (CObjMgr::Get_Instance()->Get_Player()->m_eCurState != PLAYER::PS_IDLE)
			{
				// ū ����
			}
			
			CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CStar>());
			
			if (m_tInfo.fX < pCounterObj->Get_Info().fX) // �÷��̾ ���ʿ��� �ٰ�����
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // �÷��̾ �����ʿ��� �ٰ�����
				m_tInfo.fX += rc.right - rc.left;
		}
	}
}

CObj * CPlayer::Create_Bullet()
{
	CBullet* pBullet = nullptr;

	if (m_fAngle == 0) // �������� ���� �ִٸ�		{
		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tRect.top, 30);
	else if (m_fAngle == 180) // ������ ���� �ִٸ�
		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tRect.top, 150);

	// �÷��̾ ���� ��, Ŭ �� �Ѿ� Ƣ�� ���� �ٸ���..?

	return pBullet;
}

int CPlayer::Get_iLife()
{
	return m_iLife;
}
