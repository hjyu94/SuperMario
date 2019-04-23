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
	bool  m_bCreate_Action;
	bool  m_bBlock_Coll;
	float m_fCreate_Y;
	float m_fTime;
	float m_fPower;
	
	float m_fTwingle;

};
