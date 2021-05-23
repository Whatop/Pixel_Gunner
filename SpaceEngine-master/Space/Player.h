#pragma once

class Player : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_ColBox[5];

	float m_Speed;
	float DelayTime;
	float m_Timer;
	float m_DashCooltime;
	float m_DashTime;

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
	void Esc();
	void ColBox();
	void Buff();
	void Dash();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

