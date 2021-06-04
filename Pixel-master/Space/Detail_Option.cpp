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

	if (type == _Start) { // ���� �÷���

		Mouse_Shape = Sprite::Create(L"Painting/Mouse/Mouse.png");
		MineMap = Sprite::Create(L"Painting/Option/Game_Play/always.png");

		//���콺 ���
		m_Name[0] = Sprite::Create(L"Painting/Option/Game_Play/Cusor.png");

		// ���콺 ȭ��ǥ
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 300);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 300);

		//�̴ϸ� ǥ��
		m_Name[1] = Sprite::Create(L"Painting/Option/Game_Play/MeniMap.png");

		// �̴ϸ� ǥ�� ȭ��ǥ
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 550);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 550);
	}
	else if (type == _Control) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
		// ������, W, S, A, D,  
		Sprite* KeyChange;
	}
	else if (type == _Vidio) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
		//�ػ�
		m_Name[0] = Sprite::Create(L"Painting/Option/Vidio/Resolution.png");
		m_Name[0]->SetPosition(1920 / 2, 200);
		Resolution = Sprite::Create(L"Painting/Option/Vidio/Size_1.png");
		Resolution->SetPosition(1920 / 2, 275);

		//�ػ� ȭ��ǥ
		Arrow_Button[0] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[0]->SetPosition(1920 / 2 - 300, 275);

		Arrow_Button[1] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[1]->SetPosition(1920 / 2 + 300, 275);

		//��ũ�� â���,��üȭ��
		m_Name[1] = Sprite::Create(L"Painting/Option/Vidio/Screen.png");
		m_Name[1]->SetPosition(1920 / 2, 400);
		Window = Sprite::Create(L"Painting/Option/Vidio/Windowed.png");
		Window->SetPosition(1920 / 2, 475);

		// ��ũ�� ȭ��ǥ
		Arrow_Button[2] = Sprite::Create(L"Painting/Option/left.png");
		Arrow_Button[2]->SetPosition(1920 / 2 - 300, 475);

		Arrow_Button[3] = Sprite::Create(L"Painting/Option/right.png");
		Arrow_Button[3]->SetPosition(1920 / 2 + 300, 475);

		//����
		m_Name[2] = Sprite::Create(L"Painting/Option/Vidio/Gamma.png");
		m_Name[2]->SetPosition(1920 / 2, 600);
		Bar[0] = Sprite::Create(L"Painting/Option/Vidio/GammaBar.png");
		Bar[0]->SetPosition(1920 / 2, 675);
	}
	else {	// �����
		// ���� ����(�����)
		m_Name[0] = Sprite::Create(L"Painting/Option/Audio/Music_1.png");

		Bar[0]= Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[0]->SetPosition(1920 / 2 , 300);
		// ���� ����(������, ��..)
		m_Name[1] = Sprite::Create(L"Painting/Option/Audio/Music_2.png");

		Bar[1] = Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[1]->SetPosition(1920 / 2, 500);

		//UI ����(Ȯ�ι�ư�̳� �׷� �Ҹ�)
		m_Name[2] = Sprite::Create(L"Painting/Option/Audio/Music_3.png");

		Bar[2] = Sprite::Create(L"Painting/Option/Audio/SoundBar.png");
		Bar[2]->SetPosition(1920 / 2, 700);
	}
	m_Type = type;
	m_Line = 1;
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { //���
		for (int h = 0; h < 3; h++) {
			if (h != 0) {
				Choice_Button[h]->R = 120;
				Choice_Button[h]->G = 120;
				Choice_Button[h]->B = 120;
			}
		}
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		if (_Start) {
			m_Line = 3;
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // �ʱ�ȭ
		for (int h = 0; h < 3; h++) {
			if (h != 1) {
				Choice_Button[h]->R = 120;
				Choice_Button[h]->G = 120;
				Choice_Button[h]->B = 120;
			}
		}
		if (INPUT->GetButtonDown()) {
			Reset();
			INPUT->ButtonDown(false);
		}
		if (_Start) {
			m_Line = 4;
		}
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[2])) { // Ȯ��
		for (int h = 0; h < 3; h++) {
			if (h != 2) {
				Choice_Button[h]->R = 120;
				Choice_Button[h]->G = 120;
				Choice_Button[h]->B = 120;
			}
		}
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			INPUT->ButtonDown(false);
		}
		if (_Start) {
			m_Line = 5;
		}
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

