#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

// 链表指针:
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;


// 链表节点:
typedef struct LINKLIST {
	LinkNode head;
	int size;
}LinkList;

// 遍历函数指针:
typedef void(*PRINTNODE)(LinkNode*);

// 比较函数指针:
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// 初始化链表:
LinkList* Init_LinkList();

// 插入节点:
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

// 删除节点:
void Remove_LinkList(LinkList* list, int pos);

// 查找节点:
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

// 返回链表的大小:
int Size_LinkList(LinkList* list);

// 打印链表:
void Print_LinkList(LinkList* list, PRINTNODE print);

// 释放链表内存:
void FreeSpace_LinkList(LinkList* list);

#endif // !LINKLIST_H
