#pragma once

class Player : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_ColBox[5];

	float m_Max_Hp;
	float m_Hp;

	float m_Speed;

	float m_Def;

	float m_Critical;

	float DelayTime;
	float m_Timer;

	float m_DashCooltime;
	float m_DashTime;
	float m_DashCool;

	bool Up;
	bool Down;
	bool Right;
	bool Left; 

	bool X[2];
	bool Y[2];
	
	bool m_Dash;

	float Multiple;//대각선 속도 제어

	Vec2 Dire;
	Vec2 Mouse;

	std::vector<std::string>m_Weapon_Tag;
public:
	Player(Vec2 Pos);
	~Player();
	
	void Move();
	void State();
	void ColBox();
	void Buff();
	void Dash();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

