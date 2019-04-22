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
}

int CPlayer::Update()
{
	return 0;
}

void CPlayer::LateUpdate()
{
}

void CPlayer::Render(HDC hDC)
{
}

void CPlayer::Release()
{
}
