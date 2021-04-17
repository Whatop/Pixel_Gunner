#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Mouse;
	TextMgr* m_UI;
public:
	UI();
	~UI();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
};

