#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Linklist.h"


void test01() {

	// 初始化动态数组
	Array* myArray = Init_Array();

	// 打印容量:
	printf("Arrat size: %d\n", Capacity_Array(myArray));
	printf("Number of elements: %d\n", Size_Array(myArray));

	// 插入元素:
	for (int i = 0; i < 30; i++) {
		Push_Back_Array(myArray, i);
	}

	// 打印:
	Print_Array(myArray);

	// 删除元素:
	RemoveByPos_Array(myArray, 0);
	RemoveByValue_Array(myArray, 27);
	RemoveByValue_Array(myArray, 15);

	// 打印:
	printf("**************************************************\n");
	Print_Array(myArray);

	// 查询:
	int pos = 0;

	pos = FindSpace_Array(myArray, 5);
	printf("%d\n", pos);


	// 打印容量:
	printf("Arrat size: %d\n", Capacity_Array(myArray));
	printf("Number of elements: %d\n", Size_Array(myArray));

	// 销毁:
	FreeSpace_Array(myArray);
}



#include<stdio.h>
#include<stdlib.h>
int main() {

	test01();

	system("pause");
	return 0;
}
