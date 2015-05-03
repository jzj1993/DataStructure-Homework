// 第六章27题

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
int Insert(LinkList *lst, LinkList *New)
{
	if(lst == NULL) {
		return FALSE;
	}
	LinkList *prev = lst;
	lst = lst->next;
	while(lst != NULL) {	// 如果找到最后一个节点仍没有比dat大的，则插入最后一个节点prev之后
		if((New->dat) < (lst->dat)) {
			break;			// 找到比参数dat值大的节点，跳出循环
		}
		prev = lst;
		lst = lst->next;
	}
	// 此时将新的节点插入到prev和lst之间即可
	New->next = lst;
	prev->next = New;
	return TRUE;
}

// 合并递增有序单链表
LinkList *Merge(LinkList *lst1, LinkList *lst2)
{
	if(lst1 == NULL) {	// lst1 = lst2 = NULL 或 lst1 = NULL, lst2 != NULL
		return lst2;
	}
	if(lst2 == NULL) {	// lst1 != NULL, lst2 == NULL
		return lst1;
	}
	// lst1 != NULL, lst2 != NULL
	LinkList *head2 = lst2;
	lst2 = lst2->next;			// 跳过lst2头节点
	while(lst2 != NULL) {
		LinkList *t = lst2->next;
		Insert(lst1, lst2);		// 将lst2的节点逐个插入
		lst2 = t;
	}
	delete head2;
	return lst1;
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
	int num1[] = {1,3,5,6,7,8,9,15,20,21};
	int num2[] = {0,1,2,7,8,13,21,23,24,25};
	LinkList *A = List_InitRear(num1, 10);
	LinkList *B = List_InitRear(num2, 10);
	PrintAll(A);
	PrintAll(B);
	LinkList *C = Merge(A, B);
	PrintAll(C);
	system("pause");
	return 0;
}

