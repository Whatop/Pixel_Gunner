#include "stdafx.h"
#include "Weapon.h"
#include "Bullet.h"

Weapon::Weapon(std::string weapontag, Vec2 Pos)
{
	m_Trans.assign(weapontag.begin(), weapontag.end());
	m_Weapon = Sprite::Create(L"Painting/Weapon/"+m_Trans + L".png");
	m_Weapon->SetParent(this);
	SetPosition(Pos);
	m_WeaponName = weapontag;
	std::cout << "�� ���� : "<<m_WeaponName<< std::endl;
	DelayTime = 0;
}

Weapon::~Weapon()
{
}

void Weapon::Fire()
{
	if (m_WeaponName == "Basicgun") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Heroine") {

		m_State.Atk = 30;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
				ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Bullet_Bore") {
		SetScale(2.f, 2.f);
		m_State.Atk = 40;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "The_Scrambler") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Vulcan_Cannon") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "RC_Rocket") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Thumbnail") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Marine_Sidearm") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Range = 10;
		m_State.Reload = 10;
		m_State.Speed = 1300;
		m_State.Mag = 10;
		m_State.Ammo = 10;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	if (m_WeaponName == "Blasphemy") {
		SetScale(2.f, 2.f);
		m_State.Atk = 10;
		m_State.Speed = 1300;
		m_State.Reload = 10;
		m_State.Range = 10;
		m_State.Mag= 10;
		m_State.Ammo = 500;

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, m_State.Speed), "Bullet");
			DelayTime = 0;
		}
	}
	//int Damege, Speed, Reload, Range, Mag, Ammo;
	GameMgr::GetInst()->UpdateWeaponStatus(m_State);
}

void Weapon::WeaponRotate()
{
	//   1.5
	//3 	  0		
	//	 1.5
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
}

void Weapon::Update(float delatTime, float Time)
{
	for (auto& iter : ObjMgr->m_Objects) {
		if(iter->m_Tag == "Player")
		m_Position = iter->m_Position;
	}
	Fire();
	WeaponRotate();
}

void Weapon::Render()
{
	m_Weapon->Render();
}

void Weapon::OnCollision(Object* obj)
{
}
