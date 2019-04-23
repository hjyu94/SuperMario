#include "stdafx.h"
#include "GrowMushroom.h"


CGrowMushroom::CGrowMushroom()
	:m_bCreate_Action(true), m_fCreate_Y(0.f)
{
}


CGrowMushroom::~CGrowMushroom()
{
}

void CGrowMushroom::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 40.f;
	m_fSpeed = 5.f;
	m_bIsGrounded = true;
	m_tInfo.fX = 400.f;///�ϴ� ����NUM ->�� ��ġ
	m_tInfo.fY = 400.f;///�ϴ� ����NUM ->�� ��ġ

	m_fCreate_Y = m_tInfo.fY;
}

int CGrowMushroom::Update()
{
	if (m_bIsDead)
	{
		//�׾����� 
		m_Vel_Y = 0.f;
		return OBJ_DEAD;
	}

	///���� �׼�
	if (m_bCreate_Action && m_bIsGrounded)
	{
		m_tInfo.fY -= (m_fSpeed - 3.f);
		if (m_tInfo.fY <= m_fCreate_Y - ITEM_MOVE_SIZE)
		{
			m_bCreate_Action = false;
		}
	}
	if (!m_bCreate_Action && m_bIsGrounded)
	{
		m_tInfo.fX += m_fSpeed;
	}

//�ӽ�////////////////////////////////////
	//�浹üũ
	if (m_tInfo.fX >= 425.f)
	{
		m_bIsGrounded = false;
	}
	//��������
	if (!m_bCreate_Action && !m_bIsGrounded)
	{
		m_Vel_Y += 0.4f;
		m_tInfo.fY += m_Vel_Y;
	}
	if (m_tInfo.fY >= 100.f)
	{
		m_bIsGrounded = true;
	}
	else
	{
		m_Vel_Y = 0.f;
	}


////////////////////////////////////////

	return OBJ_ALIVE;
}

void CGrowMushroom::LateUpdate()
{
}

void CGrowMushroom::Render(HDC hDC)
{
	CObj::UpdateRect();

	HBRUSH myBrush = NULL;
	HBRUSH oldBrush;
	myBrush = (HBRUSH)CreateSolidBrush(RGB(250, 244, 192));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CGrowMushroom::Release()
{
}
