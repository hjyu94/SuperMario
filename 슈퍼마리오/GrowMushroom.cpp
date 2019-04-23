#include "stdafx.h"
#include "GrowMushroom.h"


CGrowMushroom::CGrowMushroom()
{
}


CGrowMushroom::~CGrowMushroom()
{
}

void CGrowMushroom::Initialize()
{
}

int CGrowMushroom::Update()
{
	if (m_bIsDead)
	{
		return OBJ_DEAD;
	}

	return OBJ_ALIVE;
}

void CGrowMushroom::LateUpdate()
{
}

void CGrowMushroom::Render(HDC hDC)
{
}

void CGrowMushroom::Release()
{
}
