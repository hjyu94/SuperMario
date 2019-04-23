#pragma once
#include "Monster.h"
class CMushroomMon :
	public CMonster
{
public:
	CMushroomMon();
	virtual ~CMushroomMon();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	virtual void Collision_Proc(CObj* pCounterObj) override;
};

