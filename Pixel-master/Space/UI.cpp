#include "stdafx.h"
#include "MainScene.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init() // ?? ĭ + ?Ѿ? ĭ + HP + ???? 
{
	m_Mouse = Sprite::Create(L"Painting/Mouse/Mouse.png");
	m_Mouse->SetPosition(INPUT->GetMousePos());

	m_Interface[0] = Sprite::Create(L"Painting/UI/Timer.png");
	m_Interface[0]->SetPosition(150, 50);

	m_Interface[1] = Sprite::Create(L"Painting/UI/Bar.png"); 
	m_Interface[1]->SetPosition(1920 / 2, 1000);

	m_Interface[2] = Sprite::Create(L"Painting/UI/HPBar.png");
	m_Interface[2]->SetPosition(1920 / 2, 1000);

	m_Interface[3] = Sprite::Create(L"Painting/UI/Bar.png"); 
	m_Interface[3]->SetPosition(1920 / 2, 975);

	m_Interface[4] = Sprite::Create(L"Painting/UI/RoolBar.png"); 
	m_Interface[4]->SetPosition(1920 / 2, 975);
	
	m_Interface[3]->SetScale(1, 0.5f);
	m_Interface[4]->SetScale(1, 0.5f);

	m_Interface[5] = Sprite::Create(L"Painting/UI/Bar.png"); 
	m_Interface[5]->SetPosition(50, 875);
	m_Interface[5]->m_Rotation = D3DXToRadian(90);

	m_Interface[6] = Sprite::Create(L"Painting/UI/AmmoBar.png");
	m_Interface[6]->SetPosition(50, 875);
	m_Interface[6]->m_Rotation = D3DXToRadian(180);	

	m_Interface[7] = Sprite::Create(L"Painting/UI/Temp.png");
	m_Interface[7]->SetPosition(1920 / 2, 930);
	m_Interface[7]->m_Visible = false;

	m_Interface[8] = Sprite::Create(L"Painting/UI/2.png"); // GUN2
	m_Interface[9] = Sprite::Create(L"Painting/UI/1.png"); // GUN1
	m_Interface[10] = Sprite::Create(L"Painting/UI/3.png"); // BasicGun
	m_Interface[11] = Sprite::Create(L"Painting/UI/4.png"); // Melee
	m_Interface[12] = Sprite::Create(L"Painting/UI/5.png"); // ??

	m_Interface[8]->SetPosition(1920 / 2 - 300, 930);
	m_Interface[9]->SetPosition(1920 / 2 - 200, 930);
	m_Interface[10]->SetPosition(1920 / 2 - 100, 930);
	m_Interface[11]->SetPosition(1920 / 2, 930);
	m_Interface[12]->SetPosition(1920 / 2 + 100, 930);
	//ȭ??ǥ? ???? ĭ?ֵ??
	

	m_OptionUI[0] = Sprite::Create(L"Painting/UI/OptionBG.png"); // BG
	m_OptionUI[0]->SetPosition(300, 700);
	m_OptionUI[0]->SetScale(2, 2);

	m_OptionUI[1] = Sprite::Create(L"Painting/UI/OptionName.png",D3DCOLOR_XRGB(0, 0, 0)); // Name
	m_OptionUI[1]->SetPosition(300, 300);

	m_OptionUI[2] = Sprite::Create(L"Painting/UI/Back.png", D3DCOLOR_XRGB(0, 0, 0)); // ???ư???
	m_OptionUI[2]->SetPosition(300, 500);
	
	m_OptionUI[3] = Sprite::Create(L"Painting/UI/giveup.png", D3DCOLOR_XRGB(0, 0, 0)); // ?????ϱ?(Ÿ??Ʋ??)
	m_OptionUI[3]->SetPosition(300, 600);

	m_OptionUI[4] = Sprite::Create(L"Painting/UI/EXIT.png", D3DCOLOR_XRGB(0, 0, 0)); // ????????
	m_OptionUI[4]->SetPosition(300, 700);
	
	for (int i = 0; i < 5; i++) {
		m_OptionUI[i]->m_Visible = true;
	}
	for (int i = 8; i <= 12; i++) {
		m_Interface[i]->R = 130;
		m_Interface[i]->G = 130;
		m_Interface[i]->B = 130;
		if(i!=9)
		m_Interface[i]->SetScale(2, 2);
	}

	if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE1 || GameMgr::GetInst()->GetScene() == CurrentScene::STAGE2) {
		
		for (int i = 0; i <= 12; i++) {
			ObjMgr->AddObject(m_Interface[i], "UI");
		}
	}
	m_UItext = new TextMgr();
	m_UItext->Init(42, true, false, "????");
	m_UItext->SetColor(255, 255, 255, 255);	

	m_Hptext = new TextMgr();
	m_Hptext->Init(32, true, false, "????");
	m_Hptext->SetColor(255, 255, 255, 255);
	
	//m_Damagetext = new TextMgr();
	//m_Damagetext->Init(32, true, false, "????");
	//m_Damagetext->SetColor(255, 255, 255, 255);
	
	//m_DelayTime = 0;
	//m_Hit = false;
	One = true;
	Two = true;
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
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::GUN1) {
		m_Interface[9]->R = 255;
		m_Interface[9]->G = 255;
		m_Interface[9]->B = 255;

	}
	else {
		for (int i = 8; i <= 12; i++) {
			if (i == 9) {
				m_Interface[i]->R = 130;
				m_Interface[i]->G = 130;
				m_Interface[i]->B = 130;
			}
		}
	}
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::GUN2) {
		m_Interface[8]->R = 255;
		m_Interface[8]->G = 255;
		m_Interface[8]->B = 255;
	}
	else {
		for (int i = 8; i <= 12; i++) {
			if (i == 8) {
				m_Interface[i]->R = 130;
				m_Interface[i]->G = 130;
				m_Interface[i]->B = 130;
			}
		}
	}
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::BASICGUN) {
		m_Interface[10]->R = 255;
		m_Interface[10]->G = 255;
		m_Interface[10]->B = 255;
	}
	else {
		for (int i = 8; i <= 12; i++) {
			if (i == 10) {
				m_Interface[i]->R = 130;
				m_Interface[i]->G = 130;
				m_Interface[i]->B = 130;
			}
		}
	}
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::MELEE) {
		m_Interface[11]->R = 255;
		m_Interface[11]->G = 255;
		m_Interface[11]->B = 255;
		
	}
	else {
		for (int i = 8; i <= 12; i++) {
			if (i == 11) {
				m_Interface[i]->R = 130;
				m_Interface[i]->G = 130;
				m_Interface[i]->B = 130;
			}
		}
	}
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::GRENADE) {
		m_Interface[12]->R = 255;
		m_Interface[12]->G = 255;
		m_Interface[12]->B = 255;	
	}
	else {
		for (int i = 8; i <= 12; i++) {
			if (i == 12) {
				m_Interface[i]->R = 130;
				m_Interface[i]->G = 130;
				m_Interface[i]->B = 130;
			}
		}
	}	

	if (GameMgr::GetInst()->HaveGun == 1) {
		m_Interface[9]->m_Visible = true;
		m_Interface[8]->SetPosition(1920 / 2 - 200, 930);
		m_Interface[9]->SetPosition(1920 / 2 - 100, 930);
		m_Interface[10]->SetPosition(1920 / 2, 930);
		m_Interface[11]->SetPosition(1920 / 2 + 100, 930);
		m_Interface[12]->SetPosition(1920 / 2 + 200, 930);
	}
	else if (GameMgr::GetInst()->HaveGun == 2) {
		m_Interface[8]->m_Visible = true;
		m_Interface[8]->SetPosition(1920 / 2 - 200, 930);
		m_Interface[9]->SetPosition(1920 / 2 - 100, 930);
		m_Interface[10]->SetPosition(1920 / 2, 930);
		m_Interface[11]->SetPosition(1920 / 2 + 100, 930);
		m_Interface[12]->SetPosition(1920 / 2 + 200, 930);
	}
	else {
		m_Interface[8]->m_Visible = false;
		m_Interface[9]->m_Visible = false;
	}
	
}

