#include "stdafx.h"
#include "Star.h"


CStar::CStar()
	:m_bCreate_Action(0)
{
}


CStar::~CStar()
{
}

void CStar::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 5.f;
	m_bIsGrounded = true;
	m_tInfo.fX = 350.f;///�ϴ� ����NUM ->�� ��ġ
	m_tInfo.fY = 400.f;///�ϴ� ����NUM ->�� ��ġ

	m_fCreate_Y = m_tInfo.fY;
}

int CStar::Update()
{
	if (m_bIsDead)
	{
		//�׾����� 
		m_Vel_Y = 0.f;
		return OBJ_DEAD;
	}

	///���� �׼� üũ
	if (0 == m_bCreate_Action)
	{
		//�ö󰡱�
		m_tInfo.fY -= (m_fSpeed - 3.f);

		if (m_tInfo.fY <= m_fCreate_Y - ITEM_MOVE_SIZE)
		{
			m_bCreate_Action = 1;
		}
	}
	if (1 == m_bCreate_Action)
	{
		//������
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		if (m_tInfo.fY >= 515.f)
		{
			m_bCreate_Action = 2;
		}
	}
	if (2 == m_bCreate_Action)
	{
		m_tInfo.fX += m_fSpeed;
		if (m_tInfo.fX >= WINCX)
		{
			m_bCreate_Action = 3;
		}
	}
	if (3 == m_bCreate_Action)
	{
		m_tInfo.fX -= m_fSpeed;
	}

	return OBJ_ALIVE;
}

void CStar::LateUpdate()
{
}

void CStar::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CStar::Release()
{
}
