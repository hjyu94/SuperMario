#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "LineMgr.h"
///Obj
#include "Player.h"
///아이템 <-- 추후 블럭에 들어갈것
#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"
#include "FlowerMon.h"
#include "PlantBlock.h"
#include "BreakBlock.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	///객체 생성
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, CAbstractFactory<CPlayer>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create());

	//1) 플레이어
	CObj* pPlayer = CAbstractFactory<CPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, pPlayer);
	CObjMgr::Get_Instance()->Set_Player((CPlayer*)pPlayer);
	
	//2) 아이템<-- 추후 블럭에 들어갈것
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CGrowMushroom>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CCoin>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CFireFlower>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CLifeMushroom>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CStar>::Create());

	//3) 몬스터
	/*CPlantBlock* pPlant = CAbstractFactory<CPlantBlock>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CFlowerMon* pFlowerMon = CAbstractFactory<CFlowerMon>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CObjMgr::Get_Instance()->AddObject(OBJID::MONSTER, pFlowerMon);
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, pPlant);*/

	//4) 벽, Obj, 타일 ????
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(680,400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1200, 530));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1600, 510));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1940, 460));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(2400, 460));

	//5) 선 그리기
	CLineMgr::Get_Instance()->Initialize();

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(2800,540));


}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CMainGame::Render()
{
	if (CObjMgr::Get_Instance()->Get_Player()->Get_iLife() < 0)
	{
		WCHAR lpOut[1024] = L"Game Over";
		TextOut(m_hDC, WINCX / 2, WINCY / 2, lpOut, lstrlen(lpOut));
	}
	else
	{
		Rectangle (m_hDC, 0, 0, WINCX, WINCY);
		CObjMgr::Get_Instance()->Render(m_hDC);
		CLineMgr::Get_Instance()->Render(m_hDC);
	}
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Get_Instance()->Release();
	CLineMgr::Get_Instance()->Release();
}

