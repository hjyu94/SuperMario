#include "stdafx.h"
#include "Player.h"
#include "AbstractFactory.h"

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
	// 수정함
	// 그래
	// 으하하

	// git add --all 
	// git commit -m "Message"
	// git push
}

int CPlayer::Update()
{
	// 나도 수정할거야
	if (!m_bIsGrounded)
	{
		m_Vel_Y += 1.f;
		m_tInfo.fY += m_Vel_Y;
	}
	else
	{
		m_Vel_Y = 0.f;
	}

	CObj::UpdateRect();
	return 0;
}

void CPlayer::LateUpdate()
{
	// pull
	// 수정하고
	// commit
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
	
}
