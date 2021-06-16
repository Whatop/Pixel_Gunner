#include "stdafx.h"
#include "Missile.h"

Missile::Missile(std::wstring fileName)
{
	m_Missile = Sprite::Create(fileName);
	m_Missile->SetParent(this);
	SetPosition(GameMgr::GetInst()->PlayerPos);

	Rad = GameMgr::GetInst()->GrenDir;
	turnRadian = std::atan2(Rad.y, Rad.x);
	vrad = 0.001f;
	Homing = false;
}

Missile::~Missile()
{
}

void Missile::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Enemy");
	if (!Homing) {
		Monster = GameMgr::GetInst()->MonsterPos - m_Position;
		D3DXVec2Normalize(&Dire, &Monster);
		//vrad += dt * 0.1;
		vrad = 0.019f;

		float pi2 = D3DX_PI * 2;
		float diff = std::atan2f(Dire.y, Dire.x) - turnRadian;
		while (diff < -D3DX_PI) diff += pi2;
		while (diff >= D3DX_PI) diff -= pi2;

		if (abs(diff) < vrad)
			turnRadian += diff;
		else {
			turnRadian += (diff < 0 ? -vrad : vrad);
		}

		Dire.y = sin(turnRadian);
		Dire.x = cos(turnRadian);
		m_Rotation = std::atan2f(Dire.y, Dire.x);
		Translate(Dire.x * 700 * dt, Dire.y * 700 * dt);
	}
	else {
		ObjMgr->RemoveObject(this);
		ObjMgr->AddObject(new EffectMgr(L"Painting/Missile/", 1, 0.5f, 8, m_Position), "Effect");
	}
	
}

void Missile::Render()
{
	m_Missile->Render();
}

void Missile::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Enemy") {
				Homing = true;
	}
}
