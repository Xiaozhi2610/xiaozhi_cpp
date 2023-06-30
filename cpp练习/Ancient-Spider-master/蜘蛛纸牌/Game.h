#pragma once
#include <vector>
#include <array>
#include "Card.h"
#include "View.h"
#include "CardsSlots.h"

// �Ѷ�
enum Difficulty
{
	// ��
	easy,
	// ��ͨ
	normal,
	// ����
	hard,
};

// �Ʋ�����
const int SlotsNum  = 10;

// ��������
const int GroupsNum = 8;

// Ԥ����  Ԥ������������ = Ԥ���� * ������ = 5 * 10 = 50 ���Է����
const int ReservedQuantity = 5;

struct Point {
	int x, y;

	Point() 
		:x(0), y(0) 
	{}

	Point(int a, int b)
		:x(a), y(b)
	{}

	void SetValue(int a, int b)
	{
		x = a, y = b;
	}

	bool operator == (const Point p) const 
	{
		return x == p.x && y == p.y;
	}
};

enum Dir {
	left,
	up,
	right,
	down
};

class View;
class Game
{
private:
	// ������Ϸ��������
	std::array<Card, GroupsNum * CardValueNum> _Cards;

	// ��Ϸ�Ѷ�
	Difficulty _Difficulty;

	View *_pView;

	std::array<CardsSlots, SlotsNum> Scenes;

	// Ԥ�����ƵĴ���
	int ReservedCount;

	// �ɹ������ϵļ�����
	int SuccessCount;

	Point PSelected;
	Point PCurrent;

	bool IsVictory;
public:
	friend class View;

	Game(Difficulty difficulty = Difficulty::easy);
	~Game();

	void Show();

	void SetDifficulty(Difficulty newDifficulty);
	Difficulty GetDifficulty() const { return _Difficulty; }

	bool GetIsVictory() const { return IsVictory; }

	// ϴ��
	void Shuffle();

	// ��ʼ������
	void InitScenes();

	// ��ʼһ������Ϸ
	void StartNewGame();

	// ���ƣ�Ԥ�����ƴ����㹻������²Żᷢ�ɹ���
	void Deal();

public:
	// ����ƶ�
	void CurMove(Dir dir);

	// ѡ��ǰ���ָ�����  �����Ƿ�ѡ��ɹ�
	bool Select();

private:
	void MoveCards(Point point, int SlotsIndex);

	bool CheckIsOptional(Point point);

	bool CheckIsOrderly(Card cur, Card next, Difficulty difficulty);

	bool CheckIsSuccess(int SlotsIndex);
};

