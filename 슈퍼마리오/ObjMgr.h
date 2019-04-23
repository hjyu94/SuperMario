#pragma once

class CObj;
class CPlayer;

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	static CObjMgr* Get_Instance();
	static void Destroy_Instance();

public:
	void AddObject(OBJID::ID eID, CObj* pObj);
	int Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();

	void ScrollToRight(float _fSpeed);

public:
	CPlayer* Get_Player();
	static void Set_Player(CPlayer* _player);

private:
	static CObjMgr* m_pInstance; // 초기화 안 해주면 링킹 에러 발생
	OBJLIST m_Objlist[OBJID::END];
	static CPlayer* m_pPlayer;
};

