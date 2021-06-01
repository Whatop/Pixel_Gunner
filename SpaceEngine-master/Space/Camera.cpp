#include"stdafx.h"
#include "Camera.h"
Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
}

void Camera::Init()
{
	m_Rotation = 0;
	m_Position = Vec2(0, 0);
	Mouse = Vec2(0, 0);
	m_Scale = Vec2(1.f, 1.f);
	Follow(nullptr);
}

void Camera::Follow(Object* obj)
{
	if (obj != nullptr)
	{

			
			if (GameMgr::GetInst()->_QuarkOption)
				Mouse = Vec2(0, 0);
			
				if (INPUT->GetMousePos().x >= obj->m_Position.x) {
					Mouse.x = (INPUT->GetMousePos().x - obj->m_Position.x) / 10;
				}
				else if (INPUT->GetMousePos().x <= obj->m_Position.x) {
					Mouse.x = (INPUT->GetMousePos().x - obj->m_Position.x) / 10;
				}
				if (INPUT->GetMousePos().y >= obj->m_Position.y) {
					Mouse.y = (INPUT->GetMousePos().y - obj->m_Position.y) / 10;
				}
				else if (INPUT->GetMousePos().y <= obj->m_Position.y) {
					Mouse.y = (INPUT->GetMousePos().y - obj->m_Position.y) / 10;
				}
			m_Position.x = obj->m_Position.x - App::GetInst()->m_Width / 2 + Mouse.x - GameMgr::GetInst()->m_WeaponStatus.Rebound * GameMgr::GetInst()->BulletDir.x;
			m_Position.y = obj->m_Position.y - App::GetInst()->m_Height / 2 + Mouse.y - GameMgr::GetInst()->m_WeaponStatus.Rebound * GameMgr::GetInst()->BulletDir.y;

			//	m_Position.x = obj->m_Position.x - App::GetInst()->m_Width / 2 - GameMgr::GetInst()->m_WeaponStatus.Rebound * GameMgr::GetInst()->BulletDir.x;
			//	m_Position.y = obj->m_Position.y - App::GetInst()->m_Height / 2 - GameMgr::GetInst()->m_WeaponStatus.Rebound * GameMgr::GetInst()->BulletDir.y;
	}
	
}

void Camera::Update(float deltaTime, float time)
{
	if (m_Rotation >= 360)
		m_Rotation = 0;
}

void Camera::Render()
{
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(m_Rotation));
	D3DXMatrixTranslation(&mTrans, -m_Position.x, -m_Position.y, 1.f);
	D3DXMatrixScaling(&mScale, m_Scale.x, m_Scale.y, 1.f);

	mWorld = mScale * mRot * mTrans;
}
