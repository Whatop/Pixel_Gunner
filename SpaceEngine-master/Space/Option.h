#pragma once
class Option : public Object //Ű �ٲٴ� ��, ����, â ũ��, UI ũ��, ���콺 ��� �� ����
{
private:
	Sprite* m_BG;

	//���� ������ 
	Sprite* Control[2];

	//���� �÷���, ��Ʈ��, ����, ����� ����
	Sprite* Button[4];

	//��������
	Sprite* Sound;

	//���콺 ���
	Sprite* Mouse_Shape;

	//â ũ��
	Sprite* Window;

	//���콺 ��
	Sprite* MouseColor;

	// ������, W, S, A, D,  
	Sprite* KeyChange;

	// ���, �ʱ�ȭ, Ȯ�� ��ư
	Sprite* Choice_Button[3];

	bool ColBox;
	float Delay;
	//Sprite* m_
	
public:
	Option();
	~Option();

	void Init();
	void Update(float deltaTime, float Time);
	void Render();

};

