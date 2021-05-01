#pragma once

#define _Start		1
#define _Control	2
#define _Vidio		3
#define _Audio		4


class Detail_Option : public Object //Ű �ٲٴ� ��, ����, â ũ��, UI ũ��, ���콺 ��� �� ����
{
private:
	Sprite* m_BG;
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

	Sprite* Arrow_Button[2];

	int Line;
	bool ColBox;
public:
	Detail_Option(int type);
	~Detail_Option();

	void Order();
	void Shape();
	void Direction();
	void Init();
	void Update(float deltaTime, float Time);
	void Render();

};

