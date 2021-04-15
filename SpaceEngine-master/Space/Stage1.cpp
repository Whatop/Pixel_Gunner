#include "stdafx.h"
#include "Stage1.h"
#include "Player.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init() 
{
	ObjMgr->AddObject(new Player, "Player");
}

void Stage1::Update(float deltaTime, float Time)
{
}

void Stage1::Render()
{
}

void Stage1::Release()
{
}
