#pragma once
#include "Obj.h"
class CLifeMushroom :
	public CObj
{
public:
	CLifeMushroom();
	~CLifeMushroom();
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	bool  m_bCreate_Action;
	bool  m_bBlock_Coll;
	float m_fCreate_Y;
	float m_fTime;
	float m_fPower;
};
