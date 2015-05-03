// µÚÁùÕÂ21Ìâ Ë³Ðò±í

#include "stdafx.h"

#include <iostream>
using namespace std;

#define MAX_SIZE   100
#define TRUE        1
#define FALSE      -1

typedef int ElemType;

typedef struct
{
	ElemType dat[MAX_SIZE];
	int lenth;
} SqList;

void Reverse(SqList *lst)
{
	for(int i = 0; i < lst->lenth/2; ++i) {
		ElemType t = lst->dat[i];
		lst->dat[i] = lst->dat[lst->lenth - i - 1];
		lst->dat[lst->lenth - i - 1] = t;
	}
}

SqList *ListInit(ElemType *dat, int n)
{
	if((dat == NULL) || (n < 0) || (n > MAX_SIZE)) {
		return NULL;
	}
	SqList *sq = new SqList;
	for(int i = 0; i < n; ++i) {
		sq->dat[i] = dat[i];
	}
	sq->lenth = n;
	return sq;
}

void PrintAll(SqList *sq)
{
	for(int i = 0; i < sq->lenth; ++i) {
		cout << sq->dat[i] <<" ";
	}
	cout << endl;
}

int main(void)
{
	int d[] = {0,1,2,3,4,5};
	SqList *sq = ListInit(d, 6);
	PrintAll(sq);
	Reverse(sq);
	PrintAll(sq);

	SqList *sq2 = ListInit(d, 5);
	PrintAll(sq2);
	Reverse(sq2);
	PrintAll(sq2);
	system("pause");
	return 0;
}

