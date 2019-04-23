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
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				// �浹 
				pDst->Collision_Proc(pSrc);
				pSrc->Collision_Proc(pDst);
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

//������ �Ա�
void CCollisionMgr::EatItem(OBJLIST & DestList, OBJLIST & SourList)
{
	RECT rc = {};
	for (auto& pDst : DestList)
	{
		for (auto& pSrc : SourList)
		{
			if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
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



void CCollisionMgr::CollisionRectEX(OBJLIST & DestList, OBJLIST & SourList)
{
	{
		float fMoveX = 0.f, fMoveY = 0.f;
		for (auto& pDst : DestList)
		{
			for (auto& pSrc : SourList)
			{
				if (CheckPlayerBlockColl(pDst, pSrc, &fMoveX, &fMoveY))
				{
					float x = pSrc->Get_Info().fX;
					float y = pSrc->Get_Info().fY;

					if (fMoveX > fMoveY)
					{
						if (y < pDst->Get_Info().fY)
						{
							fMoveY *= -1.f;
						}
						pSrc->Set_Pos(x, y + fMoveY);
					}
					else
					{
						if (x < pDst->Get_Info().fX)
							fMoveX *= -1.f;

						pSrc->Set_Pos(x + fMoveX, y);
					}
				}
			}
		}

	}
}

bool CCollisionMgr::CheckPlayerBlockColl(CObj * pDest, CObj * pSour, float * pMoveX, float * pMoveY)
{
	// �������� ��. 
	float fRadiusSumX = (pDest->Get_Info().fCX * 0.5f) + (pSour->Get_Info().fCX * 0.5f);
	float fRadiusSumY = (pDest->Get_Info().fCY * 0.5f) + (pSour->Get_Info().fCY * 0.5f);

	float fDistX = fabs(pDest->Get_Info().fX - pSour->Get_Info().fX);
	float fDistY = fabs(pDest->Get_Info().fY - pSour->Get_Info().fY);

	if (fRadiusSumX >= fDistX && fRadiusSumY >= fDistY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY;
		return true;
	}

	return false;
}
