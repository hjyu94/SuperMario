#pragma once
#include "Obj.h"
class CBreakBlock :
	public CObj
{
public:
	CBreakBlock();
	~CBreakBlock();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

