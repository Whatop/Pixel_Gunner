#include "stdafx.h"
#include "Option.h"

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

	//
	//Control[0] = Sprite::Create(L"Painting/Option/right.png");
	//Control[0]->SetPosition(1920 / 2 + 300, 400);

	//Control[1] = Sprite::Create(L"Painting/Option/left.png");
	//Control[1]->SetPosition(1920 / 2 - 300, 400);

	//Sound = Sprite::Create(L"Painting/Option/Sound.png");
	//Sound->SetPosition(1920 / 2, 1400);

	//Mouse_Shape = Sprite::Create(L"Painting/Player.png");
	//Mouse_Shape->SetPosition(100,100);

	//Window = Sprite::Create(L"Painting/Player.png");
	//Window->SetPosition(100, 100);

	//MouseColor = Sprite::Create(L"Painting/Player.png");
	//MouseColor->SetPosition(100, 100);

	//KeyChange = Sprite::Create(L"Painting/Player.png"); // ������
	//KeyChange->SetPosition(100, 100);

	ColBox = true;
	for (int h = 0; h < 4; h++) {
		Button[h]->R = 120;
		Button[h]->G = 120;
		Button[h]->B = 120;
	}
	
	//GameMgr::GetInst()->m_Scene = CurrentScene::OPTION;

}

void Option::Update(float deltaTime, float Time) 
//�̰� Ű����� �����Ѵٰ� ġ�� �׳� �� 4���� ���·� ����ٰ� ���� �ɵ� ex)1�� �����÷��� ��ư�� ���콺�� ������� Enter�� ��ư�� Ŭ���ϸ� ���� 
//	W������ �ö󰡰� S������ �������� 4���� �������� 1�� ���ϴ�. �ݴ뵵 �ְ�
//, void ??? ���� ���� �����ϵ��� �ϰ�
{
	for (int h = 0; h < 4; h++) {
		Button[h]->R = 120;
		Button[h]->G = 120;
		Button[h]->B = 120;
	}

	if (ColBox) {
		Delay += dt;
		if (Delay > dt) {//ESC�� �����ֱ� ���Ͽ� ���ǰɾ��
			GameMgr::GetInst()->m_Scene = CurrentScene::OPTION; 
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[0])) { // ���� �÷��� : Ŀ�� ���, �̴ϸ� ǥ��(�׻�,������ ����,����),

			Button[0]->R = 255;
			Button[0]->G = 255;
			Button[0]->B = 255;
			if (INPUT->GetButtonDown()) {
				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					ColBox = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
					GameMgr::GetInst()->m_Scene = CurrentScene::Detail_Option;
				}
				m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
				m_BG->SetPosition(1920 / 2, 1080 / 2);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[1])) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)
			Button[1]->R = 255;
			Button[1]->G = 255;
			Button[1]->B = 255;
			if (INPUT->GetButtonDown()) {
				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					ColBox = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
					GameMgr::GetInst()->m_Scene = CurrentScene::Detail_Option;
				}
				m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
				m_BG->SetPosition(1920 / 2, 1080 / 2);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[2])) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
			Button[2]->R = 255;
			Button[2]->G = 255;
			Button[2]->B = 255;
			if (INPUT->GetButtonDown()) {
				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					ColBox = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
					GameMgr::GetInst()->m_Scene = CurrentScene::Detail_Option;
				}
				m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
				m_BG->SetPosition(1920 / 2, 1080 / 2);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(Button[3])) { // ����� : ���� ����(�����), ���� ����(������, ��..), UI ����(Ȯ�ι�ư�̳� �׷� �Ҹ�)
			Button[3]->R = 255;
			Button[3]->G = 255;
			Button[3]->B = 255;
			if (INPUT->GetButtonDown()) {
				for (int h = 0; h < 4; h++) {
					Button[h]->m_Visible = false;
					ColBox = false; //fasle �ɾ��༭ ��ư�� �浹 ���� ��
					GameMgr::GetInst()->m_Scene = CurrentScene::Detail_Option;
				}
				m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
				m_BG->SetPosition(1920 / 2, 1080 / 2);
			}
		}
	}
	if (GameMgr::GetInst()->GetScene() == CurrentScene::Detail_Option) {
		if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN) { // �ɼǿ� ��ҳ� Ȯ��, ESC ���������� �ٲٱ�
			Init();
		}
	}
}

void Option::Render()
{
	m_BG->Render();
	for (int h = 0; h < 4; h++) {
		Button[h]->Render();
	}

	/*Control[0]->Render();
	Control[1]->Render();

	Sound->Render();

	Mouse_Shape->Render();

	Window->Render();

	MouseColor->Render();

	KeyChange->Render();*/
}
