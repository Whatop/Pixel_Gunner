#include "stdafx.h"
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

	if (type == _Start) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),
		//���콺 ���
		Sprite* Mouse_Shape;
		//���콺 ��
		Sprite* MouseColor;
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
}

Detail_Option::~Detail_Option()
{
}

void Detail_Option::Order()
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[0])) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;

			INPUT->ButtonDown(false);
		}
		Line = 1;
		ColBox = true;
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(Choice_Button[1])) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
		if (INPUT->GetButtonDown()) {
			GameMgr::GetInst()->m_Scene = CurrentScene::NONE;

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
