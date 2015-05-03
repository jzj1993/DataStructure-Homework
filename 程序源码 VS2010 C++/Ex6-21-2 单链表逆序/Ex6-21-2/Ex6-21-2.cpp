// 第六章21题 单链表

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

// 逆置
int Reverse(LinkList *head)
{
	if(head == NULL) {
		return FALSE;
	}
	if((head->next == NULL) || (head->next->next == NULL)) {	// 只有0个或1个节点，直接退出
		return TRUE;
	}
	LinkList *prev = head->next, *cur = prev->next;
	prev->next = NULL;				// 第一个节点变为最后一个节点，next指针改为NULL
	while(cur != NULL) {
		LinkList *t = cur->next;	
		cur->next = prev;			// 反转prev和cur节点指向，由prev->cur变为cur->prev

		prev = cur;
		cur = t;
	}
	head->next = prev;				// 头指针指向最后一个节点
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
	int num[] = {0,1,2,3,4,5,6,7,8,9};
	LinkList *List = List_InitRear(num, 10);
	PrintAll(List);
	cout << Reverse(List) << endl;
	PrintAll(List);
	system("pause");
	return 0;
}

