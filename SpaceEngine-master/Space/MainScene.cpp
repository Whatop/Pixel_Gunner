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
	
	m_Button[0] = Start_Button;
	m_Button[1] = Option_Button;
	m_Button[2] = Difficulty_Button;
	m_Button[3] = Exit_Button;
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
//이게 키보드랑 같이한다고 치면 그냥 그 4개의 상태로 만든다고 보면 될듯 ex)1번 게임플레이 버튼에 마우스가 닿았을때 Enter나 버튼을 클릭하면 시작 
//	W누르면 올라가고 S누르면 내려가고 4에서 내려가면 1로 갑니다. 반대도 있고연
//, void ??? 새로 만들어서 관리하도록 하고
{
	if (Line == 1) {
		Start_Button = Sprite::Create(L"Painting/Button/Start_2.png");
		Start_Button->SetPosition(265, 665);
		if (INPUT->GetButtonDown()) {
			SceneDirector::GetInst()->ChangeScene(new Stage1);
		}
	}
	else if (Line == 2) {
		Option_Button = Sprite::Create(L"Painting/Button/Control_2.png");
		Option_Button->SetPosition(265, 760);
		if (INPUT->GetButtonDown()) {
			ObjMgr->AddObject(new Option(), "Option");
			for (int h = 0; h < 4; h++) {
				m_Button[h]->m_Visible = false;
			}
		}
	}
	else if (Line == 3) {
		Difficulty_Button = Sprite::Create(L"Painting/Button/Difficulty_2.png");
		Difficulty_Button->SetPosition(265, 855);
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->AddDifficulty();
			INPUT->ButtonDown(false);
		}
	}
	else if (Line == 4) {
		Exit_Button = Sprite::Create(L"Painting/Button/Exit_2.png");
		Exit_Button->SetPosition(265, 945);
		if (INPUT->GetButtonDown()) {
			App::GetInst()->Release();
			exit(0);
		}
	}


	if (INPUT->GetKey(VK_DOWN) == KeyState::NONE) {

	}
	else if (INPUT->GetKey(VK_UP) == KeyState::NONE) {

	}
	Button();
}
void MainScene::Button()
{
	if (GameMgr::GetInst()->GetScene() == CurrentScene::MAINSCENE) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Start_Button)) {
			Line = 1;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Option_Button)) {
			Line = 2;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Difficulty_Button)) {
			Line = 3;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Exit_Button)) {
			Line = 4;
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
	else if (GameMgr::GetInst()->GetScene() == CurrentScene::OPTION) {
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
	for (int h = 0; h < 4; h++) {
		m_Button[h]->Render();
	}
	Difficulty->Render();
}
