#pragma once
#include "Obj.h"
class CBreakBlock 
	:public CObj
{
public:
	CBreakBlock();
	~CBreakBlock();
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;


public:
	template<class T>
	CObj* CreateItem()
	{
		CObj* pObj = CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY);
		pObj->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		return pObj;
	}
private:
	void CreateCoin();
	void CreateFireFlower();
	void CreateGrowMush();
	void CreateLifeMush();
	void CreateStar();
};

