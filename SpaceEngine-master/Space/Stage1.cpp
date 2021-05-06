#include "stdafx.h"
#include "Stage1.h"
#include "Player.h"
#include "Wall.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init() 
{
	GameMgr::GetInst()->m_Scene = CurrentScene::STAGE1;
	m_BG = Sprite::Create(L"Painting/Stage1/BG.png");
	m_BG->SetPosition(1920 / 2, 1080-m_BG->m_Size.y/2);

	m_Obstacle[0] = Sprite::Create(L"Painting/Stage1/ColBox.png");
	m_Obstacle[0]->SetPosition(500, 300);

	for (int i = 1; i < 187; i++)
	{
		ObjMgr->AddObject(new Wall(Vec2(1920 - 40, 80 * -i + 1080 + 40)), "Wall");
		ObjMgr->AddObject(new Wall(Vec2(40, 80 * -i + 1080 + 40)), "Wall");

	}
	for (int i = 1; i < 24; i++)
	{
		ObjMgr->AddObject(new Wall(Vec2(80 * -i - 40+1920, -14920+1160)), "Wall");
		ObjMgr->AddObject(new Wall(Vec2(80 * -i - 40+1920, 1080-40)), "Wall");
	}

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
	m_BG->Render();
	m_Obstacle[0]->Render();
}

void Stage1::Release()
{
}
