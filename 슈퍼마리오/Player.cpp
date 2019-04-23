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
	m_fAngle = 0; // ó�� ���� ����: ������: 0��
}

int CPlayer::Update()
{
	// ��������
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

	// Ű �Է�
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

	if (GetAsyncKeyState('Z')) // �Ѿ� �߻�
	{
		//CBullet* pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, m_fAngle+45);
		//CObjMgr::Get_Instance()->AddObject(OBJID::BULLET, );
	}

	// ġƮŰ, ���¿� ���� �÷��̾� �� ����
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
			if (m_tInfo.fCX == PLAYER_S_FCX) // ���� ���µ� IDLE, ���ݵ� IDLE
			{

			}
			else // ���� ���´� ū ���¿��µ�, ���� ���·� ������Ʈ �� ���
			{
				m_tInfo.fCX = PLAYER_S_FCX;
				m_tInfo.fCY = PLAYER_S_FCY;
				m_tInfo.fY += (PLAYER_B_FCY - PLAYER_S_FCY) * 0.5f;
			}
		}
		
		else if (m_eCurState != PLAYER::STATE::PS_IDLE)// ū ������� �ϴ� ����
		{
			if (m_tInfo.fCX == PLAYER_B_FCX) // ���� ���µ� ū ����, ������ ū ����
			{

			}
			else // ���� ���´� ���� ���¿��µ�, ū ���·� ������Ʈ �� ���
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
	case PLAYER::PS_IDLE: // ���
		break;
	case PLAYER::PS_RUNNING: // �Ķ��� 212, 244, 250
		myBrush = (HBRUSH)CreateSolidBrush(RGB(212, 244, 250));
		break;
	case PLAYER::PS_BIG: // ����� 255,255,212
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 212));
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
	
	// ��
	MoveToEx(hDC, 0, WINCY - 100, NULL);
	LineTo(hDC, WINCX, WINCY - 100);

	Rectangle(hDC, 100, WINCY - 200, 150, WINCY - 250);
}

void CPlayer::Release()
{
	
}
