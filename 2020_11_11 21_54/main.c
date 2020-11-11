#include "game1_guess.h"
#include "game2_chess.h"
#include "game3_mine.h"

int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			Game1_guess();
			break;
		case 2:
			Game2_chess();
			break;
		case 3:
			Game3_mine();
			break;
		case 4:
			quit = 1;
			break;
		default:
			printf(" ‰»Î”–ŒÛ\n");
			break;
		}
	}
	printf("byebye\n");
	return 0;
}