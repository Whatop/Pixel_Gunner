#pragma once
class Missile : public Object
{
	Sprite* m_Missile;
	Vec2 Monster, Dire;
	float turnRadian;
public:
	Missile(std::wstring fileName);
	~Missile();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

