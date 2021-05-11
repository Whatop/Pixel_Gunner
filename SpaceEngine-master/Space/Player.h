#pragma once

class Player : public Object
{
private:
	Sprite* m_Player;

	float m_Speed;
	float DelayTime;
	float m_Timer;
	float m_DashCooltime;
	float m_DashTime;

	bool m_Dash;

	Vec2 Dire;
	Vec2 Mouse;
	Weapon_Type m_Weapon_Type;

	std::vector<std::string>m_Weapon_Tag;
public:
	Player(Vec2 Pos);
	~Player();
	
	void Move();
	void Hand();
	void Buff();
	void Dash();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

