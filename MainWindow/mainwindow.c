//
// Created by Administrator on 2019-12-07.
//
#include "mainwindow.h"

void DrawGameFrame()
{
    SetCursorPosition(FrameX+Frame_width-7,FrameY-2);   	//��ӡ��Ϸ����
    SetFontColor(11);
    printf("ɳ�����˹����");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+7);  	//��ӡѡ��˵�
    SetFontColor(2);
    printf("**********");
    SetCursorPosition(FrameX+2*Frame_width+13,FrameY+7);  	//��ӡѡ��˵�
    SetFontColor(3);
    printf("��һ���ַ��飺");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+13);
    SetFontColor(2);
    printf("**********");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+17);
    SetFontColor(14);
    printf("��������ת");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+19);
    printf("�ո���ͣ��Ϸ");
    SetCursorPosition(FrameX+2*Frame_width+3,FrameY+15);
    printf("Esc ���˳���Ϸ");
    SetCursorPosition(FrameX,FrameY);
    SetFontColor(12);
    printf("�X");							//��ӡ���
    SetCursorPosition(FrameX+2*Frame_width-2,FrameY);
    printf("�[");
    SetCursorPosition(FrameX,FrameY+Frame_height);
    printf("�^");
    SetCursorPosition(FrameX+2*Frame_width-2,FrameY+Frame_height);
    printf("�a");
    a[FrameX][FrameY+Frame_height]=2;       //��ס�ô�����ͼ��
    a[FrameX+2*Frame_width-2][FrameY+Frame_height]=2;
    for(i=2;i<2*Frame_width-2;i+=2)
    {
        SetCursorPosition(FrameX+i,FrameY);
        printf("�T");         //��ӡ�Ϻ��
    }
    for(i=2;i<2*Frame_width-2;i+=2)
    {
        SetCursorPosition(FrameX+i,FrameY+Frame_height);
        printf("�T");         //��ӡ�º��
        a[FrameX+i][FrameY+Frame_height]=2;    //��ס�º����ͼ��
    }
    for(i=1;i<Frame_height;i++)
    {
        SetCursorPosition(FrameX,FrameY+i);
        printf("�U");         //��ӡ������
        a[FrameX][FrameY+i]=2;       //��ס��������ͼ��
    }
    for(i=1;i<Frame_height;i++)
    {
        SetCursorPosition(FrameX+2*Frame_width-2,FrameY+i);
        printf("�U");         //��ӡ������
        a[FrameX+2*Frame_width-2][FrameY+i]=2;   //��ס��������ͼ��
    }
}

