//커밋테스트입니다 4:16
#include "stdafx.h"
#include "MainGame.h"

#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"

#include "Player.h"
#include "GrowMushroom.h"
#include "TileBlock.h"
#include "FlowerMon.h"
#include "PlantBlock.h"

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
	//1) 플레이어
	CObj* pPlayer = CAbstractFactory<CPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, pPlayer);
	CObjMgr::Get_Instance()->Set_Player(pPlayer);
	
	//2) 아이템
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CGrowMushroom>::Create());

	//3) 몬스터
	CPlantBlock* pPlant = CAbstractFactory<CPlantBlock>::Create(500, 500);
	CFlowerMon* pFlowerMon = CAbstractFactory<CFlowerMon>::Create(500, 500);
	CObjMgr::Get_Instance()->AddObject(OBJID::MONSTER, pFlowerMon);
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, pPlant);

	CPlantBlock* pPlant2 = CAbstractFactory<CPlantBlock>::Create(300, 500);
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, pPlant2);

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
	Rectangle (m_hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Get_Instance()->Release();
}

