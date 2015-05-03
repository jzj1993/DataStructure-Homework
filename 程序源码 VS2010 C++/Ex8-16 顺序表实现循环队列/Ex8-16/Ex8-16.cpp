// µÚ°ËÕÂ16Ìâ

#include "stdafx.h"
#include <assert.h>
#include <iostream>
using namespace std;

#define TRUE        1
#define FALSE      -1

#define MAX_SIZE   20

typedef int ElemType;

typedef struct Queue
{
	int rear;
	int quelen;
	ElemType sequ[MAX_SIZE];
} Queue;

Queue *Queue_Create(void)
{
	Queue *q = new Queue;
	assert(q != NULL);
	q->rear = 0;
	q->quelen = 0;
	return q;
}

int EnQueue(Queue *q, ElemType dat)
{
	if((q == NULL) || (q->quelen == MAX_SIZE)) {
		return FALSE;
	}
	q->sequ[q->rear] = dat;
	++q->quelen;
	q->rear = (q->rear + 1) % MAX_SIZE;
	return TRUE;
}

int DeQueue(Queue *q, ElemType *dat)
{
	if((q == NULL) || (q->quelen == 0)) {
		return FALSE;
	}
	*dat = q->sequ[(q->rear + MAX_SIZE - q->quelen) % MAX_SIZE];
	--q->quelen;
	return TRUE;
}

int main(void)
{
	Queue *q = Queue_Create();
	for(int i = 0; i < 25; ++i) {
		EnQueue(q, i);
	}
	
	ElemType e;
	for(int i = 0; i < 25; ++i) {
		if(DeQueue(q, &e) == TRUE) {
			cout << e << " ";
		} else {
			cout << "NULL ";
		}
	}
	cout << endl;

	system("pause");
	return 0;
}



