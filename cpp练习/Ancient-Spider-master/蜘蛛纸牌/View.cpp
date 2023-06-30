#include "View.h"
#include <iostream>

const char *CardTypeView[] = {
	"����",
	"����",
	"÷��",
	"����",
};

const char *CardValueView[] = {
	" A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K"
};


View::~View()
{
}

void View::ShowCard(bool isNull)
{
	std::cout << (isNull ? "      " : "XXXXXX");
}
void View::ShowCard(Card card)
{
	std::cout << CardTypeView[card.GetType()] << CardValueView[card.GetValue()];
}

void View::ShowGame()
{
	bool flag = true;
	char lc = '[', rc = ']';
	for (int level = 0; flag; ++level)
	{
		flag = false;
		for (int i = 0; i < _Game.Scenes.size(); ++i)
		{
			if (_Game.PSelected.y == level && _Game.PSelected.x == i)
				lc = rc = '*';
			else if (_Game.PCurrent.y == level && _Game.PCurrent.x == i)
				lc = '>', rc = '<';
			else
				lc = '[', rc = ']';

			// ����ǻ�û�����Ĳ�
			if (level < _Game.Scenes[i].GetHideLevel())
			{
				std::cout << lc;
				ShowCard(false);
				std::cout << rc;
				flag = true;
			}
			// ������������Ƶ�
			else if (level < _Game.Scenes[i].Count())
			{
				std::cout << lc;
				ShowCard(_Game.Scenes[i].GetCards()[level]);
				std::cout << rc;
				flag = true;
			}
			// ��������ǿյĲ�
			else if (level == 0 && _Game.Scenes[i].Count() == 0)
			{
				// ����������������ϣ����ֹ��
				if (_Game.PCurrent.y == level && _Game.PCurrent.x == i)
					lc = '>', rc = '<';
				else
					lc = ' ', rc = ' ';
				std::cout << lc;
				ShowCard(true);
				std::cout << rc;
			}
			// ������ȫ�������
			else
			{
				std::cout << ' ';
				ShowCard(true);
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

	std::cout << "\n\n\n��ǰ�Ѿ���ɣ�" << _Game.SuccessCount << "��\tʣ�෢�ƴ�����" << _Game.ReservedCount << "��" << std::endl;
}
