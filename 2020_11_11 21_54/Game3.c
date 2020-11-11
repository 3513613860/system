#include "game3_mine.h"

void Menu3()
{
	printf("###############################\n");
	printf("### 1 PLAY ######### 2 EXIT ###\n");
	printf("###############################\n");
	printf("请输入你的选项：");
}


void show_board(char board[][12], int row, int col)
{
	printf("\n      1   2   3   4   5   6   7   8   9   10\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf(" %2d ", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		printf("     ----------------------------------------");
		printf("\n");
	}
}

void set_mine(char mine_board[][12], int row, int col)
{
	int i = 0;
	while (i < 20)
	{
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		if (mine_board[x][y] == '0')
		{
			mine_board[x][y] = '1';
			i++;
		}
	}
}

int get_mines(char mine_board[][12], int row, int col, int x, int y)
{
	return mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + \
		mine_board[x][y - 1] + mine_board[x][y + 1] + \
		mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 8 * '0';
}
void move(char my_board[][12], char mine_board[][12], int row, int col)
{
	int count = 80;
	int x = 0;
	int y = 0;
	do {
		show_board(my_board, ROW, COL);
		printf("请输入坐标：");
		scanf_s("%d%d", &x, &y);
		if (x < 1 || x > 10 || y < 1 || y > 10)
		{
			printf("输入坐标错误");
			continue;
		}
		if (my_board[x][y] != '*')
		{
			printf("输入坐标重复");
			continue;
		}
		if (mine_board[x][y] == '1')
		{
			break;
		}
		int num = get_mines(mine_board, ROW, COL, x, y);
		my_board[x][y] = num + '0';
		count--;
	} while (count > 0);
	if (count > 0)
	{
		printf("你被炸死了！\n");
	}
	else
	{
		printf("你赢了！\n");
	}
	printf("下面是雷区的排布！\n");
	show_board(mine_board, ROW, COL);
}

void Game3()
{
	srand((unsigned long)time(NULL));

	char my_board[ROW][COL];
	char mine_board[ROW][COL];

	memset(my_board, '*', sizeof(my_board));
	memset(mine_board, '0', sizeof(mine_board));
	set_mine(mine_board, ROW, COL);
	move(my_board, mine_board, ROW, COL);
}

void Game3_mine()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu3();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			Game3();
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
}