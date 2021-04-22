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
	Difficulty = 1;
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

void GameMgr::AddDifficulty()
{
	if (Difficulty > 2) {
		Difficulty = 0;
	}
	if (Difficulty == 0) {
		GameDifficulty = Game_Difficulty::EASY;
	}
	if (Difficulty == 1) {
		GameDifficulty = Game_Difficulty::NOMAL;
	}
	if (Difficulty == 2) {
		GameDifficulty = Game_Difficulty::HARD;
	}
	Difficulty++;
}
