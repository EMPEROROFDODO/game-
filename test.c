#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char board[ROW][COL];//��������
	InitBoard(board, ROW,COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����

	//��ʼ��Ϸ
	char ret = 0;
	while (1)
	{
		PlayerMove(board, ROW, COL);//����ж�
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;

		ComputerMove(board, ROW, COL);//�����ж�
		IsWin(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW,COL);
		if (ret != 'c')
			break;
	}

		DisplayBoard(board, ROW, COL);
	if (ret = '*')
	{
		printf("��Ӯ��\n");
	}
	else if (ret = '#')
	{
		printf("������\n");
	}
	else 
	{
		printf("ƽ��\n");
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
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
	return 0;
}


