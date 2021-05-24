#pragma once

class UI : public Singleton<UI>
{
	Sprite* m_Interface[10];
	Sprite* m_OptionUI[10];
	TextMgr* m_UI;
	TextMgr* m_Hp;
	//구르기 시간
	int m_Ammo[4];
	//시간 gt
	int MonsterCount;
	std::string Stage_Name;// + 난이도
	int shape;
	float m_Timer;
	int m_Time[4];
public:
	UI();
	~UI();
	
	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();

	void Timer();
	void Mouse();
	float m_HpGage;
	float m_DashGage;

	Sprite* m_Mouse;
};

