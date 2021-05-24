#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init() // ÃÑ Ä­ + ÃÑ¾Ë Ä­ + HP + µîµî 
{
	m_Mouse = Sprite::Create(L"Painting/Mouse/Mouse.png");
	m_Mouse->SetPosition(INPUT->GetMousePos());

	m_Interface[0] = Sprite::Create(L"Painting/UI/Timer.png");
	m_Interface[0]->SetPosition(150, 50);

	m_Interface[1] = Sprite::Create(L"Painting/UI/BGHpBar.png"); // HPBar
	m_Interface[1]->SetPosition(1920 / 2, 900);

	m_Interface[2] = Sprite::Create(L"Painting/UI/HPBar.png"); // HP
	m_Interface[2]->SetPosition(1920 / 2, 900);

	m_Interface[3] = Sprite::Create(L"Painting/UI/BGRoolBar.png"); // HPBar
	m_Interface[3]->SetPosition(1920 / 2, 875);

	m_Interface[4] = Sprite::Create(L"Painting/UI/RoolBar.png"); // HP
	m_Interface[4]->SetPosition(1920 / 2, 875);
	

	m_Interface[3]->SetScale(1, 0.5f);
	m_Interface[4]->SetScale(1, 0.5f);

	m_OptionUI[0] = Sprite::Create(L"Painting/UI/OptionBG.png"); // HPBar
	m_OptionUI[0]->SetPosition(300, 700);

	m_OptionUI[1] = Sprite::Create(L"Painting/UI/OptionName.png",D3DCOLOR_XRGB(0, 0, 0)); // HPBar
	m_OptionUI[1]->SetPosition(300, 300);

	m_OptionUI[2] = Sprite::Create(L"Painting/UI/Back.png", D3DCOLOR_XRGB(0, 0, 0)); // HPBar
	m_OptionUI[2]->SetPosition(300, 500);
	
	m_OptionUI[3] = Sprite::Create(L"Painting/UI/giveup.png", D3DCOLOR_XRGB(0, 0, 0)); // HPBar
	m_OptionUI[3]->SetPosition(300, 600);

	m_OptionUI[4] = Sprite::Create(L"Painting/UI/EXIT.png", D3DCOLOR_XRGB(0, 0, 0)); // HPBar
	m_OptionUI[4]->SetPosition(300, 700);
	
	for (int i = 0; i < 5; i++) {
		m_OptionUI[i]->m_Visible = true;
	}

	if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE1 || GameMgr::GetInst()->GetScene() == CurrentScene::STAGE2) {
		
		ObjMgr->AddObject(m_Interface[0], "UI");

		ObjMgr->AddObject(m_Interface[1], "UI");
		ObjMgr->AddObject(m_Interface[2], "UI");

		ObjMgr->AddObject(m_Interface[3], "UI");
		ObjMgr->AddObject(m_Interface[4], "UI");
	}
	m_UI = new TextMgr();
	m_UI->Init(42, true, false, "±¼¸²");
	m_UI->SetColor(255, 255, 255, 255);

	m_Hp = new TextMgr();
	m_Hp->Init(32, true, false, "±¼¸²");
	m_Hp->SetColor(255, 255, 255, 255);
	SetCursor(NULL);
}

void UI::Release()
{
}

void UI::Update(float deltaTime, float Time)
{
	Timer();
	Mouse();
	if (GameMgr::GetInst()->_QuarkOption) {
		for (int i = 0; i < 5; i++) {
			m_OptionUI[i]->m_Visible = true;
			m_OptionUI[0]->SetPosition(GameMgr::GetInst()->PlayerPos);
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			m_OptionUI[i]->m_Visible = false;
			if (i != 0) {
				m_OptionUI[i]->SetPosition(GameMgr::GetInst()->PlayerPos.x-600, 
					GameMgr::GetInst()->PlayerPos.y-400+ 100 * i);
			}
		}
		m_OptionUI[0]->SetPosition(GameMgr::GetInst()->PlayerPos);
	}
}

