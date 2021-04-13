#include "stdafx.h"
#include "MainScene.h"
#include "Stage1.h"
#include "MainScene.h"
#include "MainScene.h"

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::Init()
{
	BackGround = Sprite::Create(L"Painting/Stage1/BackGround/Stage2.png");
	BackGround->SetPosition(1920 / 2, 1080 / 2);
	Start = Sprite::Create(L"Painting/Button/start.png");
	Start->SetPosition(200, 550);
	Option = Sprite::Create(L"Painting/Button/start.png");
	Option->SetPosition(200, 700);
	Exit = Sprite::Create(L"Painting/Button/start.png");
	Exit->SetPosition(200, 850);

	Rank = Sprite::Create(L"Painting/Button/start.png");
	Rank->SetPosition(200, 300);
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Start) && INPUT->GetButtonDown()) {
		SceneDirector::GetInst()->ChangeScene(new Stage1);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Option) && INPUT->GetButtonDown()) {
		SceneDirector::GetInst()->ChangeScene(new Stage1);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Exit) && INPUT->GetButtonDown()) {
		SceneDirector::GetInst()->ChangeScene(new Stage1);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Rank) && INPUT->GetButtonDown()) {
		SceneDirector::GetInst()->ChangeScene(new Stage1);
	}
}

void MainScene::Render()
{
	BackGround->Render();
	Start->Render();
	Option->Render();
	Exit->Render();
	Rank->Render();
}
