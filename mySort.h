#pragma once
#include<stddef.h>

#define Type int

#define N  100
#define N1 100
#define N2 1000
#define N3 10000
#define N4 100000
#define DATA_SIZE 100

#define TEST_BUTTON 1

#define SWAP(a,b) Type temp=a;a=b;b=temp; 


#define RESULTType result->bubbleSort_t,\
				   result->selection_sort_t,\
				   result->arrInsert_t,\
				   result->shellSort_t,\
				   result->qSort_t,\
				   result->arrHeap_t,\
				   result->arrCout_t

#define COMPARE_SWAP_TIME(choice) result->fre_bubbleSort.choice,\
							 result->fre_selection_sort.choice,\
							 result->fre_arrInsert.choice,\
							 result->fre_shellSort.choice,\
							 result->fre_qSort.choice,\
							 result->fre_arrHeap.choice,\
							 result->fre_arrCout.choice

/// "seewick" 希尔增量    数据规模：100，1000，10000，100000
#if !TEST_BUTTON
#define SEDWICK_N 14
const int sedwick[14] = { 
		1, 5, 19, 41, 109, 209, 505, 929, 2161,
		3905, 8929, 16001, 36289, 64769
};
#endif

//比较，移动
typedef struct {
	long move_num;
	long compare_num;
}performance;

//保存每个排序花费的时间和发生的比较，数据移动
struct sortResult {
	double arrInsert_t;
	double qSort_t;
	double bubbleSort_t;
	double selection_sort_t;
	double arrHeap_t;
	double shellSort_t;
	double arrCout_t;
	performance fre_arrInsert;
	performance fre_qSort;
	performance fre_bubbleSort;
	performance fre_selection;
	performance fre_arrHeap;
	performance fre_shellSort;
	performance fre_selection_sort;
	performance fre_arrCout;

};

//	实现各种内部排序。至少包括冒泡排序，直接选择排序，直接插入排序，希尔排序，快速排序，堆排序

void arrPrint(Type* arr);
//冒泡排序
void bubbleSort(Type* arr, const int length,performance*);
//快速排序
void qSort(Type* arr, const int length,performance*);
void quickSort(Type* arr, int left, int right, performance*);
int partition(Type* arr, int left, int right,performance*);
//希尔排序
void shellSort(Type* arr, const int length,performance*);
//堆排序
void arrHeap(Type* arr,const int length,performance*);
void adjustMaxHeap(Type* arr, int adjustPos, int length,performance*);
//插入排序
void arrInsert(Type* arr, const int length,performance*);
//选择排序
void selection_sort(Type* arr, const int length,performance*);

void arrCout(Type* arr,const int length,performance*);

