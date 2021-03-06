#pragma once

class UI : public Singleton<UI>
{
	Sprite* m_Interface[15];
	Sprite* m_OptionUI[10];
	TextMgr* m_UItext;
	TextMgr* m_Hptext;
	//TextMgr* m_Damagetext;
	//구르기 시간
	int m_Ammo[4];
	//시간 gt
	int MonsterCount;
	std::string Stage_Name;// + 난이도
	int shape;
	float m_Timer;
	int m_Time[4];

	Vec2 EnemyPos;
	Vec2 Pos;
public:
	UI();
	~UI();
	
	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();

	void Timer();
	void Mouse();

	//bool m_Hit;
	//float m_DelayTime;

	float m_HpGage;
	float m_DashGage;
	float m_AmmoGage;

	bool One;
	bool Two;

	Sprite* m_Mouse;
};

