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
    a[tetris->x][tetris->y]=b[0];    //���ķ���λ�õ�ͼ��״̬
    switch(tetris->flag)      //��7���࣬19������
    {
        case 1:         /*���ַ��� ����
		  			               ����  */
        {
            SetFontColor(10);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x+2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 2:         /*ֱ�߷��� ��������*/
        {
            SetFontColor(13);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y]=b[2];
            a[tetris->x+4][tetris->y]=b[3];
            break;
        }
        case 3:         /*ֱ�߷��� ��
		  			               ��
								   ��
								   ��  */
        {
            SetFontColor(13);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y-2]=b[2];
            a[tetris->x][tetris->y+1]=b[3];
            break;
        }
        case 4:         /*T�ַ��� ������
		  			                ��  */
        {
            SetFontColor(11);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y]=b[2];
            a[tetris->x][tetris->y+1]=b[3];
            break;
        }
        case 5:         /* ˳ʱ��90��T�ַ���   ��
		  			                         ����
									           ��*/
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y]=b[3];
            break;
        }
        case 6:         /* ˳ʱ��180��T�ַ���     ��
		  			                            ������*/
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 7:         /* ˳ʱ��270��T�ַ���   ��
		  			                            ����
									            ��  */
        {
            SetFontColor(11);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 8:         /* Z�ַ���   ����
		  			                   ����*/
        {
            SetFontColor(14);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x+2][tetris->y+1]=b[3];
            break;
        }
        case 9:         /* ˳ʱ��Z�ַ���      ��
		  			                        ����
									        ��  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y]=b[2];
            a[tetris->x-2][tetris->y+1]=b[3];
            break;
        }
        case 10:        /* ��תZ�ַ���      ����
		  			                      ����  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x-2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 11:        /* ˳ʱ��Z�ַ���    ��
		  			                        ����
									          ��  */
        {
            SetFontColor(14);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x-2][tetris->y-1]=b[2];
            a[tetris->x-2][tetris->y]=b[3];
            break;
        }
        case 12:        /* 7�ַ���    ����
		  			                    ��
									    ��  */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y-1]=b[3];
            break;
        }
        case 13:        /* ˳ʱ��90��7�ַ���        ��
		  			                            ������*/
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 14:        /* ˳ʱ��180��7�ַ���      ��
		  			                               ��
									               ����  */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y+1]=b[3];
            break;
        }
        case 15:        /* ˳ʱ��270��7�ַ���    ������
		  			                             ��    */
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x-2][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 16:        /* ��ת7�ַ���    ����
		  			                      ��
										  ��    */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y+1]=b[1];
            a[tetris->x][tetris->y-1]=b[2];
            a[tetris->x+2][tetris->y-1]=b[3];
            break;
        }
        case 17:        /* ˳ʱ��ת90��7�ַ���    ������
		  			                                  ��*/
        {
            SetFontColor(12);
            a[tetris->x-2][tetris->y]=b[1];
            a[tetris->x+2][tetris->y+1]=b[2];
            a[tetris->x+2][tetris->y]=b[3];
            break;
        }
        case 18:        /* ˳ʱ��ת180��7�ַ���    ��
		  			                               ��
									             ����    */
        {
            SetFontColor(12);
            a[tetris->x][tetris->y-1]=b[1];
            a[tetris->x][tetris->y+1]=b[2];
            a[tetris->x-2][tetris->y+1]=b[3];
            break;
        }
        case 19:        /* ˳ָ��ת270��7�ַ���    ��
		  			                               ������*/
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
        b[i]=1;         				//����b[4]��ÿ��Ԫ�ص�ֵ��Ϊ1
    }
    MakeTetris(tetris);      			//������Ϸ����
    for( i=tetris->x-2; i<=tetris->x+4; i+=2 )
    {
        for(j=tetris->y-2;j<=tetris->y+1;j++)
        {
            if( a[i][j]==1 && j>FrameY )
            {
                SetCursorPosition(i,j);
                printf("��");     //��ӡ�߿��ڵķ���
            }
        }
    }
    //��ӡ�˵���Ϣ
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
    if(a[tetris->x][tetris->y]!=0)//�����ķ���λ������ͼ��ʱ������ֵΪ0���������ƶ�
    {
        return 0;
    }
    else
    {
        if( //��Ϊ���ַ����ҳ����ķ���λ���⣬����"��"�ַ���λ������ͼ��ʱ��˵�����λ���ܹ��������ַ��飬�����ƶ������λ�ã�����ֵΪ1�������ƶ�
            //�������ַ��飬�������ķ��������½ǵġ�����������ϣ��ң����ϵ�λ��Ϊ�գ������λ�þͿ��Է�һ�����ַ��飻�����һ��λ���ϲ�Ϊ�գ����Ų���һ����
                ( tetris->flag==1  && ( a[tetris->x][tetris->y-1]==0   &&
                                        a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
                //��Ϊֱ�߷����ҳ����ķ���λ���⣬����"��"�ַ���λ������ͼ��ʱ������ֵΪ1�������ƶ�
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
        b[i]=0;         //����b[4]��ÿ��Ԫ�ص�ֵ��Ϊ0
    }
    MakeTetris(tetris);      //��������˹����
    for( i = tetris->x - 2;i <= tetris->x + 4; i+=2 )       //��X ����  XΪ���ķ���
    {
        for(j = tetris->y-2;j <= tetris->y + 1;j++)        /* ��
															  ��
															  X
  															  ��	*/
        {
            if( a[i][j] == 0 && j > FrameY )
            {
                SetCursorPosition(i,j);
                printf("  ");    //�������
            }
        }
    }
}

void Del_Fullline(struct Tetris *tetris)//��ĳ����Frame_width-2������ʱ������������
{
    int block_num = 0,del_rows=0;  //�ֱ����ڼ�¼ĳ�з���ĸ�����ɾ������������ı���
    for(j=FrameY+Frame_height-1;j>=FrameY+1;j--)
    {
        block_num=0;
        for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
        {
            if(a[i][j]==1) //���������δ������ϣ��������������������ж��Ƿ�����
            {
                block_num++;  //��¼���з���ĸ���
                if(block_num==Frame_width-2)  //�������
                {
                    int del_x,move_y;
                    for(del_x=FrameX+2;del_x<FrameX+2*Frame_width-2;del_x+=2)//ɾ�����еķ���
                    {
                        a[del_x][j]=0;
                        SetCursorPosition(del_x,j);
                        printf("  ");
//      					Sleep(1);
                    }
                    for(move_y=j-1;move_y>FrameY;move_y--) //���ɾ�������ϵ�λ���з��飬����������ٽ���������һ��λ��
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
                                printf("��");
                            }
                        }
                    }
                    j++;   //�������ƺ������ж�ɾ�����Ƿ�����
                    del_rows++; //��¼ɾ�����������
                }
            }
        }
    }
    tetris->score+=100*del_rows; //ÿɾ��һ�У���100��
    if( del_rows>0 && ( tetris->score%1000==0 || tetris->score/1000>tetris->level-1 ) )
    {        //�����1000�ּ��ۼ�ɾ��10�У��ٶȼӿ�20ms����һ��
        tetris->speed-=20;
        tetris->level++;
    }
}
void Flag(struct Tetris *tetris)
{
    tetris->number++;     				//��ס��������ĸ���
    srand(time(NULL));  		//��ʼ�������
    if(tetris->number==1)
    {
        tetris->flag = rand()%19+1;  	//��ס��һ����������
    }
    tetris->next = rand()%19+1;   		//��ס��һ����������
}

