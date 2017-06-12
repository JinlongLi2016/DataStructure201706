#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef int ElemType;
// typedef struct alist *SqList;
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

/* 在这样的情况下 不(能)在 SqList 前面加 struct
 因为 typedef 的存在, what's the deep reason? */
SqList *CreateList(ElemType a[], int n)
{
	int i;
	SqList *a_sqlist;
	a_sqlist = (SqList *)malloc(sizeof( SqList));
	for(i=0; i<n; i++)
		a_sqlist->data[i] = a[i];
	return a_sqlist;
}
/*  如果使用
 	struct SqList{
 	ElemType data[MaxSize];
 	int length;
 	};
	形式的结构体 without using 'typedef'
	那么 CreateList 应该这样改:
	struct SqList *CreateList(ElemType a[], int n)
	{
	int i;
	struct SqList *a_sqlist; //定义结构体指针
	a_sqlist =(struct SqList*)malloc(sizeof(struct student))
	}
	!*** 显著的区别是 struct SqList 被完全替换为了 SqList
	*/

int main(void)
{
	return 0;
}
