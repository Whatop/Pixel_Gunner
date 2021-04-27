#pragma once
class MainScene : public Scene
{
	Sprite* BackGround;

	Sprite* m_Button[4];

	Sprite* Difficulty;

	int Line;
	bool ColBox;
	float ButtonDelay;
public:
	MainScene();
	~MainScene();

	void Button();
	void Reset();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

