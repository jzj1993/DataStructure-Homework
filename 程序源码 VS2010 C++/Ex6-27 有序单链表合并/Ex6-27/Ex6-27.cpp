// ������27��

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

// ������������ ����ڵ�
int Insert(LinkList *lst, LinkList *New)
{
	if(lst == NULL) {
		return FALSE;
	}
	LinkList *prev = lst;
	lst = lst->next;
	while(lst != NULL) {	// ����ҵ����һ���ڵ���û�б�dat��ģ���������һ���ڵ�prev֮��
		if((New->dat) < (lst->dat)) {
			break;			// �ҵ��Ȳ���datֵ��Ľڵ㣬����ѭ��
		}
		prev = lst;
		lst = lst->next;
	}
	// ��ʱ���µĽڵ���뵽prev��lst֮�伴��
	New->next = lst;
	prev->next = New;
	return TRUE;
}

// �ϲ�������������
LinkList *Merge(LinkList *lst1, LinkList *lst2)
{
	if(lst1 == NULL) {	// lst1 = lst2 = NULL �� lst1 = NULL, lst2 != NULL
		return lst2;
	}
	if(lst2 == NULL) {	// lst1 != NULL, lst2 == NULL
		return lst1;
	}
	// lst1 != NULL, lst2 != NULL
	LinkList *head2 = lst2;
	lst2 = lst2->next;			// ����lst2ͷ�ڵ�
	while(lst2 != NULL) {
		LinkList *t = lst2->next;
		Insert(lst1, lst2);		// ��lst2�Ľڵ��������
		lst2 = t;
	}
	delete head2;
	return lst1;
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

