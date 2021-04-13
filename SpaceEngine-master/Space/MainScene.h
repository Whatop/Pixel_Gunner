#pragma once
class MainScene : public Scene
{
	Sprite* BackGround;
	Sprite* Start;
	Sprite* Option;
	Sprite* Exit;

	Sprite* Rank;
public:
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

