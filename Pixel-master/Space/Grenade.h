#pragma once
class Grenade : public Object
{
	Sprite* m_Grenade;
	float DelayTime, AAddTime;

	Vec2 Mouse, Dire;
	int Ammo;
	bool Limit;

public:
	Grenade();
	~Grenade();

	void GrenadeRotato();
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

