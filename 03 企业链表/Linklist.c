#include"Linklist.h"


// 初始化链表:
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}

// 插入节点:
void Insert_LinkList(LinkList* list, int pos, LinkNode* data) {
	// 判断链表是否为空:
	if (list == NULL) {
		return;
	}
	// 判断待插入数据是否为空
	if (data == NULL) {
		return;
	}
	// 判断插入位置是否合法:
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}

	// 查找插入位置: [指针只能存储 地址编号, list->head 并不是指针, 可通过 &(list->head) 取出地址编号]
	LinkNode* p = &(list->head);
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	// 插入新节点:
	data->next = p->next;
	p->next = data;
	list->size++;
}

// 删除节点:
void Remove_LinkList(LinkList* list, int pos) {

}

// 查找节点:
int Find_LinkList(LinkList* list, LinkNode* data) {
	return 0;
}

// 返回链表的大小:
int Size_LinkList(LinkList* list) {
	return 0;
}

// 打印链表:
void Print_LinkList(LinkList* list, PRINTNODE print) {
	if (list == NULL) {
		return;
	}
	// 辅助指针:[指针只能存储 地址编号, list->head 并不是指针, list->head.next 才是地址编号]
	LinkNode* p = list->head.next;
	while (p != NULL) {
		print(p);
		p = p->next;
	}
}

// 释放链表内存:
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}

	free(list);
}
