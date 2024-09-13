#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//�˵�
void menu()
{
	printf("######################\n");
	printf("####    1.play    ####\n");
	printf("####    0.exit    ####\n");
	printf("######################\n");
	printf("������ѡ��:<");
}



//��ʼ������
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

//��ӡ���
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


//����ж�
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��һغ�\n");
	while (1)
	{
		printf("����������:<");
		scanf("%d%d", &x, &y);//��������
		if (x >= 1 && x <= col && y>= 1 && y <= row)//�ж�����Ϸ���
		{
			if (board[x - 1][y - 1]==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������!\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}


//�����ж�
void ComputerMove(char board[ROW][COL],int row,int col)
{
	printf("���Իغ�/n");
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


//�ж�ʤ��
char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (board[i][j] != ' ')
				printf("ƽ��\n");
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
		printf("ƽ��\n");
	}
}
