#pragma once



class UI : public Singleton<UI>
{
	TextMgr* m_UI;
	int m_Hp;
	//������ �ð�
	int m_Ammo[4];
	//�ð� gt
	int MonsterCount;
	std::string Stage_Name;// + ���̵�

	int shape;
public:
	UI();
	~UI();
	
	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
	Sprite* m_Mouse;
};

