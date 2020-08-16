﻿

#include <stdlib.h>
#include <stdio.h>
#include"Linklist.h"

/*
	int* pADDR;  //数据地址
	int size;  //元素大小
	int capacity;  //容量
*/

// 初始化:
Array* Init_Array() {
	// 申请内存:
	Array* myArray = (Array*)malloc(sizeof(Array));
	// 初始化:
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);
	return myArray;
}

// 插入:
void Push_Back_Array(Array* arr, int value) {
	if (arr == NULL) {
		return;
	}

	// 判断空间是否足够
	if (arr->size == arr->capacity) {
		// 申请一块更大的内存:
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		// 将数据 copy 到型内存空间中:
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		// 释放旧的内存空间:
		free(arr->pAddr);
		// 更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpace;
	}

	// 插入新元素:
	arr->pAddr[arr->size] = value;
	arr->size++;
}

// 下标删除:
void RemoveByPos_Array(Array* arr, int pos) {
	if (arr == NULL) {
		return;
	}

	// 判断 pos 是否有效:
	if (pos < 0 || pos >= arr->size) {
		return;
	}

	// 删除元素:
	for (int i = pos; i < arr->size - 1; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->size--;
}

// 值删除:
void RemoveByValue_Array(Array* arr, int value) {
	if (arr == NULL) {
		return;
	}

	// 查找值的位置:
	int pos = FindSpace_Array(arr, value);

	// 根据位置删除:
	RemoveByPos_Array(arr, pos);
}

// 查找:
int FindSpace_Array(Array* arr, int value) {
	if (arr == NULL) {
		return -1;
	}

	// 查找:
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			return pos;
			break;
		}
	}
}

// 打印:
void Print_Array(Array* arr) {
	if (arr == NULL) {
		return;
	}

	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");
}

// 释放内存:
void FreeSpace_Array(Array* arr) {
	if (arr == NULL) {
		return;
	}

	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}
	free(arr);
}

// 清空数据:
void Clean_Array(Array* arr) {
	if (arr == NULL) {
		return;
	}

	arr->size = 0;
}

// 获取大小:
int Capacity_Array(Array* arr) {
	if (arr == NULL) {
		return -1;
	}

	return arr->capacity;
}

// 获取当前元素个数:
int Size_Array(Array* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->size;
}

// 根据位置获得某个元素:
int At_Array(Array* arr, int pos) {
	return arr->pAddr[pos];
}
