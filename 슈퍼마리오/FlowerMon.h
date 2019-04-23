#pragma once
#include "Monster.h"

class CPlayer;

class CFlowerMon :
	public CMonster
{
public:
	CFlowerMon();
	virtual ~CFlowerMon();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	
public:

private:
	float m_fCenter_x;
	float m_fCenter_y;
	bool m_bInit;
	bool m_isStop;

	DWORD BulletCoolTime;
	CPlayer* m_pTarget;
};

