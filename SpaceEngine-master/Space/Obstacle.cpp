#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle(std::wstring fileName, Vec2 Pos)
{
	m_Obstacle = Sprite::Create(fileName);
	m_Obstacle->SetParent(this);
	SetPosition(Pos);
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float deltaTime, float Time)
{
}

void Obstacle::Render()
{
	m_Obstacle->Render();
}

void Obstacle::OnCollision(Object* obj)
{
}
