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

	// ������, W, S, A, D,  
	Sprite* KeyChange;


	// �̴ϸ� ǥ�� : �׻�, ���� �� ����, ��� �� �� 
	Sprite* MineMap;
	
	// ȭ��ǥ
	Sprite* Arrow_Button[4];

	// ����
	Sprite* Gamma;

	//Ǯ��ũ��
	Sprite* FullScreen;

	// üũ�ڽ�
	Sprite* CheckBox[10];

	// �̸� : Ŀ��, �̴ϸ�, 
	Sprite* m_Name[10];

	// ���, �ʱ�ȭ, Ȯ�� ��ư
	Sprite* Choice_Button[3];

	int Line;
	bool ColBox;
	int m_Type;
	int Minemap_Option;
public:
	Detail_Option(int type);
	~Detail_Option();

	void Order();
	void Name();
	void Shape();
	void Direction();


	void Reset();

	void Update(float deltaTime, float Time);
	void Render();

};

