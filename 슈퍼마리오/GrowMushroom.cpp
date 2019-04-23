#include "stdafx.h"
#include "GrowMushroom.h"


CGrowMushroom::CGrowMushroom()
	:m_bCreate_Action(false)
{
}


CGrowMushroom::~CGrowMushroom()
{
}

void CGrowMushroom::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 30.f;
	m_fSpeed = 5.f;

	m_tInfo.fX = 400.f;///�ϴ� ���ǻ��� ->�� ��ġ
	m_tInfo.fY = 400.f;///�ϴ� ���ǻ��� ->�� ��ġ
}

int CGrowMushroom::Update()
{
	if (m_bIsDead)
	{
		//�׾����� ���� �Լ�
		return OBJ_DEAD;
	}
	if (false == m_bCreate_Action)
	{
		m_tInfo.fY -= (m_fSpeed-3.f);
	}

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
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 187, 0));
	oldBrush = (HBRUSH)SelectObject(hDC, myBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, oldBrush);
	DeleteObject(myBrush);
}

void CGrowMushroom::Release()
{
}
