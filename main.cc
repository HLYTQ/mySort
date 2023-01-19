/*
 *  mySort/src/main.cc
 *
 *  (C) 2022/11/24 Tangzheng
 */


// 【问题描述】
// 设计一个测试程序比较几种内部排序算法的关键字比较次数和移动次数以取得直观感受。
// -----------------------------------------------------------------------------------
// 【基本要求】
// （1）实现各种内部排序。至少包括冒泡排序，直接选择排序，直接插入排序，希尔排序，快速排序，堆排序。
// （2）数据采用随机算法生成，数据量分为100，1000，10000，100000等几种规模，生成后的数据保存文件中，以后直接从文件中读取，排序好的数据也要保存在文件中。
// （3）生成各种情况（顺序、逆序、无序）的数据进行排序，比较各种算法的时间复杂度。
// （4）演示程序以人机对话的形式进行。动态显示其排序过程，每次测试完毕显示各种比较指标值的列表，用柱状图表示，以便比较各种排序的优劣。
// （5）小结（已实现了哪些功能？遇到哪些问题，如何解决的？以后哪些方面需要加强？）


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
	//生成随机数据
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
		TCHAR s[50] = L"插入排序";
		button(550, 100, 250, 50, s);

		TCHAR s1[50] = L"各个排序比较";
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

	//释放内存
	free(arr);
	free(res);
	_getch();
	//关闭窗口
	closegraph();
	return 0;
}