void Detail_Option::Reset()
{
	if (m_Type == _Start) {
		GameMgr::GetInst()->m_MouseShape = MouseShape::none;
		GameMgr::GetInst()->menimap = 1;
	}
}

void Detail_Option::Update(float deltaTime, float Time)
{
	Name();
	Start();
	Order();
	Line();
}

void Detail_Option::Line()
{
	if (m_Type == _Start) {
		if (m_Line == 1) {
			for (int h = 0; h < 2; h++) {
				Arrow_Button[h]->R = 255;
				Arrow_Button[h]->G = 255;
				Arrow_Button[h]->B = 255;
			}
			m_Name[0]->R = 255;
			m_Name[0]->G = 255;
			m_Name[0]->B = 255;
			Mouse_Shape->R = 255;
			Mouse_Shape->G = 255;
			Mouse_Shape->B = 255;

			if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
				GameMgr::GetInst()->Shape(true);
			}
			else if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
				GameMgr::GetInst()->Shape(false);
			}
		}
		else if (m_Line == 2) {
			for (int h = 2; h < 4; h++) {
				Arrow_Button[h]->R = 255;
				Arrow_Button[h]->G = 255;
				Arrow_Button[h]->B = 255;
			}
			m_Name[1]->R = 255;
			m_Name[1]->G = 255;
			m_Name[1]->B = 255;
			MineMap->R = 255;
			MineMap->G = 255;
			MineMap->B = 255;
			if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(true);
			}
			else if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(false);
			}
		}
		else if (m_Line == 3) {
			Choice_Button[0]->R = 255;
			Choice_Button[0]->G = 255;
			Choice_Button[0]->B = 255;
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			}
		}
		else if (m_Line == 4) {
			Choice_Button[1]->R = 255;
			Choice_Button[1]->G = 255;
			Choice_Button[1]->B = 255;
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				Reset();
			}
		}
		else if (m_Line == 5) {
			Choice_Button[2]->R = 255;
			Choice_Button[2]->G = 255;
			Choice_Button[2]->B = 255;
			if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN) {
				GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
			}
		}
		if (INPUT->GetKey(VK_DOWN) == KeyState::DOWN) {
			if (m_Line >= 5) {
				m_Line = 1;
			}
			else {
				m_Line++;
			}
		}
		else if (INPUT->GetKey(VK_UP) == KeyState::DOWN) {
			if (m_Line <= 1) {
				m_Line = 5;
			}
			else {
				m_Line--;
			}
		}
	}
}

void Detail_Option::Start()
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

		if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[0])) { // ȭ��ǥ ����

			Arrow_Button[0]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->Shape(true);
				INPUT->ButtonDown(false);
			}
			m_Line = 1;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[1])) { // ȭ��ǥ ������
			Arrow_Button[1]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->Shape(false);
				INPUT->ButtonDown(false);
			}
			m_Line = 1;
		}
		else {
			for (int h = 0; h < 2; h++) {
				Arrow_Button[h]->R = 120;
				Arrow_Button[h]->G = 120;
				Arrow_Button[h]->B = 120;
				Arrow_Button[h]->SetScale(1.f, 1.f);
			}
			m_Name[0]->R = 120;
			m_Name[0]->G = 120;
			m_Name[0]->B = 120;
			Mouse_Shape->R = 120;
			Mouse_Shape->G = 120;
			Mouse_Shape->B = 120;
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[2])) { // ȭ��ǥ ����
			Arrow_Button[2]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown() || INPUT->GetKey(VK_LEFT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(true);
				INPUT->ButtonDown(false);
			}
			m_Line = 2;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Arrow_Button[3])) { // ȭ��ǥ ������
			Arrow_Button[3]->SetScale(1.5f, 1.5f);
			if (INPUT->GetButtonDown() || INPUT->GetKey(VK_RIGHT) == KeyState::DOWN) {
				GameMgr::GetInst()->MeniMap(false);
				INPUT->ButtonDown(false);
			}
			m_Line = 2;
		}
		else {
			for (int h = 2; h < 4; h++) {
				Arrow_Button[h]->R = 120;
				Arrow_Button[h]->G = 120;
				Arrow_Button[h]->B = 120;
				Arrow_Button[h]->SetScale(1.f, 1.f);
			}
			m_Name[1]->R = 120;
			m_Name[1]->G = 120;
			m_Name[1]->B = 120; 
			MineMap->R = 120;
			MineMap->G = 120;
			MineMap->B = 120;
		}
	}
}

void Detail_Option::Control()
{
}

void Detail_Option::Vidio()
{
}

void Detail_Option::Audio()
{
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
