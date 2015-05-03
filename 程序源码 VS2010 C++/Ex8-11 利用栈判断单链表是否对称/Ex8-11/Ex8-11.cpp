// 第八章11题

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

#define STACK_MAX_SIZE  100

typedef struct Stack {
	ElemType dat[STACK_MAX_SIZE];
	int size;
} Stack;

// 创建栈
Stack *Stack_Create(void)
{
	Stack *s = new Stack;
	s->size = 0;
	return s;
}

// 入栈
int Stack_Push(Stack *s, ElemType dat)
{
	if((s == NULL) || (s->size == STACK_MAX_SIZE)) {
		return FALSE;
	}
	s->dat[(s->size)++] = dat;
	return TRUE;
}

// 出栈
ElemType Stack_Pop(Stack *s)
{
	if((s == NULL) || (s->size == 0)) {
		return NULL;
	}
	return s->dat[--(s->size)];
}

// 判断是否对称：当lst的长度为n、且lst对称时返回TRUE，否则返回FALSE
int IsSymmetrical(LinkList *lst, int n)
{
	Stack *s = Stack_Create();
	if((lst == NULL) || (n < 1)) {
		return FALSE;
	}
	lst = lst->next;							// lst: 第0个元素
	for(int i = 0; i < n/2; ++i) {
		Stack_Push(s, lst->dat);
		lst = lst->next;	
		if(lst == NULL) {
			return FALSE;			// 参数n有错：n > lenth
		}
	}
	if(n % 2) {
		lst = lst->next;				// n为奇数，则跳过正中间的字符，此句执行前lst != NULL
	}
	ElemType e;
	for(int i = 0; i < n/2 + 1; ++i) {
		e = Stack_Pop(s);
		if((lst == NULL) && (e == NULL)) {			// 当对lst的访问和出栈同时完成，说明刚好遍历完整个链表
			return TRUE;
		} else if((lst == NULL) || (e == NULL)) {	// 如果不是同时完成，说明参数n的值有错
			return FALSE;
		}
		if(lst->dat != e) {							// 链表字符串不对称
			return FALSE;
		}
		lst = lst->next;
	}
	return FALSE;
}

// 输出所有节点
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
	cout << IsSymmetrical(lst, 10) << endl;		// 参数n的值不正确，返回FALSE
	cout << IsSymmetrical(lst, 9) << endl;		// 正常执行，返回TRUE
	
	char c2[] = "Test_tseT_";
	LinkList *lst2 = List_InitRear(c2, 10);
	PrintAll(lst2);
	cout << IsSymmetrical(lst2, 9) << endl;		// 参数n的值不正确，返回FALSE
	cout << IsSymmetrical(lst2, 10) << endl;	// 正常执行，返回FALSE

	system("pause");
	return 0;
}
