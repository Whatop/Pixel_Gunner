#include "stdafx.h"
#include "Option.h"
#include "Detail_Option.h"

Option::Option()
{
	GameMgr::GetInst()->m_Scene = CurrentScene::OPTION;
	Init();
}

Option::~Option()
{
}

void Option::Init()
{
	m_BG = Sprite::Create(L"Painting/Option/Option.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	Button[0] = Sprite::Create(L"Painting/Option/Player_Option.png");
	Button[0]->SetPosition(1920 / 2, 447);

	Button[1] = Sprite::Create(L"Painting/Option/Control_Option.png");
	Button[1]->SetPosition(1920 / 2, 523);

	Button[2] = Sprite::Create(L"Painting/Option/Vidio_Option.png");
	Button[2]->SetPosition(1920 / 2, 599);

	Button[3] = Sprite::Create(L"Painting/Option/Audio_Option.png");
	Button[3]->SetPosition(1920 / 2, 670);

	
	Collsion = true;
	ColBox = false;
	for (int h = 0; h < 4; h++) {
		Button[h]->R = 120;
		Button[h]->G = 120;
		Button[h]->B = 120;
	}
	
	//GameMgr::GetInst()->m_Scene = CurrentScene::OPTION;
}

void Option::Order()
{
	if (Line == 1) {
		Button[0]->R = 255;
		Button[0]->G = 255;
		Button[0]->B = 255;
		if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
		
			for (int h = 0; h < 4; h++) {
				Button[h]->m_Visible = false;
				Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
			}
			ObjMgr->AddObject(new Detail_Option(_Start), "Detail_Option");
		}
	}
	else if (Line == 2) {
		Button[1]->R = 255;
		Button[1]->G = 255;
		Button[1]->B = 255;
		if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
			
			for (int h = 0; h < 4; h++) {
				Button[h]->m_Visible = false;
				Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
			}
			ObjMgr->AddObject(new Detail_Option(_Control), "Detail_Option");
		}
	}
	else if (Line == 3) {
		Button[2]->R = 255;
		Button[2]->G = 255;
		Button[2]->B = 255;
		if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
			
			for (int h = 0; h < 4; h++) {
				Button[h]->m_Visible = false;
				Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
			}
			ObjMgr->AddObject(new Detail_Option(_Vidio), "Detail_Option");
		}
	}
	else if (Line == 4){
		Button[3]->R = 255;
		Button[3]->G = 255;
		Button[3]->B = 255;
		if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
		
			for (int h = 0; h < 4; h++) {
				Button[h]->m_Visible = false;
				Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				GameMgr::GetInst()->m_Scene = CurrentScene::DETAIL_OPTION;
			}
			ObjMgr->AddObject(new Detail_Option(_Audio), "Detail_Option");
		}
	}
	else {
		for (int h = 0; h < 4; h++) {
			Button[h]->R = 120;
			Button[h]->G = 120;
			Button[h]->B = 120;
		}
	}
}

void Option::Update(float deltaTime, float Time) 
//이게 키보드랑 같이한다고 치면 그냥 그 4개의 상태로 만든다고 보면 될듯 ex)1번 게임플레이 버튼에 마우스가 닿았을때 Enter나 버튼을 클릭하면 시작 
//	W누르면 올라가고 S누르면 내려가고 4에서 내려가면 1로 갑니다. 반대도 있고연
//, void ??? 새로 만들어서 관리하도록 하고
{
	ColBox = false;
	for (int h = 0; h < 4; h++) {
		Button[h]->R = 120;
		Button[h]->G = 120;
		Button[h]->B = 120;
	}

	if (Collsion) {
		Delay += dt;
		if (Delay > dt) {//ESC에 텀을주기 위하여 조건걸어둠
			GameMgr::GetInst()->m_Scene = CurrentScene::OPTION; 
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[0])) { // 게임 플레이 : 커서 모양, 미니맵 표시(항상,전투중 제외,없음),
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				}
				ObjMgr->AddObject(new Detail_Option(_Start), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 1;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[1])) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				}
				ObjMgr->AddObject(new Detail_Option(_Control), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 2;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[2])) { // 비디오 : 전체화면, 해상도(1440:900,1920:1080), 감마, 잔해양(시체),크기
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				}
				ObjMgr->AddObject(new Detail_Option(_Vidio), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 3;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[3])) { // 오디오 : 음악 볼륨(배경음), 음향 볼륨(구른다, 총..), UI 볼륨(확인버튼이나 그런 소리)
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle 걸어줘서 버튼의 충돌 판정 끔
				}
				ObjMgr->AddObject(new Detail_Option(_Audio), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 4;
			ColBox = true;
		}
	}
	if (GameMgr::GetInst()->GetScene() == CurrentScene::DETAIL_OPTION) {
		if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN) { // 옵션에 취소나 확인, ESC 눌렀을때로 바꾸기
			Init();
			ObjMgr->DeleteObject("Detail_Option");
		}
	}
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
	Order();
}

void Option::Render()
{
	m_BG->Render();
	for (int h = 0; h < 4; h++) {
		Button[h]->Render();
	}
}
