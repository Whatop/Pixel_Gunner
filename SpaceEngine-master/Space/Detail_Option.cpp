#include "stdafx.h"
#include "UI.h"
#include "Detail_Option.h"

Detail_Option::Detail_Option(int type)
{
	GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
	m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	Choice_Button[0] = Sprite::Create(L"Painting/Option/Cancle.png");
	Choice_Button[0]->SetPosition(1920 / 2-415, 940);

	Choice_Button[1] = Sprite::Create(L"Painting/Option/Reset.png");
	Choice_Button[1]->SetPosition(1920 / 2, 940);

	Choice_Button[2] = Sprite::Create(L"Painting/Option/Check.png");
	Choice_Button[2]->SetPosition(1920 / 2+ 435, 940);

	if (type == _Start) { // 게임 플레이 : 커서  모양, 미니맵 표시(항상,전투중 제외,없음),

		Mouse_Shape = Sprite::Create(L"Painting/Mouse/Mouse.png");
		MineMap = Sprite::Create(L"Painting/Mouse/Mouse.png");

		//마우스 모양
		m_Name[0] = Sprite::Create(L"Painting/Option/Game_Play/Cusor.png");

		// 마우스 화살표
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 300);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 300);

		// 미니맵 표시 화살표
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 550);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 550);

		//미니맵 표시
		m_Name[1] = Sprite::Create(L"Painting/Option/Game_Play/MeniMap.png");
		
	}
	else if (type == _Control) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)

	// 구르기, W, S, A, D,  
		Sprite* KeyChange;
	}
	else if (type == _Vidio) { // 비디오 : 전체화면, 해상도(1440:900,1920:1080), 감마, 잔해양(시체),크기
		//창 크기
		Sprite* Window;
	}
	else {	// 오디오 : 음악 볼륨(배경음), 음향 볼륨(구른다, 총..), UI 볼륨(확인버튼이나 그런 소리)
			//볼륨설정
		Sprite* Sound;
	}
	m_Type = type;
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // 게임 플레이 : 커서 모양, 미니맵 표시(항상,전투중 제외,없음),
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			//GameMgr::GetInst()->Shape(true);
			INPUT->ButtonDown(false);
		}
		Line = 1;
		ColBox = true; 
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->Shape(false);

			//GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		Line = 2;
		ColBox = true;
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[2])) { // 비디오 : 전체화면, 해상도(1440:900,1920:1080), 감마, 잔해양(시체),크기
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;

			INPUT->ButtonDown(false);
		}
		Line = 3;
		ColBox = true;
	}
}

void Detail_Option::Name()
{
	if (m_Type == _Start) {
		m_Name[0]->SetPosition(Mouse_Shape->m_Position.x, Mouse_Shape->m_Position.y - 100);
		m_Name[1]->SetPosition(MineMap->m_Position.x, MineMap->m_Position.y - 100);
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // 게임 플레이 : 커서 모양, 미니맵 표시(항상,전투중 제외,없음),
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
				//GameMgr::GetInst()->Shape(true);
				INPUT->ButtonDown(false);
			}
			Line = 1;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->Shape(false);

				//GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
				INPUT->ButtonDown(false);
			}
			Line = 2;
			ColBox = true;
		}
	}
}

void Detail_Option::Shape()
{

}

void Detail_Option::Direction() //그 활성화 상태일때 오른쪽왼쪽누르면 되는것으로, 아닐땐 회색
{
	if (m_Type == _Start) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[2])) { // 화살표 왼쪽
			Arrow_Button[2]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown() || INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(true);
				INPUT->ButtonDown(false);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[3])) { // 화살표 오른쪽
			Arrow_Button[3]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown() || INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(false);
				INPUT->ButtonDown(false);
			}
		}
		else {
			Arrow_Button[2]->SetScale(1.f, 1.f);
			Arrow_Button[3]->SetScale(1.f, 1.f);
		}
		if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
			GameMgr::GetInst()->Shape(true);
		}
		else if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
			GameMgr::GetInst()->Shape(false);
		}
	}
}

void Detail_Option::Reset()
{
	GameMgr::GetInst()->m_MouseShape = MouseShape::none;
	GameMgr::GetInst()->menimap = 1;
}

void Detail_Option::Update(float deltaTime, float Time)
{
	if (m_Type == _Start) {
		Mouse_Shape = UI::GetInst()->m_Mouse;
		Minemap_Option = GameMgr::GetInst()->menimap;
		if (Minemap_Option == 1) {
			MineMap = Sprite::Create(L"Painting/Option/Game_Play/always.png");
		}
		else if (Minemap_Option == 2) {
			MineMap = Sprite::Create(L"Painting/Option/Game_Play/notbattle.png");
		}
		else {
			MineMap = Sprite::Create(L"Painting/Option/Game_Play/not_used.png");
		}
		Mouse_Shape->SetPosition(1920 / 2, 300);
		
		MineMap->SetPosition(1920 / 2, 550);
	}
	Name();
	Order();
	Direction();
}

void Detail_Option::Render()
{
	m_BG->Render();
	Choice_Button[0]->Render();
	Choice_Button[1]->Render();
	Choice_Button[2]->Render();
	if (m_Type == _Start) {
		for (int h = 0; h < 4; h++) {
			Arrow_Button[h]->Render();
		}
		m_Name[0]->Render();
		m_Name[1]->Render();
		Mouse_Shape->Render();
		MineMap->Render();
	}

}
