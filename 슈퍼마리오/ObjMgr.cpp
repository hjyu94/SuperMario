#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"
#include "CollisionMgr.h"

#include "CollisionMgr.h"
CObjMgr* CObjMgr::m_pInstance = nullptr;
CPlayer* CObjMgr::m_pPlayer = nullptr;

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
}

CObjMgr * CObjMgr::Get_Instance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new CObjMgr;
	
	return m_pInstance;
}

void CObjMgr::Destroy_Instance()
{
	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CObjMgr::AddObject(OBJID::ID eID, CObj * pObj)
{
	m_Objlist[eID].emplace_back(pObj);
}

int CObjMgr::Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (OBJITER iter = m_Objlist[i].begin()
			; iter != m_Objlist[i].end()
			; )
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				if (*iter)
				{
					delete *iter;
					*iter = nullptr;
					iter = m_Objlist[i].erase(iter);
				}
			}
			else
				++iter;
		}
	}

	return 0;
}

void CObjMgr::LateUpdate()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			pObj->LateUpdate();
		}
	}

	// 충돌 처리
	CCollisionMgr::CollisionRect(m_Objlist[OBJID::MONSTER], m_Objlist[OBJID::PLAYER]);
	CCollisionMgr::CollisionRect(m_Objlist[OBJID::BLOCK], m_Objlist[OBJID::PLAYER]);
	CCollisionMgr::CollisionRect(m_Objlist[OBJID::MONSTER_BULLET], m_Objlist[OBJID::PLAYER]);

	CCollisionMgr::EatItem(m_Objlist[OBJID::ITEM], m_Objlist[OBJID::PLAYER]);
	CCollisionMgr::CollisionRectEX(m_Objlist[OBJID::OBjBLOCK], m_Objlist[OBJID::PLAYER]);
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			pObj->Render(hDC);
		}
	}
}

void CObjMgr::Release()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			delete pObj;
			pObj = nullptr;
		}
		m_Objlist[i].clear();
	}
}

void CObjMgr::ScrollToRight(float _fSpeed)
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			float fCurrentY = pObj->Get_Info().fY;
			float fCurrentX = pObj->Get_Info().fX;
			pObj->Set_Pos(fCurrentX - _fSpeed, fCurrentY);
		}
	}
}

CPlayer* CObjMgr::Get_Player()
{
	return m_pPlayer;
}

void CObjMgr::Set_Player(CPlayer * _player)
{
	m_pPlayer = _player;
}
