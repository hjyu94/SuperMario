#pragma once
#include "Obj.h"
class CBlock :
	public CObj
{
public:
	CBlock();
	virtual ~CBlock();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

