#pragma once
class Melee : public Object
{
	Sprite* m_Melee;
	float DelayTime;
	float RDown;
	float Reload_Please;
	Vec2 Mouse, Dire;
public:
	Melee(Vec2 Pos);
	~Melee();

	void MeleeRotato();
	
	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

