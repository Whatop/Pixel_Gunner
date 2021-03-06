#include "stdafx.h"
#include "Input.h"


Input::Input()
	: m_MousePosition(0.f, 0.f)
	, m_bCurrentState(false)
	, m_bPrevState(false)
	, m_ButtonDown(false)
	, m_RightButtonDown(false)
{
	ZeroMemory(&m_CurrentState, sizeof(m_CurrentState));
	ZeroMemory(&m_PrevState, sizeof(m_PrevState));
}

Input::~Input()
{
}

void Input::Update()
{
	KeyBoardUpdate();
	MouseUpdate();
}

void Input::ButtonDown(bool down)
{
	m_ButtonDown = down;
}

void Input::RightButtonDown(bool down)
{
	m_RightButtonDown = down;
}

KeyState Input::GetKey(int key)
{
	m_bPrevState = m_PrevState[key];
	m_bCurrentState = m_CurrentState[key];

	if (m_bPrevState == true && m_bCurrentState == true)
		return KeyState::PRESS;

	else if (m_bPrevState == true && m_bCurrentState == false)
		return KeyState::UP;

	else if (m_bPrevState == false && m_bCurrentState == true)
		return KeyState::DOWN;

	return KeyState::NONE;
}

void Input::KeyBoardUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevState[i] = m_CurrentState[i];
		m_CurrentState[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

void Input::MouseUpdate()
{
	RECT rc;
	POINT position,p1,p2;
	GetClientRect(App::GetInst()->GetHwnd(), &rc);
	p1.x = rc.left;
	p1.y = rc.top;
	p2.x = rc.right;
	p2.y = rc.bottom;
	ClientToScreen(App::GetInst()->GetHwnd(), &p1);
	ClientToScreen(App::GetInst()->GetHwnd(), &p2);
	rc.left = p1.x;
	rc.top = p1.y;
	rc.right = p2.x;
	rc.bottom = p2.y;
	ClipCursor(&rc);
	GetCursorPos(&position);
	ScreenToClient(App::GetInst()->GetHwnd(), &position);

	m_MousePosition.x = static_cast<float>(position.x) + Camera::GetInst()->Pos.x;
	m_MousePosition.y = static_cast<float>(position.y) + Camera::GetInst()->Pos.y;
}