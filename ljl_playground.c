#include<stdio.h>
#include<stdlib.h>
#define MaxSize 30

typedef int ElemType;
typedef struct BTNode *BinTree;
struct BTNode{
	ElemType data;
	struct BTNode *lchild;
	struct BTNode *rchild;

};

void PreOrder(BinTree b) // b is a pointer
{
	struct BTNode * St[MaxSize];
	int top = -1;
	
	if(b != NULL)	St[++top] = b;
	while(top > -1)
	{
		b = St[top]; top --; printf("%d", b->data);
		if(b->rchild != NULL)
		{
			top++; St[top] = b->rchild;
		}
		if(b->lchild != NULL)
		{
			top++; St[top] = b->lchild;
		}

	}
	printf("\n");
}

void InOrder(BinTree b)
{
	struct BTNode *St[MaxSize];
	int top = -1;
	struct BTNode *p;

	
	do{
		while(b!=NULL)
		{
			top++;	St[top] = b; b = b->lchild;
		}

		p = NULL;

		b = St[top];
		if(b->lchild == p)
		{
			top--; printf("%d", b->data); p = b; b = b->rchild;
		}
		else
		{
			b = b->rchild;
		}

	}while(top>-1);
}
void InOrder1(BinTree b)
{
	struct BTNode *St[MaxSize], *p;
	int top = -1;
	printf("b->data=%d", b->data);
	if(b!=NULL)
	{
		p = b;

		while(top>-1 || p!=NULL)
		{
			while(p != NULL)
			{
				printf("hello wrold%d", p->data);

				top++; St[top] = p; p = p->lchild;
			}

			p = St[top];
			top--;
			printf("%d", p->data);
			p = p->rchild;
		}
	}
	printf("hello wrold");
}
int main()
{
	BinTree a,b,c,d; //a,b,c,d 为指向结构体的指针 结构体内存中的起始位置
	//妈蛋 sizeof(BinTree) = 4  sizeof(struct BTNode) = 12
	//
	//
	
	a = (struct BTNode *)malloc(sizeof(struct BTNode)); //sizeof(pointer or struct type)
	b = (struct BTNode *)malloc(sizeof(struct BTNode));
	c = (struct BTNode *)malloc(sizeof(struct BTNode));
	d = (struct BTNode *)malloc(sizeof(struct BTNode));

	a->data = 1;
	b->data = 2;
	c->data = 3;
	d->data = 4;
	if(a->lchild == NULL)	printf("NULL");

	a->lchild = b; 
	a->rchild = c;
	b->lchild = d;
	printf("%d;", a->data);
	printf("%d;", a->lchild->data);
	printf("c.data = %d;", a->rchild->data);
	if(c->rchild == NULL)
		printf("c right child is null %d", c->rchild->data);
	// d->data = 4;
	printf("%d", a->lchild->lchild->data);
	printf("\n%d & %d", sizeof(BinTree), sizeof(struct BTNode));
	// InOrder1(a);

	return 0;
}