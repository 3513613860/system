#include "game1_guess.h"

void Menu()
{
	printf("#######################################\n");
	printf("###########    1.������    ############\n");
	printf("###########    2.������    ############\n");
	printf("###########    3.ɨ��      ############\n");
	printf("###########    4.�˳�      ############\n");
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
		printf("\n��������²�����֣�");
		scanf_s("%d", &m);
		printf("\n");
		if (m < n)
		{
			printf("��²������̫С��\n");
		}
		else if (m > n)
		{
			printf("��²������̫����\n");
		}
		else
		{
			printf("��ϲ�㣬������\n");
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
			printf("��Ҫ��Ҫ����һ��\n");
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("��������\n");
			break;
		}
	}
	printf("byebye\n");
	return 0;
}