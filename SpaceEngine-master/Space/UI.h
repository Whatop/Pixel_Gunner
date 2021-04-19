#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Mouse;
	TextMgr* m_UI;
	int m_Hp;
	//구르기 시간
	int m_Ammo[4];
	//시간 gt
	int MonsterCount;
	std::string Stage_Name;// + 난이도
public:
	UI();
	~UI();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
};

