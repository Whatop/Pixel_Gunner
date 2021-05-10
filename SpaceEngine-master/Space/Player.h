#pragma once

enum class Weapon_Type {
	GUN1,
	GUN2,
	BASICGUN,
	MELEE,
	GRENADE,
	NONE
};

// 1번 기본무기, 2번 무기, 3번 근접무기, 4번 슈류탄
class Player : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_Hand_Left;
	Sprite* m_Hand_Right;
	Sprite* m_Weapon;//이거 따로만들까 고민중 일단 만들기
	
	int m_Type;

	float m_Speed;
	float DelayTime;
	float m_Timer;
	float m_DashCooltime;
	float m_DashTime;

	bool m_Dash;
	int HaveGun;


	Vec2 Dire;
	Vec2 Mouse;

	Weapon_Type m_Weapon_Type;
	std::vector<std::string>m_Weapon_Tag;
public:
	Player(Vec2 Pos);
	~Player();
	
	void Move();
	void Hand();
	void WeaponRotate();
	void Weapon_Type();
	void Shooting();
	void Buff();
	void Dash();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

