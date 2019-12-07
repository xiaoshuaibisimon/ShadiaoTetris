//
// Created by Administrator on 2019-12-04.
//
#include "common.h"
#include <time.h>
#include "../Welcome/welcom.h"
#include "../MainWindow/mainwindow.h"

int SetFontColor(int SetFontColor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),SetFontColor);
    return 0;
}

int  SetCursorPosition(int x,int y){
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void MakeTetris(struct Tetris *tetris)
{
    a[tetris->x][tetris->y]=b[0];    //中心方块位置的图形状态
    switch(tetris->flag)      //共7大类，19种类型
    {
        case 1:         /*田字方块 ■■
		  			               ■■  */
        {
            SetFontColor(10);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x+2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 2:         /*直线方块 ■■■■*/
        {
            SetFontColor(13);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y]=b[2];
            a[tetris->x+4][tetris->y]=b[3];
            break;
        }
        case 3:         /*直线方块 ■
		  			               ■
								   ■
								   ■  */
        {
            SetFontColor(13);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y-2]=b[2];
            a[tetris->x][tetris->y+1]=b[3];
            break;
        }
        case 4:         /*T字方块 ■■■
		  			                ■  */
        {
            SetFontColor(11);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y]=b[2];
            a[tetris->x][tetris->y+1]=b[3];
            break;
        }
        case 5:         /* 顺时针90°T字方块   ■
		  			                         ■■
									           ■*/
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y]=b[3];
            break;
        }
        case 6:         /* 顺时针180°T字方块     ■
		  			                            ■■■*/
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 7:         /* 顺时针270°T字方块   ■
		  			                            ■■
									            ■  */
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 8:         /* Z字方块   ■■
		  			                   ■■*/
        {
            SetFontColor(14);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x+2][tetris->y+1]=b[3];
            break;
        }
        case 9:         /* 顺时针Z字方块      ■
		  			                        ■■
									        ■  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x-2][tetris->y+1]=b[3];
            break;
        }
        case 10:        /* 反转Z字方块      ■■
		  			                      ■■  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 11:        /* 顺时针Z字方块    ■
		  			                        ■■
									          ■  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x-2][tetris->y-1]=b[2];
            a[tetris->x-2][tetris->y]=b[3];
            break;
        }
        case 12:        /* 7字方块    ■■
		  			                    ■
									    ■  */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y-1]=b[3];
            break;
        }
        case 13:        /* 顺时针90°7字方块        ■
		  			                            ■■■*/
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 14:        /* 顺时针180°7字方块      ■
		  			                               ■
									               ■■  */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y+1]=b[3];
            break;
        }
        case 15:        /* 顺时针270°7字方块    ■■■
		  			                             ■    */
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x-2][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 16:        /* 反转7字方块    ■■
		  			                      ■
										  ■    */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y-1]=b[3];
            break;
        }
        case 17:        /* 顺时针转90°7字方块    ■■■
		  			                                  ■*/
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 18:        /* 顺时针转180°7字方块    ■
		  			                               ■
									             ■■    */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y+1]=b[3];
            break;
        }
        case 19:        /* 顺指针转270°7字方块    ■
		  			                               ■■■*/
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x-2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        default:
            break;
    }
}

void PrintTetris(struct Tetris *tetris)
{
    for(i=0;i<4;i++)
    {
        b[i]=1;         				//数组b[4]的每个元素的值都为1
    }
    MakeTetris(tetris);      			//制作游戏窗口
    for( i=tetris->x-2; i<=tetris->x+4; i+=2 )
    {
        for(j=tetris->y-2;j<=tetris->y+1;j++)
        {
            if( a[i][j]==1 && j>FrameY )
            {
                SetCursorPosition(i,j);
                printf("■");     //打印边框内的方块
            }
        }
    }
    //打印菜单信息
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+1);
    SetFontColor(4);
    printf("level : ");
    SetFontColor(12);
    printf(" %d",tetris->level);
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+3);
    SetFontColor(4);
    printf("score : ");
    SetFontColor(12);
    printf(" %d",tetris->score);
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+5);
    SetFontColor(4);
    printf("speed : ");
    SetFontColor(12);
    printf(" %dms",tetris->speed);
}

