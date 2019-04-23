#pragma once
#include "Obj.h"
class CGrowMushroom :
	public CObj
{
public:
	CGrowMushroom();
	~CGrowMushroom();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	bool m_bCreate_Action;
};

