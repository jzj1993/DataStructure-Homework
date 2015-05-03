// ������21�� ������

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

// ����������
LinkList *List_InitEmpty(void)
{
	LinkList *head = new LinkList;
	assert(head != NULL);
	head->next = NULL;
	return head;
}

// β�巨��������
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

// ����
int Reverse(LinkList *head)
{
	if(head == NULL) {
		return FALSE;
	}
	if((head->next == NULL) || (head->next->next == NULL)) {	// ֻ��0����1���ڵ㣬ֱ���˳�
		return TRUE;
	}
	LinkList *prev = head->next, *cur = prev->next;
	prev->next = NULL;				// ��һ���ڵ��Ϊ���һ���ڵ㣬nextָ���ΪNULL
	while(cur != NULL) {
		LinkList *t = cur->next;	
		cur->next = prev;			// ��תprev��cur�ڵ�ָ����prev->cur��Ϊcur->prev

		prev = cur;
		cur = t;
	}
	head->next = prev;				// ͷָ��ָ�����һ���ڵ�
	return TRUE;
}

// ������нڵ�
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

