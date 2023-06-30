#include "Game.h"
#include <random>

Game::Game(Difficulty difficulty) :_pView(new View(*this))
{
	SetDifficulty(difficulty);
}

Game::~Game()
{
}


void Game::Show()
{
	_pView->ShowGame();
}

void Game::SetDifficulty(Difficulty newDifficulty)
{
	_Difficulty = newDifficulty;
	switch (newDifficulty)
	{
	case easy:
		for (int i = 0; i < GroupsNum; ++i)
		{
			for (int j = 0; j < CardValueNum; ++j)
			{
				_Cards[i * CardValueNum + j] = Card((CardValue)j, CardType::Spade);
			}
		}
		break;
	case normal:
		for (int i = 0; i < GroupsNum; ++i)
		{
			for (int j = 0; j < CardValueNum; ++j)
			{
				_Cards[i * CardValueNum + j] = Card((CardValue)j, j % 2 ? CardType::Heart : CardType::Spade);
			}
		}
		break;
	case hard:
		for (int i = 0; i < GroupsNum; ++i)
		{
			for (int j = 0, k = 0; j < CardValueNum; ++j, k = (k + 1) % 4)
			{
				_Cards[i * CardValueNum + j] = Card((CardValue)j, (CardType)k);
			}
		}
		break;
	default:
		break;
	}
}


void Game::Shuffle()
{
 	static std::random_device rd;
	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform_dist(0, _Cards.size() - 1);
	for (int i = 0; i < _Cards.size(); ++i)
	{
		std::swap(_Cards[i], _Cards[uniform_dist(e1)]);
	}
}

void Game::InitScenes()
{
	ReservedCount = ReservedQuantity;
	SuccessCount = 0;
	IsVictory = false;
	for (int i = 0; i < Scenes.size(); ++i)
		Scenes[i].Clear();

	for (int i = ReservedQuantity * Scenes.size(), j = 0; i < _Cards.size(); ++i, j = (j+1) % Scenes.size())
		Scenes[j].Push(_Cards[i]);
	
	for (int i = 0; i < Scenes.size(); ++i)
		Scenes[i].SetHideLevel(Scenes[i].Count() - 1);
	
	PSelected.SetValue(-1, -1);
	PCurrent.SetValue(0, Scenes[0].Count() - 1);
}

void Game::StartNewGame()
{
	Shuffle();
	InitScenes();
}

void Game::Deal()
{
	if (ReservedCount < 1)
		return;

	// ��֮ǰѡ�е�ȡ����
	PSelected.SetValue(-1, -1);

	// Ϊÿһ���۷�һ����
	for (int i = 0; i < Scenes.size(); ++i)
	{
		Scenes[i].Push(_Cards[(ReservedCount-1) * Scenes.size() + i]);
	}
	// ������һ
	ReservedCount--;
}

void Game::CurMove(Dir dir)
{
	int width = Scenes.size();
	int height = Scenes[PCurrent.x].Count();
	switch (dir)
	{
	case left:
		if (PCurrent.x == 0)
			PCurrent.x = width -1;
		else
			PCurrent.x--;
		break;
	case up:
		if (height == 0)
			PCurrent.y = 0;
		else if (PCurrent.y == 0)
			PCurrent.y = height - 1;
		else
			PCurrent.y--;
		break;
	case right:
		if (PCurrent.x == width - 1)
			PCurrent.x = 0;
		else
			PCurrent.x++;
		break;
	case down:
		if (height == 0)
			PCurrent.y = 0;
		else if (PCurrent.y == height - 1)
			PCurrent.y = 0;
		else
			PCurrent.y++;
		break;
	default:
		break;
	}

	// ���������һ��û�κ���  ָ���
	if (Scenes[PCurrent.x].Count() == 0)
		PCurrent.y = 0;
	// ����������߶ȸ��ڵ�ǰ�߶�
	//     ����֮ǰ�ĸ߶���0
	//     ����֮ǰ����һ�еĶ���ʱ
	//  �����ָ��ǰ�еĶ���
	else if (PCurrent.y >= Scenes[PCurrent.x].Count()
		|| height == 0
		|| PCurrent.y == height - 1)
		PCurrent.y = Scenes[PCurrent.x].Count() - 1;
}

