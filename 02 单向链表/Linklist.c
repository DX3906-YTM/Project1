#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>


// 初始化链表:
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	// 头节点:
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

// 指定位置插入:
void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	// pos 越界, 默认插入到尾部:
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}
	// 创建节点:
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;
	// 定位插入位置:
	LinkNode* p = list->head;
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	// 开始插入:
	newnode->next = p->next;
	p->next = newnode;

	list->size++;
}

// 删除指定位置的值:
void RemoveByPos_LinkList(LinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	// pos 越界:
	if (pos < 0 || pos >= list->size) {
		return;
	}
	// 查找删除节点前的一个节点:
	LinkNode* p = list->head;
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	//缓存删除的节点:
	LinkNode* pDel = p->next;
	p->next = pDel->next;
	// 释放被删除节点的内存:
	free(pDel);
	list->size--;
}

// 获得链表长度:
int Size_LinkList(LinkList* list) {
	return list->size;
}

// 查找:
int Find_LinList(LinkList* list, void* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	LinkNode* p = list->head->next;
	int i = 0;
	while (p != NULL) {
		if (p->data == data) {
			break;
		}
		i++;
		p = p->next;
	}
	return i;
}

// 打印链表节点:
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
	if (list == NULL) {
		return;
	}
	LinkNode* p = list->head->next;
	while (p != NULL) {
		print(p->data);
		p = p->next;
	}
}

// 返回第一个节点:
void* Front_LinkList(LinkList* list) {
	return list->head->next->data;
}

// 释放链表内存:
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	LinkNode* p = list->head;
	while (p != NULL) {
		// 缓存下一节点:
		LinkNode* pNext = p->next;
		free(p);
		p = pNext;
	}

	// 释放链表内存:
	list->size = 0;
	free(list);
}