void Gameplay()
{
    int n;
    struct Tetris t,*tetris=&t;       					//����ṹ���ָ�벢ָ��ṹ�����
    char ch;         									//������ռ�������ı���
    tetris->number=0;      								//��ʼ������˹������Ϊ0��
    tetris->speed=300;      							//��ʼ�ƶ��ٶ�Ϊ300ms
    tetris->score=0;      								//��ʼ��Ϸ�ķ���Ϊ0��
    tetris->level=1;      								//��ʼ��ϷΪ��1��
    while(1)											//ѭ���������飬ֱ����Ϸ����
    {
        Flag(tetris);     								//�õ���������˹�������͵����
        Temp=tetris->flag;     							//��ס��ǰ����˹�������
        tetris->x=FrameX+2*Frame_width+6;				//���Ԥ�����淽���x����
        tetris->y=FrameY+10;                            //���Ԥ�����淽���y����
        tetris->flag = tetris->next;                    //�����һ������˹��������
        PrintTetris(tetris);                           //���ô�ӡ����˹���鷽��
        tetris->x=FrameX+Frame_width;  					//�����Ϸ�������ķ���x����
        tetris->y=FrameY-1;     						//�����Ϸ�������ķ���y����
        tetris->flag=Temp;     							//ȡ����ǰ�Ķ���˹�������
        while(1)  										//���Ʒ��鷽��ֱ�����鲻������
        {
label:      PrintTetris(tetris);					//��ӡ����˹����
            Sleep(tetris->speed);   					//�ӻ�ʱ��
            CleanTetris(tetris);  						//����ۼ�
            Temp1=tetris->x;    						//��ס���ķ���������ֵ
            Temp2=tetris->flag;    						//��ס��ǰ����˹�������
            if(kbhit())       				  	 		//�ж��Ƿ��м������룬������ch������
            {
                ch=getch();
                if(ch==75)     							//�� ���������󶯣����ĺ������2
                {
                    tetris->x-=2;
                }
                if(ch==77)     							//�� ���������Ҷ������ĺ������2
                {
                    tetris->x+=2;
                }
                if(ch==80)     							//�� �������������
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
                if(ch==72)     						//�� ���������,����ǰ����˳ʱ��ת90��
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
                if(ch == 32)     					//���ո������ͣ
                {
                    PrintTetris(tetris);
                    while(1)
                    {
                        if(kbhit())   			//�ٰ��ո����������Ϸ
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
                    memset(a,0,sizeof(a));       //��ʼ��BOX����
                    Menu();
                }
                if(ifMove(tetris)==0) 			//������ɶ������������Ч
                {
                    tetris->x=Temp1;
                    tetris->flag=Temp2;
                }
                else      						//����ɶ���ִ�в���
                {
                    goto label;
                }
            }
            tetris->y++;     					//���û�в���ָ����������ƶ�
            if(ifMove(tetris)==0)  				//��������ƶ��Ҳ��ɶ���������ڴ˴�
            {
                tetris->y--;
                PrintTetris(tetris);
                Del_Fullline(tetris);
                break;
            }
        }
        for(i=tetris->y-2;i<tetris->y+2;i++)	//��Ϸ�������������鴥����λ��
        {
            if(i==FrameY)
            {
                system("cls");
                SetCursorPosition(29,7);
                printf("   \n");
                SetFontColor(12);
                printf("\t\t\t��������   ��     ��   ����     \n");
                printf("\t\t\t��         ����   ��   ��  ��   \n");
                printf("\t\t\t������     ��  �� ��   ��   ��  \n");
                printf("\t\t\t��         ��   ����   ��  ��   \n");
                printf("\t\t\t��������   ��     ��   ����     \n");
                SetCursorPosition(17,18);
                SetFontColor(14);
                printf("��Ҫ������һ��-------1");
                SetCursorPosition(44,18);
                printf("�����ˣ��˳���-------2\n");
                int n;
                SetCursorPosition(32,20);
                printf("ѡ��1/2����");
                SetFontColor(11);
                scanf("%d", &n);
                switch (n)
                {
                    case 1:
                        system("cls");
                        Replay();       	//���¿�ʼ��Ϸ
                        break;
                    case 2:
                        exit(0);
                        break;
                }
            }
        }
        tetris->flag = tetris->next;  			//�����һ������˹�����ͼ��(�ұߴ���)
        tetris->x=FrameX+2*Frame_width+6;
        tetris->y=FrameY+10;
        CleanTetris(tetris);
    }
}

void Replay()
{
    system("cls");                  	//����
    memset(a,0,sizeof(a));       //��ʼ��BOX���飬���򲻻�������ʾ���飬������Ϸֱ�ӽ���
    DrawGameFrame();       	//������Ϸ����
    Gameplay(); 			//��ʼ��Ϸ
}
