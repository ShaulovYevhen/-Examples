//Игра «кубики».
//Условие: имеется два игральных кубика
//со значениями от 1 до 6.
//Игра происходит с компьютером, кубики бросаются поочередно.
//Побеждает тот, у кого сумма выпавших очков по итогам пяти бросков больше.
//Предусмотрите возможность получения первого хода человеком или компьютером.
//Кубики отображаются с помощью символов.
//В конце игры необходимо выводить среднюю сумму по броскам для обоих участников.

#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace  std;

int bone_create()
{
	int bone = rand() % 6 + 1; 
	return bone;
}

void bone_show(int bone) //вывод кубика на экран
{
	switch (bone)
	{
	case 1:
		cout << "|---|\n|   |\n| * |\n|   |\n|---|\n";
		break;
	case 2:
		cout << "|---|\n|*  |\n|   |\n|  *|\n|---|\n";
		break;
	case 3:
		cout << "|---|\n|*  |\n| * |\n|  *|\n|---|\n";
		break;
	case 4:
		cout << "|---|\n|* *|\n|   |\n|* *|\n|---|\n";
		break;
	case 5:
		cout << "|---|\n|* *|\n| * |\n|* *|\n|---|\n";
		break;
	case 6:
		cout << "|---|\n|* *|\n|* *|\n|* *|\n|---|\n";
		break;
	}
}

int input_int()
{
	int i;
	cin >> i;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wrong input, enter digit pls." << endl;
		cin >> i;
	}
	return i;
}

int main()
{
	srand(time(NULL));
	int pc_bone; //переменная для кости ПК
	int user_bone;//переменная для кости игрока
	int game = 5;
	int pc_win = 0; //кол-во побeд ПК
	int user_win = 0; //кол-во побед пользователя
	cout << "Hello! Its a bones game! U wanna go first or second?(enter 1 or 2)\n";
	int whoFirst = input_int();
	while (whoFirst != 1 && whoFirst != 2)
	{
		cout << "Wrong input, enter 1 or 2 pls." << endl;
		whoFirst = input_int();
	}
	while (game != 0)
	{
		cout << endl;
		if (whoFirst = 1)
		{
			cout << "Your bone" << endl;
			user_bone = bone_create();
			bone_show(user_bone);
			cout << endl;
			cout << "PC bone" << endl;
			pc_bone = bone_create();
			bone_show(pc_bone);
			if (pc_bone == user_bone)
			{
				cout << "Draw\n";
			}
			else if (pc_bone > user_bone)
			{
				cout << "PC win\n";
				pc_win++;
			}
			else
			{
				cout << "You win\n";
				user_win++;
			}
			Sleep(2000);
		}
		else
		{
			cout << "PC bone" << endl;
			pc_bone = bone_create();
			bone_show(pc_bone);
			cout << endl;
			cout << "Your bone" << endl;
			user_bone = bone_create();
			bone_show(user_bone);
			if (pc_bone == user_bone)
			{
				cout << "Draw\n";
			}
			else if (pc_bone > user_bone)
			{
				cout << "PC win\n";
				pc_win++;
			}
			else
			{
				cout << "You win\n";
				user_win++;
			}
			Sleep(2000);
		}
		game--;
	}
	
	if (user_win == pc_win)
	{
		cout << "Draw!\n";
	}
	else if (user_win > pc_win)
	{
		cout << "You won match!\n";
	}
	else
	{
		cout << "PC won match!\n";
	}
}
