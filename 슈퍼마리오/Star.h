#pragma once
#include "Obj.h"
class CStar :
	public CObj
{
public:
	CStar();
	~CStar();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	float m_fCreate_Y;
	bool  m_bCreate_Action;
	int iNum;
};
