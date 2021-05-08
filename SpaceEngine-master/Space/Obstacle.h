#pragma once
class Obstacle : public Object
{
private:
	Sprite* m_Obstacle;
public:
	Obstacle(std::wstring fileName, Vec2 Pos);
	~Obstacle();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

