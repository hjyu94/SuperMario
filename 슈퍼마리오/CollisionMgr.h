#pragma once
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void CollisionRect(OBJLIST& DestList, OBJLIST& SourList);
	static void CollisionSphere(OBJLIST& DestList, OBJLIST& SourList);
	static void EatItem(OBJLIST& DestList, OBJLIST& SourList);

private:
	static bool CheckSphere(CObj* pDest, CObj* pSour);
};