int ifMove(struct Tetris *tetris)
{
    if(a[tetris->x][tetris->y]!=0)//当中心方块位置上有图案时，返回值为0，即不可移动
    {
        return 0;
    }
    else
    {
        if( //当为田字方块且除中心方块位置外，其他"■"字方块位置上无图案时，说明这个位置能够放下田字方块，可以移动到这个位置，返回值为1，即可移动
            //比如田字方块，它的中心方块是左下角的■，如果它的上，右，右上的位置为空，则这个位置就可以放一个田字方块；如果有一个位置上不为空，都放不下一个田
                ( tetris->flag==1  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                //或为直线方块且除中心方块位置外，其他"■"字方块位置上无图案时，返回值为1，即可移动
                ( tetris->flag==2  && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x+2][tetris->y]==0 && a[tetris->x+4][tetris->y]==0 ) )   ||
                ( tetris->flag==3  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y-2]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
                ( tetris->flag==4  && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x+2][tetris->y]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
                ( tetris->flag==5  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y]==0 ) )   ||
                ( tetris->flag==6  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
                ( tetris->flag==7  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
                ( tetris->flag==8  && ( a[tetris->x][tetris->y+1]==0   &&
                                        a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
                ( tetris->flag==9  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
                ( tetris->flag==10 && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                ( tetris->flag==11 && ( a[tetris->x][tetris->y+1]==0   &&
                                        a[tetris->x-2][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0 ) ) ||
                ( tetris->flag==12 && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y-1]==0 ) ) ||
                ( tetris->flag==15 && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x-2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                ( tetris->flag==14 && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
                ( tetris->flag==13 && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                ( tetris->flag==16 && ( a[tetris->x][tetris->y+1]==0   &&
                                        a[tetris->x][tetris->y-1]==0 && a[tetris->x+2][tetris->y-1]==0 ) ) ||
                ( tetris->flag==19 && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                ( tetris->flag==18 && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
                ( tetris->flag==17 && ( a[tetris->x-2][tetris->y]==0   &&
                                        a[tetris->x+2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) )
        {
            return 1;
        }
    }
    return 0;
}

void CleanTetris(struct Tetris *tetris)
{
    for(i=0;i<4;i++)
    {
        b[i]=0;         //数组b[4]的每个元素的值都为0
    }
    MakeTetris(tetris);      //制作俄罗斯方块
    for( i = tetris->x - 2;i <= tetris->x + 4; i+=2 )       //■X ■■  X为中心方块
    {
        for(j = tetris->y-2;j <= tetris->y + 1;j++)        /* ■
															  ■
															  X
  															  ■	*/
        {
            if( a[i][j] == 0 && j > FrameY )
            {
                SetCursorPosition(i,j);
                printf("  ");    //清除方块
            }
        }
    }
}

void Del_Fullline(struct Tetris *tetris)//当某行有Frame_width-2个方块时，则满行消除
{
    int block_num = 0,del_rows=0;  //分别用于记录某行方块的个数和删除方块的行数的变量
    for(j=FrameY+Frame_height-1;j>=FrameY+1;j--)
    {
        block_num=0;
        for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
        {
            if(a[i][j]==1) //竖坐标依次从下往上，横坐标依次由左至右判断是否满行
            {
                block_num++;  //记录此行方块的个数
                if(block_num==Frame_width-2)  //如果满行
                {
                    int del_x,move_y;
                    for(del_x=FrameX+2;del_x<FrameX+2*Frame_width-2;del_x+=2)//删除满行的方块
                    {
                        a[del_x][j]=0;
                        SetCursorPosition(del_x,j);
                        printf("  ");
//      					Sleep(1);
                    }
                    for(move_y=j-1;move_y>FrameY;move_y--) //如果删除行以上的位置有方块，则先清除，再将方块下移一个位置
                    {
                        for(del_x=FrameX+2;del_x<FrameX+2*Frame_width-2;del_x+=2)
                        {
                            if(a[del_x][move_y]==1)
                            {
                                a[del_x][move_y]=0;
                                SetCursorPosition(del_x,move_y);
                                printf("  ");
                                a[del_x][move_y+1]=1;
                                SetCursorPosition(del_x,move_y+1);
                                printf("■");
                            }
                        }
                    }
                    j++;   //方块下移后，重新判断删除行是否满行
                    del_rows++; //记录删除方块的行数
                }
            }
        }
    }
    tetris->score+=100*del_rows; //每删除一行，得100分
    if( del_rows>0 && ( tetris->score%1000==0 || tetris->score/1000>tetris->level-1 ) )
    {        //如果得1000分即累计删除10行，速度加快20ms并升一级
        tetris->speed-=20;
        tetris->level++;
    }
}
void Flag(struct Tetris *tetris)
{
    tetris->number++;     				//记住产生方块的个数
    srand(time(NULL));  		//初始化随机数
    if(tetris->number==1)
    {
        tetris->flag = rand()%19+1;  	//记住第一个方块的序号
    }
    tetris->next = rand()%19+1;   		//记住下一个方块的序号
}

void Gameplay()
{
    int n;
    struct Tetris t,*tetris=&t;       					//定义结构体的指针并指向结构体变量
    char ch;         									//定义接收键盘输入的变量
    tetris->number=0;      								//初始化俄罗斯方块数为0个
    tetris->speed=300;      							//初始移动速度为300ms
    tetris->score=0;      								//初始游戏的分数为0分
    tetris->level=1;      								//初始游戏为第1关
    while(1)											//循环产生方块，直至游戏结束
    {
        Flag(tetris);     								//得到产生俄罗斯方块类型的序号
        Temp=tetris->flag;     							//记住当前俄罗斯方块序号
        tetris->x=FrameX+2*Frame_width+6;				//获得预览界面方块的x坐标
        tetris->y=FrameY+10;                            //获得预览界面方块的y坐标
        tetris->flag = tetris->next;                    //获得下一个俄罗斯方块的序号
        PrintTetris(tetris);                           //调用打印俄罗斯方块方法
        tetris->x=FrameX+Frame_width;  					//获得游戏窗口中心方块x坐标
        tetris->y=FrameY-1;     						//获得游戏窗口中心方块y坐标
        tetris->flag=Temp;     							//取出当前的俄罗斯方块序号
        while(1)  										//控制方块方向，直至方块不再下移
        {
label:      PrintTetris(tetris);					//打印俄罗斯方块
            Sleep(tetris->speed);   					//延缓时间
            CleanTetris(tetris);  						//清除痕迹
            Temp1=tetris->x;    						//记住中心方块横坐标的值
            Temp2=tetris->flag;    						//记住当前俄罗斯方块序号
            if(kbhit())       				  	 		//判断是否有键盘输入，有则用ch↓接收
            {
                ch=getch();
                if(ch==75)     							//按 ←键则向左动，中心横坐标减2
                {
                    tetris->x-=2;
                }
                if(ch==77)     							//按 →键则向右动，中心横坐标加2
                {
                    tetris->x+=2;
                }
                if(ch==80)     							//按 ↓键则加速下落
                {
                    if(ifMove(tetris)!=0)
                    {
                        tetris->y+=2;
                    }
                    if(ifMove(tetris)==0)
                    {
                        tetris->y=FrameY+Frame_height-2;
                    }
                }
                if(ch==72)     						//按 ↑键则变体,即当前方块顺时针转90度
                {
                    if( tetris->flag>=2 && tetris->flag<=3 )
                    {
                        tetris->flag++;
                        tetris->flag%=2;
                        tetris->flag+=2;
                    }
                    if( tetris->flag>=4 && tetris->flag<=7 )
                    {
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=4;
                    }
                    if( tetris->flag>=8 && tetris->flag<=11 )
                    {
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=8;
                    }
                    if( tetris->flag>=12 && tetris->flag<=15 )
                    {
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=12;
                    }
                    if( tetris->flag>=16 && tetris->flag<=19 )
                    {
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=16;
                    }
                }
                if(ch == 32)     					//按空格键，暂停
                {
                    PrintTetris(tetris);
                    while(1)
                    {
                        if(kbhit())   			//再按空格键，继续游戏
                        {
                            ch=getch();
                            if(ch == 32)
                            {
                                goto label;
                            }
                        }
                    }
                }
                if(ch == 27)
                {
                    system("cls");
                    memset(a,0,sizeof(a));       //初始化BOX数组
                    Menu();
                }
                if(ifMove(tetris)==0) 			//如果不可动，上面操作无效
                {
                    tetris->x=Temp1;
                    tetris->flag=Temp2;
                }
                else      						//如果可动，执行操作
                {
                    goto label;
                }
            }
            tetris->y++;     					//如果没有操作指令，方块向下移动
            if(ifMove(tetris)==0)  				//如果向下移动且不可动，方块放在此处
            {
                tetris->y--;
                PrintTetris(tetris);
                Del_Fullline(tetris);
                break;
            }
        }
        for(i=tetris->y-2;i<tetris->y+2;i++)	//游戏结束条件：方块触到框顶位置
        {
            if(i==FrameY)
            {
                system("cls");
                SetCursorPosition(29,7);
                printf("   \n");
                SetFontColor(12);
                printf("\t\t\t■■■■   ■     ■   ■■     \n");
                printf("\t\t\t■         ■■   ■   ■  ■   \n");
                printf("\t\t\t■■■     ■  ■ ■   ■   ■  \n");
                printf("\t\t\t■         ■   ■■   ■  ■   \n");
                printf("\t\t\t■■■■   ■     ■   ■■     \n");
                SetCursorPosition(17,18);
                SetFontColor(14);
                printf("我要重新玩一局-------1");
                SetCursorPosition(44,18);
                printf("不玩了，退出吧-------2\n");
                int n;
                SetCursorPosition(32,20);
                printf("选择【1/2】：");
                SetFontColor(11);
                scanf("%d", &n);
                switch (n)
                {
                    case 1:
                        system("cls");
                        Replay();       	//重新开始游戏
                        break;
                    case 2:
                        exit(0);
                        break;
                }
            }
        }
        tetris->flag = tetris->next;  			//清除下一个俄罗斯方块的图形(右边窗口)
        tetris->x=FrameX+2*Frame_width+6;
        tetris->y=FrameY+10;
        CleanTetris(tetris);
    }
}

void Replay()
{
    system("cls");                  	//清屏
    memset(a,0,sizeof(a));       //初始化BOX数组，否则不会正常显示方块，导致游戏直接结束
    DrawGameFrame();       	//制作游戏窗口
    Gameplay(); 			//开始游戏
}
