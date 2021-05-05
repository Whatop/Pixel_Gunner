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

	if (type == _Start) { // 게임 플레이

		Mouse_Shape = Sprite::Create(L"Painting/Mouse/Mouse.png");
		MineMap = Sprite::Create(L"Painting/Option/Game_Play/always.png");

		//마우스 모양
		m_Name[0] = Sprite::Create(L"Painting/Option/Game_Play/Cusor.png");

		// 마우스 화살표
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 300);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 300);

		//미니맵 표시
		m_Name[1] = Sprite::Create(L"Painting/Option/Game_Play/MeniMap.png");

		// 미니맵 표시 화살표
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 550);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 550);
	}
	else if (type == _Control) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)
		// 구르기, W, S, A, D,  
		Sprite* KeyChange;
	}
	else if (type == _Vidio) { // 비디오 : 전체화면, 해상도(1440:900,1920:1080), 감마, 잔해양(시체),크기
		//해상도
		m_Name[0] = Sprite::Create(L"Painting/Option/Vidio/Resolution.png");
		m_Name[0]->SetPosition(1920 / 2, 200);
		Resolution = Sprite::Create(L"Painting/Option/Vidio/Size_1.png");
		Resolution->SetPosition(1920 / 2, 275);

		//해상도 화살표
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 275);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 275);

		//스크린 창모드,전체화면
		m_Name[1] = Sprite::Create(L"Painting/Option/Vidio/Screen.png");
		m_Name[1]->SetPosition(1920 / 2, 400);
		Window = Sprite::Create(L"Painting/Option/Vidio/Windowed.png");
		Window->SetPosition(1920 / 2, 475);

		// 스크린 화살표
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 475);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 475);

		//감마
		m_Name[2] = Sprite::Create(L"Painting/Option/Vidio/Gamma.png");
		m_Name[2]->SetPosition(1920 / 2, 600);
		Bar[0] = Sprite::Create(L"Painting/Option/Vidio/GammaBar.png");
		Bar[0]->SetPosition(1920 / 2, 675);
	}
	else {	// 오디오
		// 음악 볼륨(배경음)
		m_Name[0] = Sprite::Create(L"Painting/Option/Audio/Music_1.png");

		Bar[0]= Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[0]->SetPosition(1920 / 2 , 300);
		// 음향 볼륨(구른다, 총..)
		m_Name[1] = Sprite::Create(L"Painting/Option/Audio/Music_2.png");

		Bar[1] = Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[1]->SetPosition(1920 / 2, 500);

		//UI 볼륨(확인버튼이나 그런 소리)
		m_Name[2] = Sprite::Create(L"Painting/Option/Audio/Music_3.png");

		Bar[2] = Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[2]->SetPosition(1920 / 2, 700);
	}
	m_Type = type;
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { //취소
		Choice_Button[0]->R = 255;
		Choice_Button[0]->G = 255;
		Choice_Button[0]->B = 255;
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		Line = 1;
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // 초기화
		Choice_Button[1]->R = 255;
		Choice_Button[1]->G = 255;
		Choice_Button[1]->B = 255;
		if (INPUT->GetButtonDown()) {
			Reset();
			INPUT->ButtonDown(false);
		}
		Line = 2;
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[2])) { // 확인
		Choice_Button[2]->R = 255;
		Choice_Button[2]->G = 255;
		Choice_Button[2]->B = 255;
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		Line = 3;
	}
	else {
		for (int h = 0; h < 3; h++) {
			Choice_Button[h]->R = 120;
			Choice_Button[h]->G = 120;
			Choice_Button[h]->B = 120;
		}
	}
}

void Detail_Option::Name()
{
	if (m_Type == _Start) {
		m_Name[0]->SetPosition(Mouse_Shape->m_Position.x, Mouse_Shape->m_Position.y - 100);
		m_Name[1]->SetPosition(MineMap->m_Position.x, MineMap->m_Position.y - 100);
		
	}
	if (m_Type == _Audio) {
		m_Name[0]->SetPosition(Bar[0]->m_Position.x, Bar[0]->m_Position.y - 100);
		m_Name[1]->SetPosition(Bar[1]->m_Position.x, Bar[1]->m_Position.y - 100);
		m_Name[2]->SetPosition(Bar[2]->m_Position.x, Bar[2]->m_Position.y - 100);
	}
}

void Detail_Option::Shape()
{

}

void Detail_Option::Direction() //그 활성화 상태일때 오른쪽왼쪽누르면 되는것으로, 아닐땐 회색
{
	if (m_Type == _Start) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[0])) { // 화살표 왼쪽
			Arrow_Button[0]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->Shape(true);
				INPUT->ButtonDown(false);
			}
			Line = 1;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[1])) { // 화살표 오른쪽
			Arrow_Button[1]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->Shape(false);
				INPUT->ButtonDown(false);
			}
			Line = 2;
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
			GameMgr::GetInst()->MeniMap(true);
		}
		else if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
			GameMgr::GetInst()->MeniMap(false);
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
	if (m_Type == _Vidio) {
		for (int h = 0; h < 4; h++) {
			Arrow_Button[h]->Render();
		}
		for (int h = 0; h < 3; h++) {
			m_Name[h]->Render();
		}
		Bar[0]->Render();
		Window->Render();
		Resolution->Render();
	}
	if (m_Type == _Audio) {
		for (int h = 0; h < 3; h++) {
			m_Name[h]->Render();
			Bar[h]->Render();
		}
	}
}
