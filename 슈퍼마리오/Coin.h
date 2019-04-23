#pragma once
#include "Obj.h"
class CCoin :
	public CObj
{
public:
	CCoin();
	~CCoin();
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
	float m_fTime;
	float m_fPower;

};
