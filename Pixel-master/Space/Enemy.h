#pragma once
class Enemy : public Object
{
	Sprite* m_Enemy;
	Sprite* m_ColBox[5];
	float m_Hp, m_Speed;
	Vec2 m_Dir;
	
public:
	Enemy(Vec2 Pos);
	~Enemy();

	void Update(float deltaTime, float Time);

	void Move();
	void Shot();
	void ColBox();

	void Render();
	void OnCollision(Object* obj);
};

