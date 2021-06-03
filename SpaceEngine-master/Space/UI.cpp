#include "stdafx.h"
#include "MainScene.h"
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

	m_OptionUI[0] = Sprite::Create(L"Painting/UI/OptionBG.png"); // BG
	m_OptionUI[0]->SetPosition(300, 700);
	m_OptionUI[0]->SetScale(2, 2);

	m_OptionUI[1] = Sprite::Create(L"Painting/UI/OptionName.png",D3DCOLOR_XRGB(0, 0, 0)); // Name
	m_OptionUI[1]->SetPosition(300, 300);

	m_OptionUI[2] = Sprite::Create(L"Painting/UI/Back.png", D3DCOLOR_XRGB(0, 0, 0)); // µ¹¾Æ°¡±â
	m_OptionUI[2]->SetPosition(300, 500);
	
	m_OptionUI[3] = Sprite::Create(L"Painting/UI/giveup.png", D3DCOLOR_XRGB(0, 0, 0)); // Æ÷±âÇÏ±â(Å¸ÀÌÆ²·Î)
	m_OptionUI[3]->SetPosition(300, 600);

	m_OptionUI[4] = Sprite::Create(L"Painting/UI/EXIT.png", D3DCOLOR_XRGB(0, 0, 0)); // °ÔÀÓÁ¾·á
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
	m_UItext = new TextMgr();
	m_UItext->Init(42, true, false, "±¼¸²");
	m_UItext->SetColor(255, 255, 255, 255);

	m_Hptext = new TextMgr();
	m_Hptext->Init(32, true, false, "±¼¸²");
	m_Hptext->SetColor(255, 255, 255, 255);
	
	//m_Damagetext = new TextMgr();
	//m_Damagetext->Init(32, true, false, "±¼¸²");
	//m_Damagetext->SetColor(255, 255, 255, 255);
	
	//m_DelayTime = 0;
	//m_Hit = false;

	SetCursor(NULL);
}

void UI::Release()
{
}

void UI::Update(float deltaTime, float Time)
{
	Mouse();
	if (GameMgr::GetInst()->_QuarkOption) {
		m_Interface[0]->m_Visible = false;
		for (int i = 0; i < 5; i++) {
			m_OptionUI[i]->m_Visible = true;
			m_OptionUI[0]->SetPosition(GameMgr::GetInst()->PlayerPos);
		}
		if (CollisionMgr::GetInst()->MouseWithBoxSize(m_OptionUI[2])) {
			if (INPUT->GetButtonDown()) {
				GameMgr::GetInst()->_QuarkOption = false;
				INPUT->ButtonDown(false);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_OptionUI[3])) {
			if (INPUT->GetButtonDown()) {
				INPUT->ButtonDown(false);
				GameMgr::GetInst()->_QuarkOption = false;
				GameMgr::GetInst()->Init();
				ObjMgr->Release();
				SceneDirector::GetInst()->ChangeScene(new MainScene);
			}
		}
		else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_OptionUI[4])) {

			if (INPUT->GetButtonDown()) {
				INPUT->ButtonDown(false);
				App::GetInst()->Release();
				exit(0);
			}
		}
	}
	else {
		m_Interface[0]->m_Visible = true;
		for (int i = 0; i < 5; i++) {
			m_OptionUI[i]->m_Visible = false;
			if (i != 0) {
				m_OptionUI[i]->SetPosition(GameMgr::GetInst()->PlayerPos.x-600, 
					GameMgr::GetInst()->PlayerPos.y - 400 + 100 * i);
			}
		}
		m_OptionUI[0]->SetPosition(GameMgr::GetInst()->PlayerPos);
		Timer();
	}
}

void UI::Render()
{
	if (GameMgr::GetInst()->_PlayerCreate){
		if (!GameMgr::GetInst()->_QuarkOption) {
			Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
			m_UItext->print(std::to_string(m_Time[0]) + std::to_string(m_Time[1]) + " : "
				+ std::to_string(m_Time[2]) + std::to_string(m_Time[3]), 150, 30);
			m_Hptext->print(std::to_string(GameMgr::GetInst()->m_Hp), 1920 / 2 - 150, 885);
			//¡Ä

			//m_UItext->print(std::to_string(GameMgr::GetInst()->m_WeaponStatus.Mag) + " / " + std::to_string(GameMgr::GetInst()->m_WeaponStatus.MaxMag) +
			//	"       " + std::to_string(GameMgr::GetInst()->m_WeaponStatus.Ammo), 1920 / 2 + 250, 885);

			m_UItext->print(std::to_string(GameMgr::GetInst()->m_WeaponStatus.Mag) + " / ¡Ä", 1920 / 2 + 250, 885);

			Renderer::GetInst()->GetSprite()->End();
		}
		m_HpGage = m_Interface[2]->m_Size.x / GameMgr::GetInst()->m_Max_Hp;
		int Hp = GameMgr::GetInst()->m_Max_Hp - GameMgr::GetInst()->m_Hp;
		if (GameMgr::GetInst()->m_Hp >= 0)
			{
				SetRect(&m_Interface[2]->m_Collision, m_Interface[2]->m_Position.x - m_Interface[2]->m_Size.x / 2, m_Interface[2]->m_Position.y - m_Interface[2]->m_Size.y / 2,
					m_Interface[2]->m_Position.x + m_Interface[2]->m_Size.x / 2, m_Interface[2]->m_Position.y + m_Interface[2]->m_Size.y / 2);

				m_Interface[2]->m_Rect.right = m_Interface[2]->m_Size.x - (Hp * m_HpGage);
			}

		m_DashGage = m_Interface[4]->m_Size.x / GameMgr::GetInst()->m_Max_Dash;
		int Dash = GameMgr::GetInst()->m_Max_Dash - GameMgr::GetInst()->m_DashCooltime * 100;
		if (GameMgr::GetInst()->m_DashCooltime >= 0)
			{
				SetRect(&m_Interface[4]->m_Collision, m_Interface[4]->m_Position.x - m_Interface[4]->m_Size.x / 2, m_Interface[4]->m_Position.y - m_Interface[4]->m_Size.y / 2,
					m_Interface[4]->m_Position.x + m_Interface[4]->m_Size.x / 2, m_Interface[4]->m_Position.y + m_Interface[4]->m_Size.y / 2);

				m_Interface[4]->m_Rect.right = m_Interface[4]->m_Size.x - (Dash * m_DashGage);
			}
		}

	
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
