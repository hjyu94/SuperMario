#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void Initialize() =0;
	virtual int  Update() =0;
	virtual void LateUpdate()= 0;
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;

public:
	void UpdateRect(); 

public:
	const INFO& Get_Info()const { return m_tInfo; }
	const RECT& Get_Rect()const { return m_tRect; }

public:
	void Set_Pos(float fx, float fy);
	void Set_Angle(float _angle);
	void Set_Dead();

protected:
	INFO m_tInfo; 
	RECT m_tRect; 
	
	float m_fSpeed; 
	float m_fAngle; 
	bool m_bIsDead;
};

