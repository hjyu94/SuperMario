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
	m_tInfo.fCX = PLAYER_S_FCX;
	m_tInfo.fCY = PLAYER_S_FCY;
	m_tInfo.fX = -10;
	m_tInfo.fY = 540 - PLAYER_S_FCY / 2;

	m_fSpeed = 5.f;
	m_eCurState = PLAYER::PS_IDLE;
	m_ePrevState = PLAYER::PS_IDLE;
	m_fAngle = 0; // 처음 진행 방향: 오른쪽: 0도

	m_iLife = 3;
}

int CPlayer::Update()
{
	// 왼쪽에서 나오는 인트로
	if (!m_bInit)
	{
		m_tInfo.fX += m_fSpeed*0.5f;
		CObj::UpdateRect();

		if(m_tInfo.fX > 100)
			m_bInit = true;

		return 0;
	}

	// 자유낙하
	/*if (!m_bIsGrounded)
	{
		m_Vel_Y += 0.4f;
		m_tInfo.fY += m_Vel_Y;

		if (m_tInfo.fY > WINCY - 100 - m_tInfo.fCY / 2)
		{
			m_tInfo.fY = WINCY - 100 - m_tInfo.fCY / 2;
		}
	}
	else
	{
		m_Vel_Y = 0.f;
	}

	if (m_tInfo.fY >= WINCY - 100 - m_tInfo.fCY / 2)
	{
		m_bIsGrounded = true;
	}*/

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
			m_tInfo.fY = fy - PLAYER_S_FCY /2;
		}
	}
	else if (bIsColl)
		m_tInfo.fY = fy - PLAYER_S_FCY / 2;

	// 키 입력
	if (GetAsyncKeyState(VK_SPACE) && m_bIsGrounded)
	{
		m_Vel_Y = -12.f;
		m_bIsGrounded = false;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		// IDLE: 원래 스피드
		// 무적: 원래 스피드 * 1.2
		// 달리기: 원래 스피드 * 1.2
		// 무적일때 달리기: 원래 스피드 * 1.2 * 1.2
		// 적용 아직 제대로 안됨.

		m_fAngle = 180;

		float Speed = m_fSpeed;

		if (m_eCurState == PLAYER::PS_POWERFUL)
		{
			Speed *= 1.2f;
		}

		if (GetAsyncKeyState(VK_SHIFT))
		{
			m_tInfo.fX -= Speed * 1.2;
			m_ePrevState = m_eCurState;
			m_eCurState = PLAYER::PS_RUNNING;
		}
		else
		{
			m_tInfo.fX -= Speed;
			m_ePrevState = m_eCurState;
			//m_eCurState = PLAYER::PS_IDLE;
		}
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fAngle = 0;

		if (GetAsyncKeyState(VK_SHIFT))
		{
			m_tInfo.fX += m_fSpeed * 1.5;
			m_ePrevState = m_eCurState;
			m_eCurState = PLAYER::PS_RUNNING;
	
			if(m_tInfo.fX > 400)
				CObjMgr::Get_Instance()->ScrollToRight(m_fSpeed * 1.5);
		}
		else
		{
 			m_tInfo.fX += m_fSpeed;
			m_ePrevState = m_eCurState;
			//m_eCurState = PLAYER::PS_IDLE;
			if (m_tInfo.fX > 400)
			{
				CObjMgr::Get_Instance()->ScrollToRight(m_fSpeed);
				CLineMgr::Get_Instance()->ScrollToRight(m_fSpeed);
			}
		}
	}

	if ((GetAsyncKeyState('Z') & 0001) && m_eCurState == PLAYER::PS_ANGRY) // 총알 발사
	{
		CObjMgr::Get_Instance()->AddObject(OBJID::BULLET, Create_Bullet());
	}

	// 치트키, 상태에 따라서 플레이어 색 변함
	if (GetAsyncKeyState('A') & 0x0001)
	{
		m_eCurState = PLAYER::STATE(int(m_eCurState) + 1);
		if (m_eCurState > PLAYER::STATE::PS_END)
		{
			m_eCurState = PLAYER::STATE::PS_IDLE;
		}
	}

	if (m_eCurState != PLAYER::STATE::PS_RUNNING)
	{
		if (m_eCurState == PLAYER::STATE::PS_IDLE)
		{
			if (m_tInfo.fCX == PLAYER_S_FCX) // 예전 상태도 IDLE, 지금도 IDLE
			{

			}
			else // 예전 상태는 큰 상태였는데, 작은 상태로 업데이트 된 경우
			{
				m_tInfo.fCX = PLAYER_S_FCX;
				m_tInfo.fCY = PLAYER_S_FCY;
				m_tInfo.fY += (PLAYER_B_FCY - PLAYER_S_FCY) * 0.5f;
			}
		}
		
		else if (m_eCurState != PLAYER::STATE::PS_IDLE)// 큰 사이즈여야 하는 상태
		{
			if (m_tInfo.fCX == PLAYER_B_FCX) // 예전 상태도 큰 상태, 지금은 큰 상태
			{

			}
			else // 예전 상태는 작은 상태였는데, 큰 상태로 업데이트 된 경우
			{
				m_tInfo.fCX = PLAYER_B_FCX;
				m_tInfo.fCY = PLAYER_B_FCY;
				m_tInfo.fY -= (PLAYER_B_FCY - PLAYER_S_FCY)  * 0.5f;
			}
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

	switch (m_eCurState)
	{
	case PLAYER::PS_IDLE: // 흰색
		break;
	case PLAYER::PS_RUNNING: // 파랑색 212, 244, 250
		myBrush = (HBRUSH)CreateSolidBrush(RGB(212, 244, 250));
		break;
	case PLAYER::PS_BIG: // 노랑색 255,255,212
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 212));
		break;
	case PLAYER::PS_ANGRY: // 주황색 255, 204, 151
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 204, 151));
		break;
	case PLAYER::PS_POWERFUL: // 검정색 0, 0, 0
		myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		break;
	}
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
	

	// 상태값 표시
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

	// this(플레이어가)가 몬스터와 부딪히면
	if (nullptr != dynamic_cast<CMonster*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if (m_tInfo.fX < pCounterObj->Get_Info().fX) // 플레이어가 왼쪽에서 다가가면
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // 플레이어가 오른쪽에서 다가가면
				m_tInfo.fX += rc.right - rc.left;
			--m_iLife;
		}
	}

	// 플레이어가 몬스터 총알과 충돌할 경우
	if (nullptr != dynamic_cast<CMonsterBullet*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			--m_iLife;
		}
	}

	// 플레이어가 화분과 충돌할 경우
	if (nullptr != dynamic_cast<CBlock*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if (m_tInfo.fX < pCounterObj->Get_Info().fX) // 플레이어가 왼쪽에서 다가가면
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // 플레이어가 오른쪽에서 다가가면
				m_tInfo.fX += rc.right - rc.left;
		}
	}

	// 플레이어가 클때 부숴지는 블록에 충돌할 경우
	if (nullptr != dynamic_cast<CBreakBlock*>(pCounterObj))
	{
		if (IntersectRect(&rc, &m_tRect, &pCounterObj->Get_Rect()))
		{
			if (CObjMgr::Get_Instance()->Get_Player()->m_eCurState != PLAYER::PS_IDLE)
			{
				// 큰 상태
			}

			if (m_tInfo.fX < pCounterObj->Get_Info().fX) // 플레이어가 왼쪽에서 다가가면
				m_tInfo.fX -= rc.right - rc.left;
			if (m_tInfo.fX > pCounterObj->Get_Info().fX) // 플레이어가 오른쪽에서 다가가면
				m_tInfo.fX += rc.right - rc.left;


				/*CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CCoin>());*/
			/*	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CFireFlower>());*/
	     		//CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CGrowMushroom>());
				CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CLifeMushroom>());
				//CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, ((CBreakBlock*)pCounterObj)->CreateItem<CStar>());
			}
		}
	}
CObj * CPlayer::Create_Bullet()
{
	CBullet* pBullet = nullptr;

	if (m_fAngle == 0) // 오른쪽을 보고 있다면		{
		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tRect.top, 30);
	else if (m_fAngle == 180) // 왼쪽을 보고 있다면
		pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tRect.top, 150);

	// 플레이어가 작을 때, 클 때 총알 튀는 폭이 다른가..?

	return pBullet;
}

int CPlayer::Get_iLife()
{
	return m_iLife;
}
