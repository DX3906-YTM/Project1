#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Linklist.h"


typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data) {
	Person* p = (Person*)data;
	printf("name: %s,  age: %d\n", p->name, p->age);
}

int MyCompare(LinkNode* node1, LinkNode*node2) {
	Person* p1 = node1;
	Person* p2 = node2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
		return 0;
	}
	return -1;
}

int main(void) {
	// 创建链表:
	LinkList* list = Init_LinkList();

	// 创建数据:
	Person p1, p2, p3, p4, p5;

	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;

	// 插入链表:
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	// 打印链表:
	Print_LinkList(list, MyPrint);

	// 删除节点:
	Remove_LinkList(list, 2);

	// 打印链表:
	printf("-------------------\n");
	Print_LinkList(list, MyPrint);

	// 查找节点:
	Person find_1;
	strcpy(find_1.name, "aaa");
	find_1.age = 10;
	int pos = Find_LinkList(list, (LinkNode*)&find_1, MyCompare);
	printf("pos: %d\n", pos);

	// 释放内存:
	FreeSpace_LinkList(list);

	system("pause");
	return 0;
}