#include "stdafx.h"
#include "MainScene.h"
#include "Stage1.h"
#include "Option.h"

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::Init()
{
	GameMgr::GetInst()->m_Scene = CurrentScene::MAINSCENE;
	BackGround = Sprite::Create(L"Painting/TestBackGround.png");
	BackGround->SetPosition(1920 / 2, 1080 / 2);

	Start_Button = Sprite::Create(L"Painting/Button/Start_1.png");
	Start_Button->SetPosition(265, 665);

	Option_Button = Sprite::Create(L"Painting/Button/Control_1.png");
	Option_Button->SetPosition(265, 760);

	Difficulty_Button = Sprite::Create(L"Painting/Button/Difficulty_1.png");
	Difficulty_Button->SetPosition(265, 855);

	Exit_Button = Sprite::Create(L"Painting/Button/Exit_1.png");
	Exit_Button->SetPosition(265, 945);

	Difficulty = Sprite::Create(L"Painting/Button/Difficulty_Easy.png");
	Difficulty->SetPosition(268, 540);
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	if (GameMgr::GetInst()->GetScene()== CurrentScene::MAINSCENE) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Start_Button)) {
			Start_Button = Sprite::Create(L"Painting/Button/Start_2.png");
			Start_Button->SetPosition(265, 665);
			if (INPUT->GetButtonDown()) {
				SceneDirector::GetInst()->ChangeScene(new Stage1);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Option_Button)) {
			Option_Button = Sprite::Create(L"Painting/Button/Control_2.png");
			Option_Button->SetPosition(265, 760);
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Option(), "Option");
				BackGround->m_Visible = false;
				Start_Button->m_Visible = false;
				Option_Button->m_Visible = false;
				Difficulty_Button->m_Visible = false;
				Exit_Button->m_Visible = false;
				Difficulty->m_Visible = false;
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Difficulty_Button)) {
			Difficulty_Button = Sprite::Create(L"Painting/Button/Difficulty_2.png");
			Difficulty_Button->SetPosition(265, 855);
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->AddDifficulty();
				INPUT->ButtonDown(false);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Exit_Button)) {
			Exit_Button = Sprite::Create(L"Painting/Button/Exit_2.png");
			Exit_Button->SetPosition(265, 945);
			if (INPUT->GetButtonDown()) {
				App::GetInst()->Release();
				exit(0);
			}
		}
		else {
			Init();
		}

		if (GameMgr::GetInst()->GetDifficulty() == Game_Difficulty::EASY) {
			Difficulty = Sprite::Create(L"Painting/Button/Difficulty_Easy.png");
			Difficulty->SetPosition(268, 540);
		}
		else if (GameMgr::GetInst()->GetDifficulty() == Game_Difficulty::NOMAL) {
			Difficulty = Sprite::Create(L"Painting/Button/Difficulty_Nomal.png");
			Difficulty->SetPosition(268, 540);
		}
		else if (GameMgr::GetInst()->GetDifficulty() == Game_Difficulty::HARD) {
			Difficulty = Sprite::Create(L"Painting/Button/Difficulty_Hard.png");
			Difficulty->SetPosition(268, 540);
		}
	}
	else if(GameMgr::GetInst()->GetScene() == CurrentScene::OPTION){
		if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN) { // 옵션이 켜졌을때
			Init();
			ObjMgr->DeleteObject("Option");
			GameMgr::GetInst()->m_Scene = CurrentScene::MAINSCENE;
			
		}
	}
}

void MainScene::Render()
{
	BackGround->Render();
	Start_Button->Render();
	Option_Button->Render();
	Exit_Button->Render();
	Difficulty_Button->Render();
	Difficulty->Render();
}
