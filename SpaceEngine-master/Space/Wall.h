#pragma once
class Wall : public Object
{
private:
	Sprite* m_Wall;
public:
	Wall(Vec2 Pos);
	~Wall();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

