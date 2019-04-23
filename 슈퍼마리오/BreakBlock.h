#pragma once
#include "Block.h"
class CBreakBlock 
	:public CBlock
{
public:
	CBreakBlock();
	~CBreakBlock();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	virtual void Collision_Proc(CObj* pCounterObj) override;
private:
};

