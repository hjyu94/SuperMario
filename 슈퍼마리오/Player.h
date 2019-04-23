#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void Collision_Proc(CObj* pCounterObj);
	
public:
	CObj* Create_Bullet();

public:
	// m_fAngle: 진행 방향
	PLAYER::STATE m_eCurState;
	PLAYER::STATE m_ePrevState;
};

