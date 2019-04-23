#include "stdafx.h"
#include "Player.h"

#include "ObjMgr.h"
#include "AbstractFactory.h"

#include "Bullet.h"

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
	m_tInfo.fX = 100.f;
	m_tInfo.fY = 100.f;

	m_fSpeed = 5.f;
	m_eCurState = PLAYER::PS_IDLE;
	m_ePrevState = PLAYER::PS_IDLE;
	m_fAngle = 0; // 처음 진행 방향: 오른쪽: 0도
}

int CPlayer::Update()
{
	// 자유낙하
	if (!m_bIsGrounded)
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
	}

	// 키 입력
	if (GetAsyncKeyState(VK_SPACE) && m_bIsGrounded)
	{
		m_Vel_Y = -12.f;
		m_bIsGrounded = false;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_fAngle = 180;

		if (GetAsyncKeyState(VK_SHIFT))
		{
			m_tInfo.fX -= m_fSpeed * 1.2;
			m_ePrevState = m_eCurState;
			m_eCurState = PLAYER::PS_RUNNING;
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
			m_ePrevState = m_eCurState;
			m_eCurState = PLAYER::PS_IDLE;
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
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
			m_ePrevState = m_eCurState;
			m_eCurState = PLAYER::PS_IDLE;
		}
	}

	if (GetAsyncKeyState('Z')) // 총알 발사
	{
		//CBullet* pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, m_fAngle+45);
		//CObjMgr::Get_Instance()->AddObject(OBJID::BULLET, );
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
	
	// 맵
	MoveToEx(hDC, 0, WINCY - 100, NULL);
	LineTo(hDC, WINCX, WINCY - 100);

	Rectangle(hDC, 100, WINCY - 200, 150, WINCY - 250);
}

void CPlayer::Release()
{
	
}
