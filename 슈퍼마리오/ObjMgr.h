#pragma once

class CObj;

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

public:
	static CObj* Get_Player();
	static void Set_Player(CObj* _player);

private:
	static CObjMgr* m_pInstance; // �ʱ�ȭ �� ���ָ� ��ŷ ���� �߻�
	OBJLIST m_Objlist[OBJID::END];
	static CObj* m_pPlayer;
};

