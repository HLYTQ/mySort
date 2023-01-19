#pragma once
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "mySort.h"
#include "check.h"

#define  RES_HEIGHT(res) (505 - ((res*100)/2)/2)

void lineArrow(int x1, int y1, int x2, int y2);
void animated_demonstration_insertSort(int* arr);
void histogram();
void printTheArr(int* arr, int* left, int* top, int* right, int* bottom);
void button(int x, int y, int w, int h, TCHAR* text);

void displayInsertSort(Type* arr);
void displayCompareResult(sort_time_p res);
Type* compareTheData(sort_time_p* res);