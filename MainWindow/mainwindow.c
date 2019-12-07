//
// Created by Administrator on 2019-12-07.
//
#include "mainwindow.h"

void DrawGameFrame()
{
    SetCursorPosition(FrameX+Frame_width-7,FrameY-2);   	//打印游戏名称
    SetFontColor(11);
    printf("沙雕俄罗斯方块");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+7);  	//打印选择菜单
    SetFontColor(2);
    printf("**********");
    SetCursorPosition(FrameX+2*Frame_width+13,FrameY+7);  	//打印选择菜单
    SetFontColor(3);
    printf("下一出现方块：");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+13);
    SetFontColor(2);
    printf("**********");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+17);
    SetFontColor(14);
    printf("↑键：旋转");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+19);
    printf("空格：暂停游戏");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+15);
    printf("Esc ：退出游戏");
    SetCursorPosition(FrameX,FrameY);
    SetFontColor(12);
    printf("╔");							//打印框角
    SetCursorPosition(FrameX+2*Frame_width-2,FrameY);
    printf("╗");
    SetCursorPosition(FrameX,FrameY+Frame_height);
    printf("╚");
    SetCursorPosition(FrameX+2*Frame_width-2,FrameY+Frame_height);
    printf("╝");
    a[FrameX][FrameY+Frame_height]=2;       //记住该处已有图案
    a[FrameX+2*Frame_width-2][FrameY+Frame_height]=2;
    for(i=2;i<2*Frame_width-2;i+=2)
    {
        SetCursorPosition(FrameX+i,FrameY);
        printf("═");         //打印上横框
    }
    for(i=2;i<2*Frame_width-2;i+=2)
    {
        SetCursorPosition(FrameX+i,FrameY+Frame_height);
        printf("═");         //打印下横框
        a[FrameX+i][FrameY+Frame_height]=2;    //记住下横框有图案
    }
    for(i=1;i<Frame_height;i++)
    {
        SetCursorPosition(FrameX,FrameY+i);
        printf("║");         //打印左竖框
        a[FrameX][FrameY+i]=2;       //记住左竖框有图案
    }
    for(i=1;i<Frame_height;i++)
    {
        SetCursorPosition(FrameX+2*Frame_width-2,FrameY+i);
        printf("║");         //打印右竖框
        a[FrameX+2*Frame_width-2][FrameY+i]=2;   //记住右竖框有图案
    }
}

