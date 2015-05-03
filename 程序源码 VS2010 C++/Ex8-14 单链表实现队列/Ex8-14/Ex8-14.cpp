// ջ�Ͷ���14��

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

typedef struct Queue
{
	LinkList *list;
	LinkList *rear;
} Queue;

// �����ն���
Queue *QueueCreate(void)
{
	Queue *q = new Queue;
	assert(q != NULL);
	LinkList *head = new LinkList;
	assert(head != NULL);
	head->dat = '#';
	head->next = head;
	q->list = head;
	q->rear = head;
	return q;
}

// ���
int EnQueue(Queue *q, ElemType dat)
{
	if(q == NULL) {
		return FALSE;
	}
	LinkList *New = new LinkList;
	assert(New != NULL);
	New->dat = dat;
	New->next = q->list;			// ��ӵ��½ڵ�Ϊ��βԪ�أ���nextָ��ָ��ͷ���
	q->rear->next = New;			// ԭ�ȵĶ�βԪ��nextָ��ָ���½ڵ�
	q->rear = New;				// ���е�βָ��ָ���½ڵ�
	return TRUE;
}

// ����
int DeQueue(Queue *q, ElemType *dat)
{
	if((q == NULL) || (q->list == NULL) || (q->list == q->rear)) {
		return FALSE;				// ����ָ��Ϊ�� / ��������Ϊ�� / ����Ϊ��(������ֻ��ͷ���)���򷵻�FALSE
	}
	LinkList *lst = q->list->next;	// ��ͷԪ��
	*dat = lst->dat;
	q->list->next = lst->next;		// ����ͷ���nextָ��ָ���µĶ�ͷԪ��
	if(q->rear == lst) {				// ��ͷ�Ͷ�β��ͬ��˵��ֻ��һ��Ԫ��
		q->rear = q->list;			// ���Ӻ󣬶���Ϊ�գ�βָ��ָ������ͷ���
	}
	delete lst;						// �����ڴ�
	return TRUE;
}

// ��ն���
int QueueClear(Queue *q)
{
	if(q == NULL) {
		return FALSE;
	}
	ElemType dat;
	while(DeQueue(q, &dat) == TRUE);
	return TRUE;
}

int main(void)
{
	Queue *q = QueueCreate();

	// ��Ӻ�������
	cout << "��Ӻ�������" << endl;
	cout << EnQueue(NULL, ' ') << endl;	// �쳣���
	
	for(int i = 0; i < 3; ++i) {		// ���������'0','1','2'�������
		cout << EnQueue(q, i + '0') << endl;
	}
	
	// ���Ӻ�������
	ElemType e;
	cout << "���Ӻ�������" << endl;
	cout << DeQueue(NULL, &e) << endl;	// �쳣���

	for(int i = 0; i < 4; ++i) {
		if(DeQueue(q, &e) == TRUE) {
			cout << e << " ";			// ���������'0','1','2'���γ��ӣ��������Ԫ��
		} else {
			cout << "NULL ";			// �߽����������Ϊ�գ����"NULL"
		}
	}
	cout << endl;
	
	// �ÿնӺ�������
	cout << "�ÿնӺ�������" << endl;
	cout << QueueClear(NULL) << endl;	// �쳣���

	for(int i = 0; i < 3; ++i) {
		EnQueue(q, i + '0');
	}
	cout << QueueClear(q) << endl;		// ����������ÿն�
	cout << DeQueue(q, &e) << endl;		// ��ʱ����Ϊ�գ����ӷ���FALSE=-1

	system("pause");
	return 0;
}

