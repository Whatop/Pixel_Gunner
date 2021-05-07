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


	m_UI = new TextMgr();
	m_UI->Init(42, true, false, "±¼¸²");
	m_UI->SetColor(255, 0, 0, 0);
}

void UI::Release()
{
}

void UI::Update(float deltaTime, float Time)
{
	SetCursor(NULL);
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

void UI::Render()
{
	m_Mouse->Render();
	//if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE1) {
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		m_UI->print("½Ã°£ : " + std::to_string(gt) + "\nÇÁ·¹ÀÓ : " + std::to_string(dt), 100, 100);
		m_UI->print("¸¶¿ì½º X : " + std::to_string((int)INPUT->GetMousePos().x) + "\n¸¶¿ì½º Y : " + std::to_string((int)INPUT->GetMousePos().y), 1620, 100);
		Renderer::GetInst()->GetSprite()->End();
	//}
	/*else if (GameMgr::GetInst()->GetScene() == CurrentScene::STAGE2) {
		Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		m_UI->print("½Ã°£ : " + std::to_string(gt) + "\nÇÁ·¹ÀÓ : " + std::to_string(dt), 100, 100);
		Renderer::GetInst()->GetSprite()->End();
	}*/
}
