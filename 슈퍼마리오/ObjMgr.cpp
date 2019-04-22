#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

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
