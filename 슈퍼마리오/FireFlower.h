#pragma once
#include "Obj.h"
class CFireFlower :
	public CObj
{
public:
	CFireFlower();
	~CFireFlower();
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	float m_fCreate_Y;
	bool  m_bCreate_Action;
};