void UI::Render()
{
	if (GameMgr::GetInst()->_PlayerCreate) {
		if (!GameMgr::GetInst()->_QuarkOption) {
			Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
			m_UItext->print(std::to_string(m_Time[0]) + std::to_string(m_Time[1]) + " : "
				+ std::to_string(m_Time[2]) + std::to_string(m_Time[3]), 150, 30);
			m_Hptext->print(std::to_string(GameMgr::GetInst()->m_Hp), 1920 / 2 - 150, 985);
			//??


			if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::BASICGUN) {
				m_UItext->print(std::to_string(GameMgr::GetInst()->m_WeaponStatus.Mag) + " ??", 1920-185, 855);
			}
			else if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::MELEE) {
				m_UItext->print("??", 1920 - 185, 855);
			}
			else {
				m_UItext->print(std::to_string(GameMgr::GetInst()->m_WeaponStatus.Mag) + " / " + std::to_string(GameMgr::GetInst()->m_WeaponStatus.MaxMag), 1920 - 185, 855);
			}
			m_UItext->print(std::to_string(GameMgr::GetInst()->m_WeaponStatus.Ammo) , 25,675);
			
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

		m_AmmoGage = m_Interface[6]->m_Size.y / GameMgr::GetInst()->m_WeaponStatus.MaxAmmo;
		int Ammo = GameMgr::GetInst()->m_WeaponStatus.MaxAmmo - GameMgr::GetInst()->m_WeaponStatus.Ammo;
		if (GameMgr::GetInst()->m_DashCooltime >= 0)
		{
			SetRect(&m_Interface[6]->m_Collision, m_Interface[6]->m_Position.x - m_Interface[6]->m_Size.x / 2, m_Interface[6]->m_Position.y - m_Interface[6]->m_Size.y / 2,
				m_Interface[6]->m_Position.x + m_Interface[6]->m_Size.x / 2, m_Interface[6]->m_Position.y + m_Interface[6]->m_Size.y / 2);

			m_Interface[6]->m_Rect.bottom = m_Interface[6]->m_Size.y - (Ammo * m_AmmoGage);
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
	ShowCursor(FALSE);
}
