#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�˵�
void menu();



//��������
#define ROW
#define COL 3


//����������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char boardC,int row,int col);
//����ж�

void PlayerMove(char board[ROW][COL], int row, int col);
//�����ж�
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж�ʤ��
char IsWin(char board[ROW][COL], int row, int col);