void UI::Render()
{
	if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE1) {
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		m_UI->print(std::to_string(m_Time[0])+ std::to_string(m_Time[1])+" : "
			+ std::to_string(m_Time[2])+ std::to_string(m_Time[3]), 150, 30);
		m_Hp->print(std::to_string(GameMgr::GetInst()->m_Hp), 1920 / 2-150, 885);
		//m_UI->print("½Ã°£ : " + std::to_string(gt) + "\nÇÁ·¹ÀÓ : " + std::to_string(dt), 100, 100);
		m_UI->print("¸¶¿ì½º X : " + std::to_string((int)INPUT->GetMousePos().x) + "\n¸¶¿ì½º Y : " + std::to_string((int)INPUT->GetMousePos().y), 1620, 100);
		Renderer::GetInst()->GetSprite()->End();

		m_HpGage = m_Interface[2]->m_Size.x / GameMgr::GetInst()->m_Max_Hp;
		int Hp = GameMgr::GetInst()->m_Max_Hp - GameMgr::GetInst()->m_Hp;
		if (GameMgr::GetInst()->m_Hp >= 0)
		{
			SetRect(&m_Interface[2]->m_Collision, m_Interface[2]->m_Position.x - m_Interface[2]->m_Size.x / 2, m_Interface[2]->m_Position.y - m_Interface[2]->m_Size.y / 2,
				m_Interface[2]->m_Position.x + m_Interface[2]->m_Size.x / 2, m_Interface[2]->m_Position.y + m_Interface[2]->m_Size.y / 2);

			m_Interface[2]->m_Rect.right = m_Interface[2]->m_Size.x - (Hp * m_HpGage);
		}

		m_DashGage = m_Interface[4]->m_Size.x / GameMgr::GetInst()->m_Max_Dash;
		int Dash = GameMgr::GetInst()->m_Max_Dash - GameMgr::GetInst()->m_DashCooltime*100;
		if (GameMgr::GetInst()->m_DashCooltime >= 0)
		{
			SetRect(&m_Interface[4]->m_Collision, m_Interface[4]->m_Position.x - m_Interface[4]->m_Size.x / 2, m_Interface[4]->m_Position.y - m_Interface[4]->m_Size.y / 2,
				m_Interface[4]->m_Position.x + m_Interface[4]->m_Size.x / 2, m_Interface[4]->m_Position.y + m_Interface[4]->m_Size.y / 2);

			m_Interface[4]->m_Rect.right = m_Interface[4]->m_Size.x - (Dash * m_DashGage);
		}
	}
	/*else if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE2) {
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		m_UI->print("½Ã°£ : " + std::to_string(gt) + "\nÇÁ·¹ÀÓ : " + std::to_string(dt), 100, 100);
		Renderer::GetInst()->GetSprite()->End();
	}*/

	for (int i = 0; i < 5; i++) {
		m_OptionUI[i]->Render();
	}
	m_Mouse->Render();
}

void UI::Timer()
{
	m_Timer += dt;
	if (m_Timer >= 1) {
		m_Time[3]++;
		m_Timer = 0;
		if (m_Time[3] > 9) {
			m_Time[2]++;
			m_Time[3] = 0;
		}
		if (m_Time[2] > 5) {
			m_Time[1]++;
			m_Time[2] = 0;
		}
		if (m_Time[1] > 5) {
			m_Time[0]++;
			m_Time[1] = 0;
		}
		if (m_Time[0] > 5) {
			m_Time[0] = 0;
			m_Time[1] = 0;
			m_Time[2] = 0;
			m_Time[3] = 0;
		}
	}
}

void UI::Mouse()
{
	SetCursor(NULL);
	if (INPUT->GetKey('O') == KeyState::DOWN) {
		GameMgr::GetInst()->m_Hp -= 10;
	}
	if (INPUT->GetKey('P') == KeyState::DOWN) {
		GameMgr::GetInst()->m_Hp += 10;
	}
	if (GameMgr::GetInst()->m_MouseShape == MouseShape::scope) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/1.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::square) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/2.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::circle) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/3.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::bullet) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/4.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::cross) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/5.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::point) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/6.png");
	}
	else if (GameMgr::GetInst()->m_MouseShape == MouseShape::none) {
		m_Mouse = Sprite::Create(L"Painting/Mouse/Mouse.png");
	}
	m_Mouse->SetPosition(INPUT->GetMousePos());

}
