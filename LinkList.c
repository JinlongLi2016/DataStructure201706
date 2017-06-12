#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct LNode *List;

struct LNode
{
	ElementType data;
	List Next;
};

int Length(List PtrL)	//List == struct LNode *ptrl
{
	List p = PtrL;
	int j;
	while(p){
		p = p->Next;
		j++;	// 当前p指向的是第j个节点
	}
	return j;
}	//O(n)

// Search
List FindKth(int K, List PtrL) // 返回kth元素的地址
{
	List p = PtrL;
	int i=1;
	while(p!=NULL && i<K){
		p = p->Next;
		i++;
	}
	if(i==K)	return p;
	else	return NULL;
}
List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while(p!=NULL && p->data!=X)
		p = p->Next;
	return p;
}

// Insertion insert after place (i-1)
List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if(i==1){
		s = (List)malloc(sizeof(struct LNode));
		s->data  = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i-1, PtrL);
	if(p==NULL){
		printf("Wrong Parameter\n");
		return NULL;
	}else{
		s = (List)malloc(sizeof(List));// s = (List)malloc(sizeof(struct LNode))
		return PtrL;
	}
}
// Deletion
List Delete(int i, List PtrL)
{
	List p, s;
	if(i==1){
		s = PtrL;
		if(PtrL != NULL) PtrL = PtrL->Next;
		else	return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i-1, PtrL);
	if(p==NULL){
		printf("...");
		return NULL;
	}else if(p->Next == NULL){
		printf("the %dth node doesn't exist\n", i);
		return NULL;
	}else{
		s = p->Next;
		p->Next = s->Next;
		free(s); // S is an address
		return PtrL;
	}
}

// int main(int argc, char const *argv[])
int main(void)
{
	/* code */
	return 0;
}