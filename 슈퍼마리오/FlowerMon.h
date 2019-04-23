#pragma once
#include "Monster.h"

class CPlantBlock;

class CFlowerMon :
	public CMonster
{
public:
	CFlowerMon();
	virtual ~CFlowerMon();

public:
	// CObj��(��) ���� ��ӵ�
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
	CObj* m_pTarget;
};

