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

	if (type == _Start) { // ���� �÷��� : Ŀ��  ���, �̴ϸ� ǥ��(�׻�,������ ����,����),

		Mouse_Shape = Sprite::Create(L"Painting/Mouse/Mouse.png");
		MineMap = Sprite::Create(L"Painting/Mouse/Mouse.png");

		//���콺 ���
		m_Name[0] = Sprite::Create(L"Painting/Option/Game_Play/Cusor.png");

		// ���콺 ȭ��ǥ
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 300);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 300);

		// �̴ϸ� ǥ�� ȭ��ǥ
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 550);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 550);

		//�̴ϸ� ǥ��
		m_Name[1] = Sprite::Create(L"Painting/Option/Game_Play/MeniMap.png");
		
	}
	else if (type == _Control) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)

	// ������, W, S, A, D,  
		Sprite* KeyChange;
	}
	else if (type == _Vidio) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
		//â ũ��
		Sprite* Window;
	}
	else {	// ����� : ���� ����(�����), ���� ����(������, ��..), UI ����(Ȯ�ι�ư�̳� �׷� �Ҹ�)
			//��������
		Sprite* Sound;
	}
	m_Type = type;
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			//GameMgr::GetInst()->Shape(true);
			INPUT->ButtonDown(false);
		}
		Line = 1;
		ColBox = true; 
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->Shape(false);

			//GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		Line = 2;
		ColBox = true;
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[2])) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
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
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
				//GameMgr::GetInst()->Shape(true);
				INPUT->ButtonDown(false);
			}
			Line = 1;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
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

void Detail_Option::Direction() //�� Ȱ��ȭ �����϶� �����ʿ��ʴ����� �Ǵ°�����, �ƴҶ� ȸ��
{
	if (m_Type == _Start) {
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[2])) { // ȭ��ǥ ����
			Arrow_Button[2]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown() || INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(true);
				INPUT->ButtonDown(false);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[3])) { // ȭ��ǥ ������
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