bool Game::Select()
{
	if (PCurrent.x < 0 || PCurrent.x >= Scenes.size())
		return false;

	if (Scenes[PCurrent.x].Count() == 0 && PCurrent.y != 0)
		return false;
	
	// ���ѡ��֮ǰѡ�ģ���ȡ��ѡ��
	if (PSelected == PCurrent)
	{
		PSelected.SetValue(-1, -1);
		return true;
	}

	// ���֮ǰδѡ���κζ���
	if (PSelected.x == -1)
	{
		// �жϵ�ǰѡ������ɲ�����ѡ
		if (CheckIsOptional(PCurrent))
		{
			// �������ѡ��ѡ�����λ�ã�����true
			PSelected = PCurrent;
			return true;
		}
		else
		{
			return false;
		}
	}
	// ����˵��֮ǰѡ���˶����������ƶ�
	else
	{
		// �����ѡ�ĺ�֮ǰѡ����ͬһ�� ���� ѡ���ǲ����м����
		if (PCurrent.x == PSelected.x || PCurrent.y != Scenes[PCurrent.x].Count() - 1)
		{
			// �����һ��ɶ��û��
			if (Scenes[PCurrent.x].Count() == 0)
			{
				// ֱ���ƶ���ȥ
				MoveCards(PSelected, PCurrent.x); 
				PSelected.SetValue(-1, -1);
				return true;
			}
			if (CheckIsOptional(PCurrent))
			{
				PSelected = PCurrent;
				return true;
			}
			else
			{
				return false;
			}
		}
		// ����˵��ѡ���������е����һ��
		else
		{
			// ��������ƶ���ȥ
			if (CheckIsOrderly(
				Scenes[PCurrent.x].GetCards().at(PCurrent.y),
				Scenes[PSelected.x].GetCards().at(PSelected.y),
				_Difficulty))
			{
				// ֱ���ƶ���ȥ
				MoveCards(PSelected, PCurrent.x);
				PSelected.SetValue(-1, -1);
				return true;
			}
			// ����ѡ����һ����
			else
			{
				PSelected = PCurrent;
				return true;
			}
		}
	}
}

void Game::MoveCards(Point point, int SlotsIndex)
{
	// ��ָ��λ�õ����ƶ�����Ӧ�Ĳ���
	Scenes[point.x].MoveCardsTo(Scenes[SlotsIndex], point.y);

	// ����Ƿ����
	if (CheckIsSuccess(SlotsIndex))
	{
		// ������һ�飬�򵯳���һ����
		Scenes[SlotsIndex].Pop(CardValueNum);
		// Ȼ����ɼ�������
		SuccessCount++;

		if (SuccessCount == GroupsNum)
			IsVictory = true;
	}
}


bool Game::CheckIsOptional(Point point)
{
	// �����һ��ɶ��û��
	if (Scenes[point.x].Count() == 0)
		return false;

	if (point.y < Scenes[point.x].GetHideLevel())
		return false;

	if (point.y == Scenes[point.x].Count() - 1)
		return true;

	
	for (int i = point.y; i < Scenes[point.x].Count() - 1; ++i)
	{
		// ����Ƿ�����ֻҪ��һ���Ǵ���ģ���ֱ���޷�ѡ��
		if (!CheckIsOrderly(Scenes[point.x].GetCards().at(i), Scenes[point.x].GetCards().at(i + 1), _Difficulty))
		{
			return false;
		}
	}

	return true;
}

bool Game::CheckIsOrderly(Card cur, Card next, Difficulty difficulty)
{
	if (cur.GetValue() != next.GetValue() + 1)
		return false;

	// �����Ѷȼ�黨ɫ
	switch (difficulty)
	{
	// ���ѶȲ�����ɫ
	case easy:
		return true;

	// ��ͨ�Ѷ�Ҫ���Ƿ�ں����
	case normal:
		return cur.GetType() == CardType::Spade && next.GetType() == CardType::Heart
			|| cur.GetType() == CardType::Heart && next.GetType() == CardType::Spade;
	
	// �����Ѷ�Ҫ���Ƿ��պ��ҡ����ҡ�÷���������˳����
	case hard:
		return cur.GetType() == CardType::Spade		&& next.GetType() == CardType::Heart
			|| cur.GetType() == CardType::Heart		&& next.GetType() == CardType::Club
			|| cur.GetType() == CardType::Club		&& next.GetType() == CardType::Diamond
			|| cur.GetType() == CardType::Diamond	&& next.GetType() == CardType::Spade;
	default:
		break;
	}
	return false;
}

// �����һ�����Ƿ����
bool Game::CheckIsSuccess(int SlotsIndex)
{
	// ���ж�����۵������㲻�㹻���һ����
	if (Scenes[SlotsIndex].Count() < CardValueNum)
		return false;

	// �����ʾ�����������������һ���ƣ�ֱ�ӷ���
	if (Scenes[SlotsIndex].Count() - Scenes[SlotsIndex].GetHideLevel() < CardValueNum)
		return false;

	std::vector<Card> Cards = Scenes[SlotsIndex].GetCards();
	// Ȼ���ж��������������ǲ���A���������ֱ�ӷ���
	if (Cards.back().GetValue() != CardValue::_A)
		return false;

	// Ȼ���鵹��һ����������λ�ÿ�ʼ�Ƿ�����ֱ�ӷ��ؼ����
	return CheckIsOptional(Point(SlotsIndex, Cards.size() - CardValueNum));
}
