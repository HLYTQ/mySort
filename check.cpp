#include <time.h>
#include <stdio.h>
#include <algorithm>
#include "check.h"
#include "mySort.h"

CHECK_TIME_RESULT(arrInsert);
CHECK_TIME_RESULT(arrHeap);
CHECK_TIME_RESULT(bubbleSort);
CHECK_TIME_RESULT(qSort);
CHECK_TIME_RESULT(shellSort);
CHECK_TIME_RESULT(selection_sort);
CHECK_TIME_RESULT(arrCout);


bool createCheckData(long data_scale) {

	srand((unsigned int)time(NULL));

	FILE* file;

	if ((file = fopen("data.txt", "w")) == NULL) {  
		printf("Not find file\n");
		return false;
	}

	WRITE_TO_FILE_NUM(file, data_scale, rand() % DATA_SIZE);
	fprintf(file, "\n");

	fclose(file);
	return true;
}

void readData(const char* restrict_file,Type* arr_first,long data_scale) {
	FILE* fp_r;
	if ((fp_r = fopen(restrict_file, "r")) == NULL) {
		printf("Not find file\n");
		exit(0);
	}
	//读入数据
	READ_FROM_FILE(fp_r, data_scale, arr_first);

	fclose(fp_r);
}

void writeData(const char* restrict_file,Type* arr_first,long data_scale) {
	FILE* fp_w;
	if ((fp_w = fopen(restrict_file, "w")) == NULL) {
		printf("error\n");
		exit(0);
	}
	WRITE_TO_FILE_PTR(fp_w, N1, arr_first);
	fclose(fp_w);
}

void checkTimeResult(sort_time_p result,Type* arr_first,int data_scale) {
	CONTAIN_RESULT(arr_first, data_scale, result);
	std::sort(arr_first, arr_first + data_scale);
}


void displayResult(sortResult* result) {
	printf("排序结果如下：\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t|冒泡排序|选择排序|插入排序|希尔排序|快速排序|堆排序 |计数排序|\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|时间:  |%lf|%lf|%lf|%lf|%lf|%lf|%lf|\n",RESULTType);
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|比较次数:|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n",COMPARE_SWAP_TIME(compare_num));
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|交换次数:|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", COMPARE_SWAP_TIME(move_num));
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\n");
}
