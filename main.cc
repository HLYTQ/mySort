/*
 *  mySort/src/main.cc
 *
 *  (C) 2022/11/24 Tangzheng
 */


// ������������
// ���һ�����Գ���Ƚϼ����ڲ������㷨�Ĺؼ��ֱȽϴ������ƶ�������ȡ��ֱ�۸��ܡ�
// -----------------------------------------------------------------------------------
// ������Ҫ��
// ��1��ʵ�ָ����ڲ��������ٰ���ð������ֱ��ѡ������ֱ�Ӳ�������ϣ�����򣬿������򣬶�����
// ��2�����ݲ�������㷨���ɣ���������Ϊ100��1000��10000��100000�ȼ��ֹ�ģ�����ɺ�����ݱ����ļ��У��Ժ�ֱ�Ӵ��ļ��ж�ȡ������õ�����ҲҪ�������ļ��С�
// ��3�����ɸ��������˳���������򣩵����ݽ������򣬱Ƚϸ����㷨��ʱ�临�Ӷȡ�
// ��4����ʾ�������˻��Ի�����ʽ���С���̬��ʾ��������̣�ÿ�β��������ʾ���ֱȽ�ָ��ֵ���б�����״ͼ��ʾ���Ա�Ƚϸ�����������ӡ�
// ��5��С�ᣨ��ʵ������Щ���ܣ�������Щ���⣬��ν���ģ��Ժ���Щ������Ҫ��ǿ����


#include<stdio.h>
#include<time.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include <stdlib.h>
#include"mySort.h"
#include "check.h"
#include "Graphics.h"

#pragma warning(disable:4996)

#define TEST_EASYX 1

int main()
{
	//�����������
	createCheckData(N4);

	sort_time_p res = NULL;
	Type* arr = compareTheData(&res);

	initgraph(1300, 600, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	while (true)
	{
		ExMessage msg;
		cleardevice();
		BeginBatchDraw();
		settextcolor(BLACK);
		TCHAR s[50] = L"��������";
		button(550, 100, 250, 50, s);

		TCHAR s1[50] = L"��������Ƚ�";
		button(480, 200, 300, 50, s1);

		//TCHAR s2[50] = L"Exit";
		//button(550, 300, 250, 50, s2);

		FlushBatchDraw();

		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 550 && msg.x <= 550 + 250 && msg.y >= 100 && msg.y <= 100 + 50) {
					displayInsertSort(arr);
				}
				else if (msg.x >= 480 && msg.x <= 480 + 300 && msg.y >= 200 && msg.y <= 200 + 50) {
					displayCompareResult(res);
				}
				break;
			default:
				break;
			}
		}
	}

	//�ͷ��ڴ�
	free(arr);
	free(res);
	_getch();
	//�رմ���
	closegraph();
	return 0;
}
