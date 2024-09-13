#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//菜单
void menu();



//定义行列
#define ROW
#define COL 3


//函数的声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char boardC,int row,int col);
//玩家行动

void PlayerMove(char board[ROW][COL], int row, int col);
//电脑行动
void ComputerMove(char board[ROW][COL], int row, int col);
//判断胜利
char IsWin(char board[ROW][COL], int row, int col);
