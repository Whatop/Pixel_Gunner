#pragma once
class Option : public Object //Ű �ٲٴ� ��, ����, â ũ��, UI ũ��, ���콺 ��� �� ����
{
private:
	Sprite* m_BG;

	//���� ������ 
	Sprite* Control[2];

	//���� �÷���, ��Ʈ��, ����, ����� ����
	Sprite* Button[4];

	bool ColBox;
	float Delay;
	int Line;
	//Sprite* m_
	
public:
	Option();
	~Option();

	void Order();
	void Init();
	void Update(float deltaTime, float Time);
	void Render();

};

