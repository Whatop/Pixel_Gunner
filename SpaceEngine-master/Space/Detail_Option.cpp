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

	if (type == _Start) { // 게임 플레이 : 커서 모양, 미니맵 표시(항상,전투중 제외,없음),
		//마우스 모양
		
		//마우스 색
		Sprite* MouseColor;
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
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // 게임 플레이 : 커서 모양, 미니맵 표시(항상,전투중 제외,없음),
		if (INPUT->GetButtonDown()) {
			//GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			UI::GetInst()->Shape(true);
			INPUT->ButtonDown(false);
		}
		Line = 1;
		ColBox = true; 
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)
		if (INPUT->GetButtonDown()) {
			UI::GetInst()->Shape(false);

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

void Detail_Option::Shape()
{

}

void Detail_Option::Init()
{
}

void Detail_Option::Update(float deltaTime, float Time)
{
	Order();
}

void Detail_Option::Render()
{
	m_BG->Render();
	Choice_Button[0]->Render();
	Choice_Button[1]->Render();
	Choice_Button[2]->Render();
}
