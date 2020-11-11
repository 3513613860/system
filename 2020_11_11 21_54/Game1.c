#include "game1_guess.h"

void Menu()
{
	printf("#######################################\n");
	printf("###########    1.猜数字    ############\n");
	printf("###########    2.三子棋    ############\n");
	printf("###########    3.扫雷      ############\n");
	printf("###########    4.退出      ############\n");
	printf("#######################################\n");
	printf("please select#:");
}
void Menu1()
{
	printf("#######################################\n");
	printf("######      1 Play     2 Exit    ######\n");
	printf("#######################################\n");
	printf("please select#:");
}

void Game1()
{
	srand((unsigned long)time(NULL));
	int n = rand() % 100 + 1;
	int m = 0;
	while (1)
	{
		printf("\n请输入你猜测的数字：");
		scanf_s("%d", &m);
		printf("\n");
		if (m < n)
		{
			printf("你猜测的数字太小了\n");
		}
		else if (m > n)
		{
			printf("你猜测的数字太大了\n");
		}
		else
		{
			printf("恭喜你，猜中了\n");
			return;
		}
	}
}

void Game1_guess()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu1();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			Game1();
			printf("你要不要再来一把\n");
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("输入有误\n");
			break;
		}
	}
	printf("byebye\n");
	return 0;
}