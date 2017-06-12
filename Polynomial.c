#include <stdio.h>
#include <stdlib.h>

struct Polynode{
	int coef;
	int expon;
	struct Polynode *link;
};

typedef struct Polynode *Polynomial;
Polynomial P1, P2;
int ComPare(int i1, int i2)
{
	if(i1==i2)	return 0;
	else	return(i1>i2?1:-1);
}
void Attach( int c, int e, Polynomial *pRear )
{ /* 由于在本函数中需要改变当前结果表达式尾项指针的值， */
/* 所以函数传递进来的是结点指针的地址， *pRear指向尾项*/
 	Polynomial P;
 	P =(Polynomial)malloc(sizeof(struct Polynode)); /* 申请新结点 */
 	P->coef = c; /* 对新结点赋值 */
 	P->expon = e;
 	P->link=NULL;
 	/* 将P指向的新结点插入到当前结果表达式尾项的后面 */
 	(*pRear)->link = P;// ljl: pRear 为指针的指针

 	*pRear = P; /* 修改pRear值 */
}
Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct Polynode));
	front = rear;
	while(P1 && P2)
		switch(ComPare(P1->expon, P2->expon)){
			case 1:
				Attach(P1->coef, P1->expon, &rear);
				P1 = P1->link;
				break;
			case -1:
				Attach(P2->coef, P2->expon, &rear);
				P2 = P2->link;
				break;
			case 0:
				sum = P1->coef + P2->coef;
				if(sum) Attach(sum, P1->expon, &rear);
				P1 = P1->link;
				P2 = P2->link;
				break;
		}
	for(;P1;P1 = P1->link)	Attach(P1->coef, P1->expon, &rear);
	for(;P2;P2 = P2->link)	Attach(P2->coef, P2->expon, &rear);
	rear->link=NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}
int main(void)
{
	struct Polynode *anode;
	anode =(struct Polynode*)malloc(sizeof(struct Polynode));
	
	return 0;
}