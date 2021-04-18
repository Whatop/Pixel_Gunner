#pragma once
class Player : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_Hand;
	Sprite* m_Weapon;//이거 따로만들까 고민중 일단 만들기

	float m_Speed;
	float DelayTime;
	float m_Timer;
	float m_DashCooltime;
	float m_DashTime;

	bool m_Dash;

	Vec2 Dire;
	Vec2 Mouse;
public:
	Player();
	Player(Vec2 Pos);
	~Player();
	
	void Move();
	void WeaponRotate();
	void Shooting();
	void Buff();
	void Dash();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

