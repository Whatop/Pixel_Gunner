#pragma once
class Grenade : public Object
{
	Sprite* m_Grenade;
public:
	Grenade();
	~Grenade();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

