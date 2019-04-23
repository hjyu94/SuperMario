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
				// 충돌 
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

	// 반지름의 합 구하기. 
	float fRadiusSum = (pDest->Get_Info().fCX * 0.5f) + (pSour->Get_Info().fCX * 0.5f);
	// 밑변과 높이 구하기. 
	float fx = pDest->Get_Info().fX - pSour->Get_Info().fX;
	float fy = pDest->Get_Info().fY - pSour->Get_Info().fY;

	// 피타고라스의 정리를 사용하여 거리를 구하기. 
	float fDist = sqrtf(fx * fx + fy * fy); // a^2 + b^2 = fDist;
	//거리와 반지름의 합으로 충돌판정. 
	return fDist <= fRadiusSum;
}
