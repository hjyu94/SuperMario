#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void Collision_Proc(CObj* pCounterObj);
	
public:
	CObj* Create_Bullet();
	int Get_iLife();

public:
	// m_fAngle: ���� ����
	PLAYER::STATE m_eState;

	int m_iLife;
};

