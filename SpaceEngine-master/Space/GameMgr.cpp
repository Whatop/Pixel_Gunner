#include "stdafx.h"
#include "GameMgr.h"
#include "UI.h"
#include "Player.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::Init()
{
	_UICreate = false;
	_PlayerCreate = false;
}

void GameMgr::CreateUI()
{
	UI::GetInst()->Init();
	_UICreate = true;
}

void GameMgr::ReleaseUI()
{
	UI::GetInst()->Release();
	UI::GetInst()->ReleaseInst();
	_UICreate = false;
}

void GameMgr::CreatePlayer()
{
	_PlayerCreate = true;
	ObjMgr->AddObject(new Player,"Player");
}

void GameMgr::CreateMonster()
{

}
