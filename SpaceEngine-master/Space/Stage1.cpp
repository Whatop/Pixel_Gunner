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
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN) {
		if (!m_Puase) {
			GameMgr::GetInst()->CreateUI();
			m_Puase = true;
		}
		else {
			GameMgr::GetInst()->ReleaseUI();
			m_Puase = false;
		}
	}

}

void Stage1::Render()
{
}

void Stage1::Release()
{
}
