#pragma once
#include "Obj.h"
class CBlock :
	public CObj
{
public:
	CBlock();
	virtual ~CBlock();

	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

