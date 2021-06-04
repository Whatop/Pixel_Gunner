#pragma once
class Grenade : public Object
{
	Sprite* m_Grenade;
	float DelayTime;
	Vec2 Mouse, Dire;
	bool Reload_Please, RDown;
public:
	Grenade();
	~Grenade();

	void GrenadeRotato();
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

