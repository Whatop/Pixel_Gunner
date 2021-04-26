#include "stdafx.h"
#include "Detail_Option.h"

Detail_Option::Detail_Option(int a)
{
	GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
	m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
}

void Detail_Option::Init()
{
}

void Detail_Option::Update(float deltaTime, float Time)
{
}

void Detail_Option::Render()
{
	m_BG->Render();
}
