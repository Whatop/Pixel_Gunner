#include "stdafx.h"
#include "Missile.h"

Missile::Missile(std::wstring fileName)
{
	m_Missile = Sprite::Create(fileName);
	m_Missile->SetParent(this);
	SetPosition(GameMgr::GetInst()->PlayerPos);

	std::cout << "생성" << std::endl;
}

Missile::~Missile()
{
}

void Missile::Update(float deltaTime, float Time)
{
	Monster = GameMgr::GetInst()->MonsterPos - m_Position;
	D3DXVec2Normalize(&Dire, &Monster);
	float cross = (std::atan2(Dire.y, Dire.x));
	float angle = acosf((Monster.x * Dire.x) + (Monster.y * Dire.y));

	if (cross > 0)   // 외적 값이 음수이면 시계방향으로 회전
		angle *= -1;
	Rotate(angle * turnRadian * dt);
	turnRadian += 5 * dt;
	Translate(Dire.x * 1000 * dt, Dire.y * 1000 * dt);
}

void Missile::Render()
{
	m_Missile->Render();
}

void Missile::OnCollision(Object* obj)
{
}
