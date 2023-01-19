
/*
 *  mySort/check.h
 *
 *  (C) 2022/11/25 tangzheng
 */

/*
  ���ɺͼ������
  ���������������������
*/

#pragma once
#include <stdlib.h>
#include <time.h>
#include "mySort.h"
#pragma warning(disable:4996)

#define sort_time_p struct sortResult*


#define WRITE_TO_FILE_NUM(file_ptr,length,number)\
	for(size_t i = 0;i < length;i++){\
		fprintf(file_ptr,"%d ",number);\
	}\
	fprintf(file_ptr,"\n");

#define WRITE_TO_FILE_PTR(file_ptr,length,number)\
	for(size_t i = 0;i < length;i++){\
		fprintf(file_ptr,"%d ",number[i]);\
	}\
	fprintf(file_ptr,"\n");

#define READ_FROM_FILE(file_ptr,length,number)\
	for (size_t i = 0;i < length ; i++)\
	{\
		fscanf(file_ptr, "%d ", &number[i]);\
		fscanf(file_ptr, "\n");\
	}


/*
	�� checkTimeResult ��ʼ���� CONTAIN_RES  ��ÿ�������ָ��ֳ���
	Ϊÿ������չ����"CHECK_TIME_RESULT"�ĺ꺯�����꺯���е�����
	"SORT_TIME"�������������뵽ʵ������ sortResult �С�
	�� sortResult ��ָ���㴫�ݣ�ÿһ���ֽ��д�뵽ͬһ���ڴ��С�
*/

#define SORT_TIME(sort_function,res,index)\
	clock_t start##index, end##index;\
	start##index = clock();\
	sort_function;\
	end##index = clock();\
	res = (double)(end##index - start##index) / CLK_TCK

#define CHECK_TIME_RESULT(sort_function)\
	void check_##sort_function(Type* tmp,int length,sortResult* res){\
		Type* arr = new Type[length+1];\
		for(int i = 0;i<length;i++){\
			arr[i] = tmp[i];}\
		SORT_TIME(sort_function(arr, length,&res->fre_##sort_function),res->##sort_function##_t, 1);\
		delete[] arr;\
	}

#define CONTAIN_RESULT(tmp,length,res_p)\
	check_bubbleSort     ( tmp, length, res_p);\
	check_selection_sort ( tmp, length, res_p);\
	check_arrInsert      ( tmp, length, res_p);\
	check_shellSort      ( tmp, length, res_p);\
	check_qSort          ( tmp, length, res_p);\
	check_arrHeap        ( tmp, length, res_p);\
	check_arrCout        ( tmp, length, res_p);


bool createCheckData(long data_scale);

void readData(const char* restrict_file,Type* arr_first,long data_scale);
void writeData(const char* restrict_file,Type * arr_first,long data_scale);

void checkTimeResult(sort_time_p result,Type* arr_first,int data_scale);

void displayResult(sort_time_p result);