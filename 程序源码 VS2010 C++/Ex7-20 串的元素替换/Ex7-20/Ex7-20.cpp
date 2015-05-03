// �������� ��20��

#include "stdafx.h"
#include <assert.h>
#include <iostream>
using namespace std;

#define TRUE        1
#define FALSE      -1

typedef char ElemType;

typedef struct LinkList
{
	ElemType dat;
	LinkList *next;
} LinkList;

typedef LinkList *SqString;

// ����������
LinkList *List_InitEmpty(void)
{
	LinkList *head = new LinkList;
	assert(head != NULL);
	head->next = NULL;
	return head;
}

// β�巨��������
LinkList *List_InitRear(ElemType *dat, int n)
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

// ���ĳ�ʼ��
SqString SqStringInit(ElemType *s)
{
	int n = 0;
	ElemType *p = s;
	while(*p++) {
		++n;
	}
	return List_InitRear(s, n);
}

// �滻ָ��Ԫ��
int Replace(SqString lst, ElemType src, ElemType dst)
{
	if(lst == NULL) {
		return FALSE;
	}
	while(lst != NULL) {
		if(lst->dat == src) {
			lst->dat = dst;
		}
		lst = lst->next;
	}
	return TRUE;
}

// ���ȫ��Ԫ��
void PrintAll(LinkList *lst)
{
	if(lst == NULL) {
		return;
	}
	lst = lst->next;
	while(lst != NULL) {
		cout << lst->dat;
		lst = lst->next;
	}
	cout << endl;
}

int main(void)
{
	ElemType *str = "TectTectTect";
	SqString s = SqStringInit(str);				// ��ʼ����
	PrintAll(s);
	cout << Replace(NULL, 'c', 's') << endl;	// �쳣���������FALSE=-1
	cout << Replace(s, 'c', 's') << endl;		// ����������滻�ַ�������TRUE=1
	PrintAll(s);
	
	system("pause");
	return 0;
}

