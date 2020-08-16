
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// 动态增长内存

typedef struct DYNAMICARRAY {
	int* pAddr;  //数据地址
	int size;  //元素大小
	int capacity;  //容量
}Array;

// 初始化:
Array* Init_Array();

// 插入:
void Push_Back_Array(Array* arr, int value);

// 下标删除:
void RemoveByPos_Array(Array* arr, int pos);

// 值删除:
void RemoveByValue_Array(Array* arr, int value);

// 查找:
int FindSpace_Array(Array* arr, int value);

// 打印:
void Print_Array(Array* arr);

// 释放内存:
void FreeSpace_Array(Array* arr);

// 清空数据:
void Clean_Array(Array* arr);

// 获取大小:
int Capacity_Array(Array* arr);

// 获取当前元素个数:
int Size_Array(Array* arr);

// 根据位置获得某个元素:
int At_Array(Array* arr, int pos);

#endif // !DYNAMIC_ARRAY_H



