#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//菜单
void menu()
{
	printf("######################\n");
	printf("####    1.play    ####\n");
	printf("####    0.exit    ####\n");
	printf("######################\n");
	printf("请做出选择:<");
}



//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印表格
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
					printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}


//玩家行动
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家回合\n");
	while (1)
	{
		printf("请输入坐标:<");
		scanf("%d%d", &x, &y);//输入坐标
		if (x >= 1 && x <= col && y>= 1 && y <= row)//判断坐标合法性
		{
			if (board[x - 1][y - 1]==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入!\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
}


//电脑行动
void ComputerMove(char board[ROW][COL],int row,int col)
{
	printf("电脑回合/n");
	int x = rand() % 3;
	int y = rand() % 3;
	while (1)
	{
			if (board[x][y]== ' ')
			{
				board[x][y] = '#';
				break;
			}
	}
}


//判断胜利
char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (board[i][j] != ' ')
				printf("平局\n");
	}

}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i = 0; i < col; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=" ")
	{ 
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")
	{
		return board[0][2];
	}
	char ret = IsFull(board, row, col);
	if (ret = 'Q')
	{
		printf("平局\n");
	}
}
