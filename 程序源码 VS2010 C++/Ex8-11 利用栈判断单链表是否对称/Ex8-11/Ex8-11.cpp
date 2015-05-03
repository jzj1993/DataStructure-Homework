// �ڰ���11��

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

#define STACK_MAX_SIZE  100

typedef struct Stack {
	ElemType dat[STACK_MAX_SIZE];
	int size;
} Stack;

// ����ջ
Stack *Stack_Create(void)
{
	Stack *s = new Stack;
	s->size = 0;
	return s;
}

// ��ջ
int Stack_Push(Stack *s, ElemType dat)
{
	if((s == NULL) || (s->size == STACK_MAX_SIZE)) {
		return FALSE;
	}
	s->dat[(s->size)++] = dat;
	return TRUE;
}

// ��ջ
ElemType Stack_Pop(Stack *s)
{
	if((s == NULL) || (s->size == 0)) {
		return NULL;
	}
	return s->dat[--(s->size)];
}

// �ж��Ƿ�Գƣ���lst�ĳ���Ϊn����lst�Գ�ʱ����TRUE�����򷵻�FALSE
int IsSymmetrical(LinkList *lst, int n)
{
	Stack *s = Stack_Create();
	if((lst == NULL) || (n < 1)) {
		return FALSE;
	}
	lst = lst->next;							// lst: ��0��Ԫ��
	for(int i = 0; i < n/2; ++i) {
		Stack_Push(s, lst->dat);
		lst = lst->next;	
		if(lst == NULL) {
			return FALSE;			// ����n�д�n > lenth
		}
	}
	if(n % 2) {
		lst = lst->next;				// nΪ���������������м���ַ����˾�ִ��ǰlst != NULL
	}
	ElemType e;
	for(int i = 0; i < n/2 + 1; ++i) {
		e = Stack_Pop(s);
		if((lst == NULL) && (e == NULL)) {			// ����lst�ķ��ʺͳ�ջͬʱ��ɣ�˵���պñ�������������
			return TRUE;
		} else if((lst == NULL) || (e == NULL)) {	// �������ͬʱ��ɣ�˵������n��ֵ�д�
			return FALSE;
		}
		if(lst->dat != e) {							// �����ַ������Գ�
			return FALSE;
		}
		lst = lst->next;
	}
	return FALSE;
}

// ������нڵ�
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
	char c[] = "Test_tseT";
	LinkList *lst = List_InitRear(c, 9);
	PrintAll(lst);
	cout << IsSymmetrical(lst, 10) << endl;		// ����n��ֵ����ȷ������FALSE
	cout << IsSymmetrical(lst, 9) << endl;		// ����ִ�У�����TRUE
	
	char c2[] = "Test_tseT_";
	LinkList *lst2 = List_InitRear(c2, 10);
	PrintAll(lst2);
	cout << IsSymmetrical(lst2, 9) << endl;		// ����n��ֵ����ȷ������FALSE
	cout << IsSymmetrical(lst2, 10) << endl;	// ����ִ�У�����FALSE

	system("pause");
	return 0;
}
