#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char board[ROW][COL];//创建棋盘
	InitBoard(board, ROW,COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘

	//开始游戏
	char ret = 0;
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家行动
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;

		ComputerMove(board, ROW, COL);//电脑行动
		IsWin(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW,COL);
		if (ret != 'c')
			break;
	}

		DisplayBoard(board, ROW, COL);
	if (ret = '*')
	{
		printf("你赢了\n");
	}
	else if (ret = '#')
	{
		printf("你输了\n");
	}
	else 
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
	return 0;
}


