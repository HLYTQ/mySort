
/*
	1.时间充分的话考虑更改快速排序的实现
	2.最后有一个没有使用的计数排序，可以考虑增加
	3.有时间的话优化细节，避免不必要的性能损耗
*/

#include "mySort.h"
#include <stdio.h>
#include <stdlib.h>



#if TEST_BUTTON
void arrPrint(Type* arr)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
#endif


void bubbleSort(Type* arr, const int length,performance* frequece) {
	for(int i = 0;i < length;i++)
		for (int j = 0;j < length - i;j++) {
			if (arr[j] > arr[j + 1]) {
				frequece->compare_num++;
				SWAP(arr[j], arr[j + 1]);
				frequece->move_num+=2;
			}
		}
}


//快速排序
void qSort(Type* arr,const int length,performance* frequence){
	quickSort(arr, 0, length-1,frequence);
}

void quickSort(Type* arr, int left, int right,performance* frequence)
{
	int pivot;
	if (left < right)
	{
		pivot = partition(arr, left, right,frequence);
		quickSort(arr, left, pivot - 1,frequence);
		quickSort(arr, pivot + 1, right,frequence);
	}
}

int partition(Type* arr, int left, int right,performance* frequence)
{
	int i, k;
	for (i = left, k = left; i < right; i++)
	{
		if (arr[right] > arr[i])
		{
			SWAP(arr[i], arr[k]);
			frequence->move_num+=2;
			frequence->compare_num++;
			k++;
		}
	}
	SWAP(arr[k], arr[right]);
	frequence->move_num+=2;
	return k;
}


//堆排序
void arrHeap(Type* arr,const int n,performance* frequence)
{
	//调整为大根堆
	for (int i = n/ 2 - 1; i >= 0; i--)
	{
		adjustMaxHeap(arr, i, n,frequence);
	}
	SWAP(arr[0], arr[n-1]);
	frequence->move_num += 2;
	for (int i = N - 1; i > 1; i--)
	{
		adjustMaxHeap(arr, 0, i,frequence);
		SWAP(arr[0], arr[i - 1]);
		frequence->move_num += 2;
	}
}

void adjustMaxHeap(Type* arr, int adjustPos, int length,performance* frequence)
{
	int dad = adjustPos;
	int son = dad * 2 + 1;
	while (son < length)
	{
		if (son + 1 < length && arr[son] < arr[son + 1]) //先判断有无右子节点，如果有，判断右子是否大于左子
		{
			frequence->compare_num++;
			son++;
		}
		if (arr[dad] < arr[son])
		{
			SWAP(arr[dad], arr[son]);
			frequence->compare_num++;
			frequence->move_num+=2;
			dad = son;
			son = dad * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//直接插入排序
void arrInsert(Type* arr,const int length,performance* frequence)
{
	int  j;
	for (int i = 0; i < length; i++)
	{
		Type insertVaule = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (insertVaule < arr[j])
			{
				arr[j + 1] = arr[j];
				frequence->compare_num++;
				frequence->move_num++;
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insertVaule;
		frequence->move_num+=2;
	}
}

//希尔排序
void shellSort(Type* arr,const int length,performance* frequence) {
#if !TEST_BUTTON
	int inCrement=0;
	for (int i = 0;i < SEDWICK_N;i++) {
		if (sedwick[i] > length) { inCrement = i - 1; break; }
	}
	Type tmp; int i,j;
	for (;inCrement >= 0;inCrement--) {
		for ( i = sedwick[inCrement];i < length;i++) {
			tmp = arr[i];
			for ( j = i;j >= sedwick[inCrement];j-=sedwick[inCrement]) {
				if (tmp < arr[j - sedwick[inCrement]]) {
					arr[j] = arr[j - sedwick[inCrement]];
					frequence->compare_num++;
					frequence->move_num++;
				}
				else break;
			}
			arr[j] = tmp;
			frequence->move_num+=2;
		}
	}
#else
	int gap, i, j;
	int temp;
	for (gap = length >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < length; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
				arr[j + gap] = arr[j];
				frequence->compare_num++;
				frequence->move_num++;
			}
			arr[j + gap] = temp;
			frequence->move_num += 2;
		}
#endif
}


void selection_sort(Type* arr, const int length,performance* frequence) {
	long move_num = 0, compare_num = 0;
	for (int i = 0;i < length - 1;i++) {
		int min = i,j;
		for (j=i+1;j<length;j++)
		{
			if (arr[j] < arr[min]) {
				min = j;
				frequence->compare_num++;
			}
		}
		SWAP(arr[j], arr[min]);
		frequence->move_num+=2;
	}
}

//计数排序
void arrCout(Type* arr,const int length,performance* frequence)
{
	int k = 0, * cout;
	cout = (Type*)calloc(length,sizeof(Type));
	for (int i = 0; i < length; i++)
	{
		cout[arr[i]]++;
		frequence->compare_num++;
	}
	for (int i = 0;i < length && k<length;i++) {
		for (int j = 0;j < cout[i];j++) {
			arr[k++] = i;
		}
	}
	frequence->move_num = length;
	free(cout);
	cout = NULL;
}
