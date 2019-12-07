//
// Created by Administrator on 2019-12-05.
//

#include "welcom.h"
#include "../MainWindow/mainwindow.h"
int Title(){
    SetFontColor(15);
    SetCursorPosition(24,3);
    printf("逗  比  俄  罗  斯  方  块\n");

    SetFontColor(11);
    SetCursorPosition(18,5);
    printf("■");
    SetCursorPosition(18,6);
    printf("■■");
    SetCursorPosition(18,7);
    printf("■");

    SetFontColor(14);
    SetCursorPosition(26,6);
    printf("■■");
    SetCursorPosition(28,7);
    printf("■■");

    SetFontColor(10);
    SetCursorPosition(36,6);
    printf("■■");
    SetCursorPosition(36,7);
    printf("■■");

    SetFontColor(13);
    SetCursorPosition(45,5);
    printf("■");
    SetCursorPosition(45,6);
    printf("■");
    SetCursorPosition(45,7);
    printf("■");
    SetCursorPosition(45,8);
    printf("■");

    SetFontColor(12);
    SetCursorPosition(56,6);
    printf("■");
    SetCursorPosition(52,7);
    printf("■■■");

    return 0;
}

void Flower(){
    SetFontColor(12);
    SetCursorPosition(66,11);
    printf("(_)");

    SetCursorPosition(64,12);
    printf("(_)");

    SetCursorPosition(68,12);
    printf("(_)");

    SetCursorPosition(66,13);
    printf("(_)");

    SetFontColor(6);
    SetCursorPosition(67,12);
    printf("@");

    SetFontColor(13);
    SetCursorPosition(72,10);
    printf("(_)");

    SetCursorPosition(76,10);
    printf("(_)");

    SetCursorPosition(74,9);
    printf("(_)");

    SetCursorPosition(74,11);
    printf("(_)");

    SetFontColor(6);
    SetCursorPosition(75,10);
    printf("@");

    SetCursorPosition(71,12);
    printf("|");

    SetCursorPosition(72,11);
    printf("/");

    SetCursorPosition(70,13);
    printf("\\|");

    SetCursorPosition(70,14);
    printf("`|/");

    SetCursorPosition(70,15);
    printf("\\|");

    SetCursorPosition(71,16);
    printf("| /");

    SetCursorPosition(71,17);
    printf("|");

    SetFontColor(10);
    SetCursorPosition(67,17);
    printf("\\\\\\\\");

    SetCursorPosition(73,17);
    printf("//");

    SetFontColor(2);
    SetCursorPosition(67,18);
    printf("^^^^^^^^");

    SetFontColor(5);
    SetCursorPosition(65,19);
    printf("逗 比 科 技");

    SetCursorPosition(68,20);
    printf("刘振君");
}

void Menu(){
    int x = 0,y=0;
    int input_num = 0;
    SetFontColor(14);
    for (x=15;x<=60;x++){
        for (y=9;y<=20;y++){
            SetCursorPosition(x,y);
            if(y == 9|| y == 20){
                printf("=");
            }
            else if(x == 15 || x ==59){
                printf("||");
            }
        }
    }

    SetFontColor(12);
    SetCursorPosition(25,12);
    printf("1.开始游戏");

    SetCursorPosition(40,12);
    printf("2.按键说明");

    SetCursorPosition(25,17);
    printf("3.游戏规则");

    SetCursorPosition(40,17);
    printf("4.退出");

    SetFontColor(3);
    SetCursorPosition(21,22);
    printf("请选择[1 2 3 4]:[ ]\b\b");

    SetFontColor(14);
    scanf("%d",&input_num);
    switch(input_num){
        case 1:
            system("cls");
            DrawGameFrame();
            Gameplay();
            break;
        case 2:
            explation();
            break;
        case 3:
            regulation();
            break;
        case 4:
            close();
            break;
        default:
            break;
    }
}

void explation()
{
    int i,j = 1;
    system("cls");
    SetFontColor(13);
    SetCursorPosition(32,3);
    printf("按键说明");
    SetFontColor(2);
    for (i = 6; i <= 16; i++)   //输出上下边框===
    {
        for (j = 15; j <= 60; j++)  //输出左右边框||
        {
            SetCursorPosition(j, i);
            if (i == 6 || i == 16) printf("=");
            else if (j == 15 || j == 59) printf("||");
        }
    }
    SetFontColor(3);
    SetCursorPosition(18,7);
    printf("tip1: 玩家可以通过 ← →方向键来移动方块");
    SetFontColor(10);
    SetCursorPosition(18,9);
    printf("tip2: 通过 ↑使方块旋转");
    SetFontColor(14);
    SetCursorPosition(18,11);
    printf("tip3: 通过 ↓加速方块下落");
    SetFontColor(11);
    SetCursorPosition(18,13);
    printf("tip4: 按空格键暂停游戏，再按空格键继续");
    SetFontColor(4);
    SetCursorPosition(18,15);
    printf("tip5: 按ESC退出游戏");
    getch();                //按任意键返回主界面
    system("cls");
    Menu();
}

void regulation()
{
    int i,j = 1;
    system("cls");
    SetFontColor(13);
    SetCursorPosition(34,3);
    printf("游戏规则");
    SetFontColor(2);
    for (i = 6; i <= 18; i++)   //输出上下边框===
    {
        for (j = 12; j <= 70; j++)  //输出左右边框||
        {
            SetCursorPosition(j, i);
            if (i == 6 || i == 18) printf("=");
            else if (j == 12 || j == 69) printf("||");
        }
    }
    SetFontColor(12);
    SetCursorPosition(16,7);
    printf("tip1: 不同形状的小方块从屏幕上方落下，玩家通过调整");
    SetCursorPosition(22,9);
    printf("方块的位置和方向，使它们在屏幕底部拼出完整的");
    SetCursorPosition(22,11);
    printf("一行或几行");
    SetFontColor(14);
    SetCursorPosition(16,13);
    printf("tip2: 每消除一行，积分增加100");
    SetFontColor(11);
    SetCursorPosition(16,15);
    printf("tip3: 每累计1000分，会提升一个等级");
    SetFontColor(10);
    SetCursorPosition(16,17);
    printf("tip4: 提升等级会使方块下落速度加快，游戏难度加大");
    getch();                //按任意键返回主界面
    system("cls");
    Menu();
}

void close()
{
    exit(0);
}