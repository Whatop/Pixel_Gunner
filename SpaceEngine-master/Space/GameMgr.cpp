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
	shape = 0;
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

void GameMgr::Shape(bool dir)//false 위로 true 아래로
{
	if (dir) {
		if (shape >= 6) {
			shape = 1;
		}
		else {
			shape++;
		}
	}
	else if(!dir){
		if (shape <= 1) {
			shape = 6;
		}
		else {
			shape--;
		}
	}
	if (shape == 1) {
		m_MouseShape = MouseShape::scope;
	}
	else if (shape == 2) {
		m_MouseShape = MouseShape::square;
	}
	else if (shape == 3) {
		m_MouseShape = MouseShape::circle;
	}
	else if (shape == 4) {
		m_MouseShape = MouseShape::bullet;
	}
	else if (shape == 5) {
		m_MouseShape = MouseShape::cross;
	}
	else if (shape == 6) {
		m_MouseShape = MouseShape::point;
	}
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
