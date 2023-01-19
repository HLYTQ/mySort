#include "Graphics.h"
#include <math.h>

void lineArrow(int x1, int y1, int x2, int y2)
{
	line(x1, y1, x2, y2);
	double distance = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
	double tmpx = double(x1 + (x2 - x1) * (1 - (12 * sqrt(3) / 2) / distance));
	double tmpy = double(y1 + (y2 - y1) * (1 - (12 * sqrt(3) / 2) / distance));
	if (y1 == y2)
	{
		line(x2, y2, int(tmpx), int(tmpy + 6));
		line(x2, y2, int(tmpx), int(tmpy - 6));
	}
	else
	{
		double k = (double(x2) - double(x1)) / (double(y1) - double(y2));
		double increX = 6 / sqrt(k * k + 1);
		double increY = 6 * k / sqrt(k * k + 1);
		line(x2, y2, int(tmpx + increX), int(tmpy + increY));
		line(x2, y2, int(tmpx - increX), int(tmpy - increY));
	}
}

void printTheArr(int* arr, int* left, int* top, int* right, int* bottom) {
	setbkmode(TRANSPARENT);
	setlinecolor(LIGHTBLUE);
	setfillstyle(BS_SOLID);
	setfillcolor(LIGHTBLUE);
	*left = 100, * bottom = 505;
	for (int i = 0;i < 10;i++) {
		*top = 505 - (arr[i] * 10) / 2;
		*right = (i + 1) * 100 + 20;
		*left += 100;
		fillrectangle(*left, *top, *right, *bottom);
		settextstyle(30, 0, _T("Consolas"));
		TCHAR s[5];
		_stprintf(s, _T("%d"), arr[i]);
		outtextxy(*left - 50, *top + 10, s);
		FlushBatchDraw();
		Sleep(10);
	}
}

void animated_demonstration_insertSort(int* arr) {
	//Type* arr = new Type[11];
	//readData("data.txt", arr, 10);
	int  j, length = 10;
	int left, top, right, bottom;
	printTheArr(arr, &left, &top, &right, &bottom);
	histogram();
	for (int i = 0; i < length; i++)
	{
		int insertVaule = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (insertVaule < arr[j])
			{
				arr[j + 1] = arr[j];
				Sleep(500);

				printTheArr(arr, &left, &top, &right, &bottom);
				histogram();
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insertVaule;
		Sleep(500);

		printTheArr(arr, &left, &top, &right, &bottom);
		histogram();
	}
	//delete[] arr;
}

void button(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(LIGHTGRAY);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	// 输出字符串（MBCS 字符集）
	TCHAR s1[] = L"黑体";
	settextstyle(30, 0, s1);
	TCHAR s[50] = L"hello";

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}

void histogram() {
	setlinecolor(BLACK);
	cleardevice();
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(500, 520, _T("Insert Sort"));
	lineArrow(50, 505, 50, 10);
	lineArrow(50, 505, 1200, 505);
}


void displayInsertSort(Type* arr) {
	setlinestyle(PS_SOLID, 3);
	settextcolor(BLACK);
	BeginBatchDraw();
	histogram();
	animated_demonstration_insertSort(arr);
	Sleep(3000);
}


void displayCompareResult(sort_time_p res) {
	setlinestyle(PS_SOLID, 3);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setfillcolor(LIGHTGRAY);
	cleardevice();
	BeginBatchDraw();

	lineArrow(50, 505, 50, 10);
	lineArrow(50, 505, 1200, 505);

	settextstyle(20, 0, _T("Consolas"));
	outtextxy(130, 520, _T("冒泡排序"));
	outtextxy(280, 520, _T("选择排序"));
	outtextxy(430, 520, _T("插入排序"));
	outtextxy(580, 520, _T("希尔排序"));
	outtextxy(730, 520, _T("快速排序"));
	outtextxy(880, 520, _T("堆排序"));
	outtextxy(1030, 520, _T("计数排序"));

	fillrectangle(90,  RES_HEIGHT(res->bubbleSort_t),     90  + 120, 505);
	fillrectangle(240, RES_HEIGHT(res->selection_sort_t), 240 + 120, 505);
	fillrectangle(390, RES_HEIGHT(res->arrInsert_t),      390 + 120, 505);
	fillrectangle(540, RES_HEIGHT(res->shellSort_t),      540 + 120, 505);
	fillrectangle(690, RES_HEIGHT(res->qSort_t),          690 + 120, 505);
	fillrectangle(840, RES_HEIGHT(res->arrHeap_t),        840 + 120, 505);
	fillrectangle(990, RES_HEIGHT(res->arrCout_t),        990 + 120, 505);
	
	FlushBatchDraw();
	Sleep(10000);
}

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

Type* compareTheData(sort_time_p* result) {
	int x;
	char a,dataConsequence;
again:
	system("CLS");
	printf("选择数据规模： 1:100 2:1000 3:10000 4:100000 0:退出\n请输入：");
	scanf("%c", &a);
	getchar();
	switch (a)
	{
	case '1':
		x = 100;
		break;
	case '2':
		x = 1000;
		break;
	case '3':
		x = 10000;
	case '4':
		x = 100000;
		break;
	case '0':
		exit(0);
	default:
		printf("输入错误，请重新输入\n");
		Sleep(3000);
		goto again;
		break;
	}
	printf("选择数据情况:  a:乱序 b:顺序\n请输入：");
	scanf("%c", &dataConsequence);
	getchar();

	Type* arr_first = (Type*)malloc(sizeof(Type)*x);
	//读出数据
	readData("data.txt", arr_first, x);
	Type* arr = (Type*)malloc(sizeof(Type) * 11);
	for (int i = 0;i < 10;i++) { arr[i] = arr_first[i]; }
	
	if ( dataConsequence < 'a' || dataConsequence > 'b') {
		printf("input error , use default data!\n");
	}
	else if (dataConsequence == 'b') {
		qsort(arr_first,x,sizeof(Type),cmpfunc);
	}


	//排序
	printf("Successful!!!\n");
	*result = (struct sortResult*)malloc(x * sizeof(Type));
	*(*result) = { 0,0,0,0,0,0,0,{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };  //存储排序时间结果

	checkTimeResult(*result, arr_first, x);

	displayResult(*result);
	printf("下面进入动画演示：\n");

	writeData("orderly.txt", arr_first, x);

	free(arr_first);
	return arr;
}