// ���Ա�22��

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
int Insert(LinkList *lst, ElemType dat)
{
	if(lst == NULL) {
		return FALSE;
	}
	LinkList *prev = lst;
	lst = lst->next;
	while(lst != NULL) {	// ����ҵ����һ���ڵ���û�б�dat��ģ���������һ���ڵ�prev֮��
		if(dat < lst->dat) {
			break;			// �ҵ��Ȳ���datֵ��Ľڵ㣬����ѭ��
		}
		prev = lst;
		lst = lst->next;
	}
	// ��ʱ���µĽڵ���뵽prev��lst֮�伴��
	LinkList *New = new LinkList;
	New->dat = dat;
	New->next = lst;
	prev->next = New;
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
	int num[] = {1,3,5,6,7,8,9,15,20,21};
	LinkList *L = List_InitRear(num, 10);	// ������num��ʼ��һ������
	PrintAll(L);							// ��ӡ��������Ԫ��
	// ����һЩԪ�أ����������ֵ
	cout << Insert(NULL, 1) << endl;		// �쳣�������
	cout << Insert(L, 0) << endl;			// �����������
	cout << Insert(L, 2) << endl;
	cout << Insert(L, 5) << endl;
	cout << Insert(L, 13) << endl;
	cout << Insert(L, 21) << endl;
	cout << Insert(L, 25) << endl;
	PrintAll(L);							// ��ӡ��������Ԫ��
	system("pause");
	return 0;
}

