#pragma once
#include "Obj.h"
class CGrowMushroom :
	public CObj
{
public:
	CGrowMushroom();
	~CGrowMushroom();
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	int  m_bCreate_Action;
	float m_fCreate_Y;
	float m_fCreate_X;
};

