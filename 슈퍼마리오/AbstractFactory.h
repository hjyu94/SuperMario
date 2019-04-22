#pragma once

template<class T>
class CAbstractFactory
{
public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}
	static CObj* Create(float fx, float fy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		return pObj;
	}
};
