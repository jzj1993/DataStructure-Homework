
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

// ͷ�巨��������
LinkList *List_InitFront(ElemType dat[], int n)
{
	int i;
	if(dat == NULL) {
		return List_InitEmpty();
	}
	LinkList *head, *New, *Last = NULL;
	for(i = n - 1; i >= 0; --i) {
		New = new LinkList;
		assert(New != NULL);
		New->dat = dat[i];
		New->next = Last;
		Last = New;
	}
	head = new LinkList;
	assert(head != NULL);
	head->next = Last;
	return head;
}

// ��ֵ����
LinkList *List_Locate(LinkList *lst, ElemType dat)
{
	while(lst != NULL) {
		if(lst->dat == dat) {
			return lst;
		}
		lst = lst->next;
	}
	return NULL;
}

// ����Ų���
LinkList *List_Get(LinkList *lst, int pos)
{
	int i = -1;			// ��-1��ʾͷ���λ��
	if((lst == NULL) || (pos < 0)) {
		return NULL;
	}
	while(lst != NULL) {
		if(i == pos) {
			return lst;
		}
		++i;
		lst = lst->next;
	}
	return NULL;
}

// ��ָ��λ�ú������
int List_InsertAfter(LinkList *lst, int pos, ElemType dat)
{
	LinkList *n, *New;
	if((n = List_Get(lst, pos)) != NULL) {
		New = new LinkList;
		New->dat = dat;
		New->next = n->next;
		n->next = New;
		return TRUE;
	}
	return FALSE;
}

// ��ָ��λ��ǰ������
int List_InsertBefore(LinkList *lst, int pos, ElemType dat)
{
	LinkList *New;
	if(pos < 0) {
		return FALSE;
	}
	if(pos > 0) {
		lst = List_Get(lst, pos - 1);
	}
	// ��ʱlstΪ��pos-1���ڵ� (pos = 0ʱ��lstΪͷ���)
	if((lst != NULL) && (lst->next != NULL)) {
		New = new LinkList;
		New->dat = dat;
		New->next = lst->next;
		lst->next = New;
		return TRUE;
	}
	return FALSE;
}

// ɾ����̽��
int List_DeleteAfter(LinkList *node)
{
	if((node != NULL) && (node->next != NULL)) {
		LinkList *d = node->next;
		node->next = node->next->next;
		delete d;
		return TRUE;
	}
	return FALSE;
}

// ɾ����i�����
int List_Delete(LinkList *lst, int pos)
{
	if(pos < 0) {
		return FALSE;
	}
	if(pos > 0) {
		lst = List_Get(lst, pos - 1);
	}
	// ��ʱlstΪ��pos-1���ڵ� (pos = 0ʱ��lstΪͷ���)
	return List_DeleteAfter(lst);
}

// ���ڲ��� ����ֵΪLinkList�͵ĺ��� ִ�н��
void Test(LinkList *lst)
{
	if(lst == NULL) {
		cout << "NULL" << endl;
	} else {
		cout << lst->dat << endl;
	}
}

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

// ���ڲ��� ����ֵΪBool�͵ĺ��� ִ�н��
void TestBoolean(LinkList *lst, int b)
{
	if(b == TRUE) {
		cout << "TRUE :   ";
		PrintAll(lst);
	} else if(b == FALSE) {
		cout << "FALSE" << endl;
	}
}

int main(void)
{
	int num[] = {0,10,20,30};
	LinkList *List = List_InitRear(num, 3);			// 0 10 20
	PrintAll(List);
	LinkList *List2 = List_InitFront(num, 4);
	PrintAll(List2);

	cout << "\nLocate Test\n" << endl;
	Test(List_Locate(List, 20));					// 20
	Test(List_Locate(List, 30));					// NULL

	cout << "\nGet Test\n" << endl;
	Test(List_Get(List, 2));						// 20
	Test(List_Get(List, 3));						// NULL

	cout << "\nInsertAfter Test\n" << endl;
	TestBoolean(List, List_InsertAfter(List, 3, 300));			// flase
	TestBoolean(List, List_InsertAfter(List, 2, 200));			// true : 0 10 20 200
	TestBoolean(List, List_InsertAfter(List, 1, 100));			// true : 0 10 100 20 200

	cout << "\nDelete Test\n" << endl;
	TestBoolean(List, List_Delete(List, 4));					// true : 0 10 100 20
	TestBoolean(List, List_Delete(List, 4));					// false

	cout << "\nDeleteAfter Test\n" << endl;
	TestBoolean(List, List_DeleteAfter(List_Locate(List, 10)));	// true : 0 10 20
	TestBoolean(List, List_DeleteAfter(List_Locate(List, 20)));	// false
	
	cout << "\nInsertBefore Test\n" << endl;
	TestBoolean(List, List_InsertBefore(List, 3, 300));			// flase
	TestBoolean(List, List_InsertBefore(List, 2, 200));			// true : 0 10 200 20
	TestBoolean(List, List_InsertBefore(List, 0, 100));			// true : 100 0 10 200 20
	
	system("pause");
	return 0;
}

