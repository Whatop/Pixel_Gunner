#pragma once
class Bullet : public Object
{
	Sprite* m_Bullet;

public:
	Bullet(std::wstring filename, Vec2 arrival, Vec2 pos, float speed);
	~Bullet();

	float m_Speed;
	float m_Timer;

	Vec2 Dire;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

