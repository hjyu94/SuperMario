#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::CollisionRect(OBJLIST & DestList, OBJLIST & SourList)
{
	RECT rc = {}; 
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc,&pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				// �浹 
				pDst->CObj::Collision_Proc(pSrc);
				pSrc->CObj::Collision_Proc(pDst);
			}
		}
	}
}

void CCollisionMgr::CollisionSphere(OBJLIST & DestList, OBJLIST & SourList)
{
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (CheckSphere(pDst, pSrc))
			{
				pDst->Set_Dead();
				pSrc->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::CheckSphere(CObj * pDest, CObj * pSour)
{

	// �������� �� ���ϱ�. 
	float fRadiusSum = (pDest->Get_Info().fCX * 0.5f) + (pSour->Get_Info().fCX * 0.5f);
	// �غ��� ���� ���ϱ�. 
	float fx = pDest->Get_Info().fX - pSour->Get_Info().fX;
	float fy = pDest->Get_Info().fY - pSour->Get_Info().fY;

	// ��Ÿ����� ������ ����Ͽ� �Ÿ��� ���ϱ�. 
	float fDist = sqrtf(fx * fx + fy * fy); // a^2 + b^2 = fDist;
	//�Ÿ��� �������� ������ �浹����. 
	return fDist <= fRadiusSum;
}
