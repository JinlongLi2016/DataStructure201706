#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void DestroyList(SqList *p)
{
	free(p);
	printf("func DestroyList called, and a SqList was destroyed.");
}

bool ListEmpty(SqList *L)
{
	return(L->length == 0);
}
int main(void)
{
	int a[] = {0, 1, 2, 3, 4};
	SqList *ptrl = CreateList(a, 5);
	printf("%d\n",ptrl->data[2]);
	printf("%d\n",(*ptrl).data[2] );

	DestroyList(ptrl);
	return 0;
}
