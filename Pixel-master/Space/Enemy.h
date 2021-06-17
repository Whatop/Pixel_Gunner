#pragma once
class Enemy : public Object
{
	Sprite* m_Enemy;
	Sprite* m_ColBox[5];
	//Idle Walk Die
	
	Sprite* m_Idle[3];
	Sprite* m_Walk;
	Sprite* m_Die;
	
	Sprite* m_Action;


	float m_Hp, m_Speed;
	Vec2 m_Dir;
	bool m_Hit;
	float DelayTime;
public:
	Enemy(Vec2 Pos);
	~Enemy();

	void Update(float deltaTime, float Time);

	void Move();
	void Shot();
	void ColBox();
	void Hit();

	void Render();
	void OnCollision(Object* obj);
};

