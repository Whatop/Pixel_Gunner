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
				Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
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
				Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
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
				Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
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
				Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
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
//�̰� Ű����� �����Ѵٰ� ġ�� �׳� �� 4���� ���·� ����ٰ� ���� �ɵ� ex)1�� �����÷��� ��ư�� ���콺�� ������� Enter�� ��ư�� Ŭ���ϸ� ���� 
//	W������ �ö󰡰� S������ �������� 4���� �������� 1�� ���ϴ�. �ݴ뵵 �ְ�
//, void ??? ���� ���� �����ϵ��� �ϰ�
{
	ColBox = false;
	for (int h = 0; h < 4; h++) {
		Button[h]->R = 120;
		Button[h]->G = 120;
		Button[h]->B = 120;
	}

	if (Collsion) {
		Delay += dt;
		if (Delay > dt) {//ESC�� �����ֱ� ���Ͽ� ���ǰɾ��
			GameMgr::GetInst()->m_Scene = CurrentScene::OPTION; 
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[0])) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
				}
				ObjMgr->AddObject(new Detail_Option(_Start), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 1;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[1])) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
				}
				ObjMgr->AddObject(new Detail_Option(_Control), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 2;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[2])) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
				}
				ObjMgr->AddObject(new Detail_Option(_Vidio), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 3;
			ColBox = true;
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[3])) { // ����� : ���� ����(�����), ���� ����(������, ��..), UI ����(Ȯ�ι�ư�̳� �׷� �Ҹ�)
			if (INPUT->GetButtonDown()) {

				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					Collsion = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
				}
				ObjMgr->AddObject(new Detail_Option(_Audio), "Detail_Option");
				INPUT->ButtonDown(false);
			}
			Line = 4;
			ColBox = true;
		}
	}
	if (GameMgr::GetInst()->GetScene() == CurrentScene::DETAIL_OPTION) {
		if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN) { // �ɼǿ� ��ҳ� Ȯ��, ESC ���������� �ٲٱ�
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
