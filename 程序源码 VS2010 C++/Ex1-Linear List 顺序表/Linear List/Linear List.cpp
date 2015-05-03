#include "StdAfx.h"
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

// 初始化
int List_Init(SqList *sq)
{
	sq->lenth = 0;
	return TRUE;
}

// 在指定位置插入元素
int List_Insert(SqList *sq, int pos, ElemType dat)
{
	int i;
	if((sq->lenth == MAX_SIZE) || (pos > sq->lenth) || (pos < 0)) {
		return FALSE;
	}
	for(i = sq->lenth; i > pos; --i) {
		sq->dat[i] = sq->dat[i - 1];
	}
	sq->dat[pos] = dat;
	++(sq->lenth);
	return TRUE;
}

// 删除指定位置元素
int List_Delete(SqList *sq, int pos)
{
	int i;
	if((pos >= sq->lenth) || (pos < 0)) {
		return FALSE;
	}
	--(sq->lenth);
	for(i = pos; i < sq->lenth; ++i) {
		sq->dat[i] = sq->dat[i + 1];
	}
	return TRUE;
}

// 获取元素所在位置
int List_Locate(SqList *sq, ElemType dat)
{
	int i;
	for(i = 0; i < sq->lenth; ++i) {
		if(sq->dat[i] == dat) {
			return i;
		}
	}
	return FALSE;
}

// 获取指定位置元素
int List_Get(SqList *sq, int pos, ElemType *e)
{
	int i;
	if((pos >= sq->lenth) || (pos < 0)) {
		return FALSE;
	}
	*e = sq->dat[pos];
	return TRUE;
}

int main(void)
{
	SqList Sq;
	List_Init(&Sq);

	cout << "\nInsert Test\n" << endl;
	cout << List_Insert(&Sq, 1, 10) << endl;	// false
	cout << List_Insert(&Sq, 0, 20) << endl;	// true : 20
	cout << List_Insert(&Sq, 0, 15) << endl;	// true : 15 20
	
	cout << "\nLocate Test\n" << endl;
	cout << List_Locate(&Sq, 25) << endl;		// false
	cout << List_Locate(&Sq, 15) << endl;		// 0
	
	ElemType e;
	cout << "\nGet Test\n" << endl;
	cout << List_Get(&Sq, 2, &e) << endl;		// false
	cout << List_Get(&Sq, 1, &e) << endl;		// true
	cout << e << endl;							// 20
	
	cout << "\nDelete Test\n" << endl;
	cout << List_Delete(&Sq, 2) << endl;		// false
	cout << List_Delete(&Sq, 1) << endl;		// true : 15

	system("pause");
	return 0;
}

