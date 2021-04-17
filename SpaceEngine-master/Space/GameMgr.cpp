#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::CreateUI()
{
	
	_UICreate = true;
}

void GameMgr::ReleaseUI()
{
}

void GameMgr::CreatePlayer()
{
	_UICreate = true;
	ObjMgr->AddObject(new Player,"Player");
}

void GameMgr::CreateMonster()
{

}
