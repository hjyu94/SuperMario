//Ŀ���׽�Ʈ�Դϴ� 4:16
#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
///Obj
#include "Player.h"
#include "TileBlock.h"
#include "NomalBlock.h"
///������ <-- ���� ���� ����
#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"

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
	///��ü ����
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, CAbstractFactory<CPlayer>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CNomalBlock>::Create());

	///������ ���� <-- ���� ���� ����
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CCoin>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CFireFlower>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CGrowMushroom>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CLifeMushroom>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CStar>::Create());
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

