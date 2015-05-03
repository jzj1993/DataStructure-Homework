// 线性表22题

#include "stdafx.h"
#include <assert.h>
#include <iostream>
using namespace std;

#define TRUE        1
#define FALSE      -1

typedef int ElemType;

typedef struct LinkList
{
	ElemType dat;
	LinkList *next;
} LinkList;

// 创建空链表
LinkList *List_InitEmpty(void)
{
	LinkList *head = new LinkList;
	assert(head != NULL);
	head->next = NULL;
	return head;
}

// 尾插法创建链表
LinkList *List_InitRear(ElemType dat[], int n)
{
	int i;
	if(dat == NULL) {
		return List_InitEmpty();
	}
	LinkList *head = new LinkList, *New, *Last;
	assert(head != NULL);
	Last = head;
	for(i = 0; i < n; ++i) {
		Last->next = New = new LinkList;
		assert(New != NULL);
		New->dat = dat[i];
		Last = New;
	}
	Last->next = NULL;
	return head;
}

// 递增有序单链表 插入节点
int Insert(LinkList *lst, ElemType dat)
{
	if(lst == NULL) {
		return FALSE;
	}
	LinkList *prev = lst;
	lst = lst->next;
	while(lst != NULL) {	// 如果找到最后一个节点仍没有比dat大的，则插入最后一个节点prev之后
		if(dat < lst->dat) {
			break;			// 找到比参数dat值大的节点，跳出循环
		}
		prev = lst;
		lst = lst->next;
	}
	// 此时将新的节点插入到prev和lst之间即可
	LinkList *New = new LinkList;
	New->dat = dat;
	New->next = lst;
	prev->next = New;
	return TRUE;
}

// 输出所有节点
void PrintAll(LinkList *lst)
{
	if(lst == NULL) {
		return;
	}
	lst = lst->next;
	while(lst != NULL) {
		cout << lst->dat << " ";
		lst = lst->next;
	}
	cout << endl;
}

int main(void)
{
	int num[] = {1,3,5,6,7,8,9,15,20,21};
	LinkList *L = List_InitRear(num, 10);	// 用数组num初始化一个链表
	PrintAll(L);							// 打印链表所有元素
	// 插入一些元素，并输出返回值
	cout << Insert(NULL, 1) << endl;		// 异常情况测试
	cout << Insert(L, 0) << endl;			// 正常情况测试
	cout << Insert(L, 2) << endl;
	cout << Insert(L, 5) << endl;
	cout << Insert(L, 13) << endl;
	cout << Insert(L, 21) << endl;
	cout << Insert(L, 25) << endl;
	PrintAll(L);							// 打印链表所有元素
	system("pause");
	return 0;
}

