#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode *List; // 代表结构体指针的 (typedef)
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};

struct LNode L;
List PtrL;
/* L.Data[i] or PtrL->Data[i]
L.Last+1 or PtrL->Last+1
*/

List MakeEmpty()
{
	// List PtrL;
	struct LNode *PtrL;
	PtrL =  (List)malloc( sizeof(struct LNode ));
	PtrL->Last = -1;
	return PtrL;
}
//Search
int Find(ElementType X, List PtrL)
{
	int i=0;
	while(i <= PtrL->Last && PtrL->Data[i]!= X)
		i++;
	if(i>PtrL->Last)	return -1;
	else	return i;
}
//Insertion   an element X on i(1<=i<=n+1) place
void Insert(ElementType X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE-1)
	{
		printf("manle\n");
		return;
	}
	if(i<1 || i> PtrL->Last+2){
		printf("Place %d is not proper\n", i);
		return;
	}
	for(j=PtrL->Last; j>=i-1; j--)
		PtrL->Data[j+1] = PtrL->Data[j];
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}
// Deletion delete the ith(1<=i<=n) element
void Delete(int i, List PtrL)
{
	int j;
	if(i<1 || i>PtrL->Last+1){
		printf("Place %d is inapproper.\n", i);
		return;
	}
	for(j=i;j<=PtrL->Last;j++)
		PtrL->Data[j-1] = PtrL->Data[j];
	PtrL->Last--;
	return;
}
int main(void)
{
	return 0;
}