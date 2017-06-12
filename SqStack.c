#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
typedef int ElementType;

typedef struct{
	ElementType Data[MaxSize];
	int top;
}SqStack;
// Init a Stack
// SqStack CreateStack(int MaxSize)
SqStack *CreateStack()
{
	SqStack * ss;
	ss = (SqStack *)malloc(sizeof(SqStack));
	ss->top = -1;
	return ss;
}
// Check whether the stack is full or not
bool IsFull(SqStack *ss)
{
	return(ss->top == (MaxSize - 1));
}
// Push an element to the stack
void Push(ElementType item, SqStack *ss)
{
	// printf("Not implemented\n");
	ss->top ++;
	ss->Data[ss->top] = item;
}
// Check the stack is full or not
bool IsEmpty(SqStack *ss)
{
	return(ss->top==-1);
}
// Pop an element from the stack
ElementType Pop(SqStack *ss)
{
	if(IsEmpty(ss))	return NULL;
	ss->top--;
	return ss->Data[ss->top + 1];
}
int main(void)
{
	SqStack *ss;
	ElementType elem = 1;

	ss = CreateStack();
	printf("IsEmpty %d\n", IsEmpty(ss));
	printf("IsFull %d\n",IsFull(ss));
	Push(elem, ss); 
	printf("%d\n", ss->Data[0]);;
	printf("%d\n", Pop(ss));
	free(ss);
	return 0;

}