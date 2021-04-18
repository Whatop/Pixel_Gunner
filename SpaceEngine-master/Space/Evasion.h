#pragma once
class Evasion : public Object
{
	Sprite* m_Obj;
public:
	Evasion(Vec2 Pos);
	~Evasion();

	float timer;

	void Update(float deltaTime, float Time);
	void Render();
};

