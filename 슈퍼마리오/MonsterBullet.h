#pragma once
#include "Obj.h"
class CMonsterBullet :
	public CObj
{
public:
	CMonsterBullet();
	virtual ~CMonsterBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

