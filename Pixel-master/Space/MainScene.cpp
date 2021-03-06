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

void MainScene::Init() //
{

	Camera::GetInst()->Init();
	GameMgr::GetInst()->m_Scene = CurrentScene::MAINSCENE;
	GameMgr::GetInst()->CreateUI();
	BackGround = Sprite::Create(L"Painting/TestBackGround.png");
	BackGround->SetPosition(1920 / 2, 1080 / 2);
	
	m_Button[0] = Sprite::Create(L"Painting/Button/Start_1.png");//Start
	m_Button[0]->SetPosition(265, 665);

	m_Button[1] = Sprite::Create(L"Painting/Button/Control_1.png");//Option
	m_Button[1]->SetPosition(265, 760);

	m_Button[2] = Sprite::Create(L"Painting/Button/Difficulty_1.png");//Difficulty
	m_Button[2]->SetPosition(265, 855);

	m_Button[3] = Sprite::Create(L"Painting/Button/Exit_1.png");//Exit
	m_Button[3]->SetPosition(265, 945);

	Difficulty = Sprite::Create(L"Painting/Button/Difficulty_Easy.png");
	Difficulty->SetPosition(268, 540);

	Line = 0;
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
// 마우스 닿고 있을때 키보드 못하도록 할수없나 근대 이거하려
{
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN) {
		GameMgr::GetInst()->Shape(false);
	}
	else if (INPUT->GetKey(VK_F3) == KeyState::DOWN) {
		GameMgr::GetInst()->Shape(true);
	}
	ColBox = false;
	if (GameMgr::GetInst()->GetScene() == CurrentScene::MAINSCENE) {
		Button();
		if (Line == 1) {
			Reset();
			m_Button[0] = Sprite::Create(L"Painting/Button/Start_2.png");
			m_Button[0]->SetPosition(265, 665);
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				SceneDirector::GetInst()->ChangeScene(new Stage1);
			}
		}
		else if (Line == 2) {
			Reset();
			m_Button[1] = Sprite::Create(L"Painting/Button/Control_2.png");
			m_Button[1]->SetPosition(265, 760);
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				ObjMgr->AddObject(new Option(), "Option");
				for (int h = 0; h < 4; h++) {
					m_Button[h]->m_Visible = false;
				}
			}
		}
		else if (Line == 3) {
			m_Button[0] = Sprite::Create(L"Painting/Button/Start_1.png");//Start
			m_Button[0]->SetPosition(265, 665);

			m_Button[1] = Sprite::Create(L"Painting/Button/Control_1.png");//Option
			m_Button[1]->SetPosition(265, 760);

			m_Button[2] = Sprite::Create(L"Painting/Button/Difficulty_2.png");
			m_Button[2]->SetPosition(265, 855);

			m_Button[3] = Sprite::Create(L"Painting/Button/Exit_1.png");//Exit
			m_Button[3]->SetPosition(265, 945);

			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				GameMgr::GetInst()->AddDifficulty();
				INPUT->ButtonDown(false);
			}
		}
		else if (Line == 4) {
			Reset();
			m_Button[3] = Sprite::Create(L"Painting/Button/Exit_2.png");
			m_Button[3]->SetPosition(265, 945);
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				App::GetInst()->Release();
				exit(0);
			}
		}
		else {
			Reset();
		}

		//ButtonDelay += dt;
		//if (ButtonDelay > 0.175f) { //누르고있을수록 빨라지는거 만들기
		if (!ColBox) {
			if (INPUT->GetKey(VK_DOWN) == KeyState::DOWN) {
				if (Line > 3) {
					Line = 1;
				}
				else {
					Line++;
				}
			}
			else if (INPUT->GetKey(VK_UP) == KeyState::DOWN) {
				if (Line < 2) {
					Line = 4;
				}
				else {
					Line--;
				}
			}
		}
	}
	else if (GameMgr::GetInst()->GetScene() == CurrentScene::OPTION) {
		if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN) { // 옵션이 켜졌을때
			Init();
			ObjMgr->DeleteObject("Option");
			GameMgr::GetInst()->m_Scene = CurrentScene::MAINSCENE;

		}
	}
	//}
}
void MainScene::Button()
{
		if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Button[0])) {
			if (INPUT->GetButtonDown()) {
				SceneDirector::GetInst()->ChangeScene(new Stage1);
				INPUT->ButtonDown(false);
			}
			Line = 1;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Button[1])) {
			if (INPUT->GetButtonDown()) {
				ObjMgr->AddObject(new Option(), "Option");
				for (int h = 0; h < 4; h++) {
					m_Button[h]->m_Visible = false;
				}
				INPUT->ButtonDown(false);
			}
			Line = 2;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Button[2])) {
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->AddDifficulty();
				INPUT->ButtonDown(false);
			}
			Line = 3;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Button[3])) {
			if (INPUT->GetButtonDown()) {
				App::GetInst()->Release();
				exit(0);
			}
			Line = 4;
			ColBox = true;
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

void MainScene::Reset()
{
	m_Button[0] = Sprite::Create(L"Painting/Button/Start_1.png");//Start
	m_Button[0]->SetPosition(265, 665);

	m_Button[1] = Sprite::Create(L"Painting/Button/Control_1.png");//Option
	m_Button[1]->SetPosition(265, 760);

	m_Button[2] = Sprite::Create(L"Painting/Button/Difficulty_1.png");//Difficulty
	m_Button[2]->SetPosition(265, 855);

	m_Button[3] = Sprite::Create(L"Painting/Button/Exit_1.png");//Exit
	m_Button[3]->SetPosition(265, 945);
}


void MainScene::Render()
{
	BackGround->Render();
	for (int h = 0; h < 4; h++) {
		m_Button[h]->Render();
	}
	Difficulty->Render();
}
