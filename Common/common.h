//
// Created by Administrator on 2019-12-04.
//

#ifndef CANDC___COMMON_H
#define CANDC___COMMON_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define  FrameX 13
#define  FrameY  3
#define  Frame_height  20
#define  Frame_width  18

int i,j,Temp,Temp1,Temp2;
int a[80][80];
int b[4];

struct Tetris{
    int x;
    int y;
    int flag;
    int next;
    int speed;
    int number;
    int score;
    int level;
};
HANDLE  hOut;

int  SetFontColor(int color);
int  SetCursorPosition(int x,int y);
void MakeTetris(struct Tetris *tetris);
void PrintTetris(struct Tetris *tetris);
int ifMove(struct Tetris *tetris);
void CleanTetris(struct Tetris *tetris);
void Flag(struct Tetris *tetris);
void Del_Fullline(struct Tetris *tetris);
void Replay();
void Gameplay();



#endif //CANDC___COMMON_H
