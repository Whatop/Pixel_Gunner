#pragma once
class Option : public Object //Ű �ٲٴ� ��, ����, â ũ��, UI ũ��, ���콺 ��� �� ����
{
private:
	Sprite* m_BG;

	Sprite* Button[2];
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



	//Sprite* m_

public:
	Option();
	~Option();

	void Update(float deltaTime, float Time);
	void Render();

};

