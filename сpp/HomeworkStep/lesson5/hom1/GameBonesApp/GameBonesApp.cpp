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
void who_win(int pc_bone, int user_bone)
{
	
	if (pc_bone == user_bone)
	{
		cout << "\n  Draw\n\n";
	}
	else if (pc_bone > user_bone)
	{
		cout << "\n  PC win\n\n";
	}
	else
	{
		cout << "\n  You win\n\n";
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
	int pc_sum = 0;
	int user_sum = 0;
	cout << "Hello! Its a bones game! U wanna go first or second?(enter 1 or 2)\n";
	int whoFirst = input_int();
	while (whoFirst != 1 && whoFirst != 2)
	{
		cout << "Wrong input, enter 1 or 2 pls." << endl;
		whoFirst = input_int();
	}
	cout << endl;
	if (whoFirst == 1)
	{
		while (game != 0)
		{
			cout << "Your bone" << endl;
			user_bone = bone_create();
			user_sum += user_bone;
			bone_show(user_bone);
			cout << endl;
			cout << "PC bone" << endl;
			pc_bone = bone_create();
			bone_show(pc_bone);
			pc_sum += pc_bone;
			who_win(pc_bone, user_bone);
			Sleep(2000);
			game--;
		}
	}
	else
	{
		while (game != 0)
		{
			cout << "PC bone" << endl;
			pc_bone = bone_create();
			pc_sum += pc_bone;
			bone_show(pc_bone);
			cout << endl;
			cout << "Your bone" << endl;
			user_bone = bone_create();
			user_sum += user_bone;
			bone_show(user_bone);
			who_win(pc_bone, user_bone);
			Sleep(2000);
			game--;
		}
	}

	if (user_sum == pc_sum)
	{
		cout << "Your points " << user_sum << " \n" << "Pc points " << pc_sum << "\n\n Draw!\n\n";
		cout << "Average value of points per game: \n";
		cout << "Pc = " << (float)pc_sum / 5 << endl;
		cout << "User = " << (float)user_sum / 5 << endl;
	}
	else if (user_sum > pc_sum)
	{
		cout << "Your points " << user_sum << " \n" << "Pc points " << pc_sum << "\n\n You won match!\n\n";
		cout << "Average value of points per game: \n";
		cout << "Pc = " << (float)pc_sum / 5 << endl;
		cout << "User = " << (float)user_sum / 5 << endl;
	}
	else
	{
		cout << "Your points " << user_sum << " \n" << "Pc points " << pc_sum << "\n\n PC won match!\n\n";
		cout << "Average value of points per game: \n";
		cout << "Pc = " << (float)pc_sum / 5 << endl;
		cout << "User = " << (float)user_sum / 5 << endl;
	}
}
