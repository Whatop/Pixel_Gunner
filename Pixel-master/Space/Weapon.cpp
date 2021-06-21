#include "stdafx.h"
#include "Weapon.h"
#include "Bullet.h"

Weapon::Weapon(std::string weapontag, Vec2 Pos)
{
	m_Trans.assign(weapontag.begin(), weapontag.end());
	m_Weapon = Sprite::Create(L"Painting/Weapon/" + m_Trans + L".png");
	m_Weapon->SetParent(this);
	SetPosition(Pos);

	m_Reload = Sprite::Create(L"Painting/Player/Reload.png");
	m_Reload->SetPosition(GameMgr::GetInst()->PlayerPos.x, GameMgr::GetInst()->PlayerPos.y-50);
	m_Reload->m_Visible = false;

	m_Stick = Sprite::Create(L"Painting/Player/Block.png");
	m_Stick->SetPosition(GameMgr::GetInst()->PlayerPos.x - m_Reload->m_Size.x/2 , GameMgr::GetInst()->PlayerPos.y - 50);
	m_Stick->m_Visible = false;
	m_WeaponName = weapontag;
	std::cout << "총 생성 : "<<m_WeaponName<< std::endl;

	m_State.Atk = 30;
	m_State.Range = 10;
	m_State.Reload = 2;
	m_State.Speed = 1000;
	
	m_State.MaxMag = 30;
	m_State.MaxAmmo = 130;

	m_State.Rebound = 0;

	m_State.Mag = 30;
	m_State.Ammo = 130;

	DelayTime = 1;
	ReloadTime = 0;
	RDown = false;
	Reload_Please = false;
}

Weapon::~Weapon()
{
}

void Weapon::Fire()
{
	if (m_WeaponName == "Basicgun") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.27f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			
			m_State.Mag--;

			m_State.Rebound = 15;
			DelayTime = 0;
		}

	}
	if (m_WeaponName == "Heroine") {

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.37f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");

			m_State.Mag--;

			m_State.Rebound = 20;
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Bullet_Bore") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "The_Scrambler") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown){ // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Vulcan_Cannon") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Thumbnail") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Marine_Sidearm") {
		SetScale(2.f, 2.f);

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	//int Damage, Speed, Reload, Range, Mag, Ammo, Rebound;
	GameMgr::GetInst()->UpdateWeaponStatus(m_State);
}

void Weapon::Reload()
{
	if (INPUT->GetKey('R') == KeyState::DOWN && m_State.Mag != m_State.MaxMag) {
		RDown = true;
		m_Reload->m_Visible = true;
		m_Stick->m_Visible = true;
	}
	if (m_State.Ammo > 0) {
		if (RDown) {
			ReloadTime += dt;
			if (ReloadTime > GameMgr::GetInst()->m_WeaponStatus.Reload) {
				RDown = false;
				ReloadTime = 0;
				Reload_Please = false;
				m_Reload->m_Visible = false;
				m_Stick->m_Visible = false;

				if (m_State.Ammo >= m_State.MaxMag) {
					if (m_WeaponName != "Basicgun") {
						m_State.Ammo = m_State.Ammo - m_State.MaxMag + m_State.Mag;
					}
					m_State.Mag = m_State.MaxMag;
				}
				else {
					while(m_State.Mag < m_State.MaxMag && m_State.Ammo > 0) {
						m_State.Mag++;
						m_State.Ammo--;
					}
				}
			}
		}
	}
	if (m_State.Mag <= 0) {
		Reload_Please = true;
	}
	m_Reload->SetPosition(GameMgr::GetInst()->PlayerPos.x, GameMgr::GetInst()->PlayerPos.y - 50);
	m_Stick->SetPosition(GameMgr::GetInst()->PlayerPos.x + 1 - m_Reload->m_Size.x / 2 + m_Reload->m_Size.x / GameMgr::GetInst()->m_WeaponStatus.Reload * ReloadTime, GameMgr::GetInst()->PlayerPos.y-50);
}

void Weapon::WeaponRotate()
{
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
}

void Weapon::Update(float delatTime, float Time)
{
	if (m_State.Rebound > 0) {
		m_State.Rebound -= dt * 5;
	}
	SetPosition(GameMgr::GetInst()->Left_Hand);
	Fire();
	WeaponRotate();
	Reload();
}

void Weapon::Render()
{
	m_Weapon->Render();
	m_Reload->Render();
	m_Stick->Render();
}

void Weapon::OnCollision(Object* obj)
{
}
