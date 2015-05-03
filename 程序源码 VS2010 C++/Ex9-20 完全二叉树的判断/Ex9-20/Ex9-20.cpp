// ����20��

#include "stdafx.h"
#include <assert.h>
#include <iostream>
using namespace std;

#define TRUE        1
#define FALSE       -1

///////////////////////////////////////////////////
// ���Ա�ʵ�ֵĶ��У�Ԫ������ΪElemType�ͣ��������Ĵ���ʱ����������

typedef char ElemType;

#define QUEUE_CHAR_SIZE  20

typedef struct QueueChar {
	ElemType dat[QUEUE_CHAR_SIZE];
	int front, rear, size;
} QueueChar;

int EnQueueC(QueueChar *q, char c);

// ���ַ����鴴������
QueueChar *CreateQueueC(ElemType *s)
{
	QueueChar *q = new QueueChar;
	assert(q != NULL);
	q->front = q->rear = q->size = 0;
	while(*s) {
		EnQueueC(q, *s++);
	}
	return q;
}

// ���
int EnQueueC(QueueChar *q, ElemType c)
{
	if(q == NULL || q->size == QUEUE_CHAR_SIZE) {
		return FALSE;
	}
	q->dat[q->rear] = c;
	++q->size;
	q->rear = (q->rear + 1) % QUEUE_CHAR_SIZE;
	return TRUE;
}

// ����
int DeQueueC(QueueChar *q, ElemType *c)
{
	if(q == NULL || q->size == 0) {
		return FALSE;
	}
	*c = q->dat[q->front];
	--q->size;
	q->front = (q->front + 1) % QUEUE_CHAR_SIZE;
	return TRUE;
}

// �ж��Ƿ�Ϊ��
int QueueEmptyC(QueueChar *q)
{
	if(q == NULL || q->size == 0) {
		return TRUE;
	}
	return FALSE;
}

///////////////////////////////////////////////////
// ����ʵ�ֵĶ��У�Ԫ������ΪBiTree�ͣ������ж��Ƿ�Ϊ��ȫ��ʱ�Ĳ������

typedef struct BiNode {
	ElemType dat;
	BiNode *lchild;
	BiNode *rchild;
} BiNode, *BiTree;

typedef struct LinkList
{
	BiTree dat;
	LinkList *next;
} LinkList;

typedef struct Queue
{
	LinkList *list;
	LinkList *rear;
} Queue;

// �����ն���
Queue *CreateQueue(void)
{
	Queue *q = new Queue;
	assert(q != NULL);
	LinkList *head = new LinkList;
	assert(head != NULL);
	head->next = head;
	q->list = head;
	q->rear = head;
	return q;
}

// ���
int EnQueue(Queue *q, BiTree dat)
{
	if(q == NULL) {
		return FALSE;
	}
	LinkList *New = new LinkList;
	New->dat = dat;
	New->next = q->list;
	q->rear->next = New;	
	q->rear = New;
	return TRUE;
}

// ����
int DeQueue(Queue *q, BiTree *dat)
{
	if((q == NULL) || (q->list == NULL) || (q->list == q->rear)) {
		return FALSE;				// ����Ϊ�� / ��������Ϊ�� / ������ֻ��ͷ��㣬�򷵻�FALSE
	}
	LinkList *lst = q->list->next;	// ��ͷ
	*dat = lst->dat;
	q->list->next = lst->next;		// ͷ���ָ��ָ����һ���ڵ�
	if(q->rear == lst) {				// ��ͷ�Ͷ�β��ͬ��˵��ֻ��һ��Ԫ��
		q->rear = q->list;			// ���Ӻ󣬶���Ϊ�գ�βָ��ָ��head
	}
	delete lst;
	return TRUE;
}

// �ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue *q)
{
	if((q == NULL) || (q->list == NULL) || (q->list == q->rear)) {
		return TRUE;
	}
	return FALSE;
}

//////////////////////////////////////////////////////////////

// ǰ�������ʽ���������� �ݹ麯��
BiTree &CreateBiTree(BiTree &t, QueueChar *q)
{
	ElemType e;
	if(DeQueueC(q, &e) == FALSE || e == '#') {
		t = NULL;
	} else {
		t = new BiNode;
		assert(t != NULL);
		t->dat = e;
		t->lchild = CreateBiTree(t->lchild, q);
		t->rchild = CreateBiTree(t->rchild, q);
	}
	return t;
}

// �ж϶������Ƿ�Ϊ��ȫ������ Full Binary Tree�����ò��������
int IsFBT(BiTree t)
{
	if(t == NULL) {
		return FALSE;
	}
	Queue *q = CreateQueue();
	EnQueue(q, t);
	while(QueueEmpty(q) == FALSE) {
		DeQueue(q, &t);
		if(t != NULL) {
			EnQueue(q, t->lchild);		// ����ӽڵ�Ϊ�գ��սڵ�NULL���
			EnQueue(q, t->rchild);
		} else {		// �Ѿ����ʵ���һ���սڵ㣬�������ȫ�����������滹δ���ʵĽڵ㶼�ǿսڵ�
			while(DeQueue(q, &t) == TRUE) {
				if(t != NULL) {
					return FALSE;
				}
			}
			return TRUE;
		}
	}
	return TRUE;
}

int main(void)
{
	/*
	// ----------------1----------------
	        A
	    B       C
	  D   E   F   G
	 # # # # # # # #
	 
	// ----------------2----------------
	        A
	    B       C
	  D   E   #   #
	 # # # #
	 
	// ----------------3----------------
	        A
	    B       C
	  D   #   E   #
	 # #     # #

	// ----------------4----------------
	        A
	    B       #
	  D   E
	 # # # #

	// ----------------5----------------
	        A
	    B       C
	  #   D   #   #
	     # #
		 
	// ----------------5----------------
	*/
	
	ElemType c1[] = "ABD##E##CF##G##";
	ElemType c2[] = "ABD##E##C##";
	ElemType c3[] = "ABD###CE###";
	ElemType c4[] = "ABD##E###";
	ElemType c5[] = "AB#D##C##";
	ElemType *p[] = {c1, c2, c3, c4, c5};

	cout << IsFBT(NULL) << endl;	// �쳣���

	for(int i = 0; i < 5; ++i) {	// ����������ж��������ֶ������Ƿ�Ϊ��ȫ������
		BiTree t = CreateBiTree(t, CreateQueueC(p[i]));
		cout << IsFBT(t) << endl;
	}
	
	system("pause");
	return 0;
}

