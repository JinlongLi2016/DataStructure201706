#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;
typedef struct TreeNode *BinTree;

struct TreeNode{
	ElemType Data;
	struct TreeNode * Left;
	struct TreeNode * Right;
};

void PreOrderTraversal( BinTree BT);
void InOrderTraversal( BinTree BT);
void PostOrderTraversal( BinTree BT);
void InOrderTraversalLoop( BinTree BT);
void LevelOrderTraversal( BinTree BT);
int main(void)
{
	printf("Hello world!\n");
	return 0;
}
//先根遍历
void PreOrderTraversal( BinTree BT)
{
	if(BT){
		printf("%d", BT->Data);
		PreOrderTraversal( BT->Left);
		PreOrderTraversal( BT->Right);
	}
}

void InOrderTraversal( BinTree BT)
{
	if(BT){
		InOrderTraversal( BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal( BT->Right);
	}
}

void PostOrderTraversal( BinTree BT)
{
	if(BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}
// 中序遍历的非递归实现(循环)
// Basically, accomplish this function via a stack
void InOrderTraversalLoop( BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack( MaxSize);// Create and Initialize t_stack
	while(T || !IsEmpty(S)){
		while(T){
			Push(S, T);
			T = T->Left;
		}
// 		if(!IsEmpty(S)){   // 这里的判断是否多余了？
// 			T = Pop(S);
// 			printf("%5d", T->Data); // access data
// 			T = T->Right; // turn to the right tree
// 		}
		T = Pop(S);
		printf("%5d", T->Data);
		T = T->Right;
	}
}

void LevelOrderTraversal( BinTree BT)
{
	Queue Q;	BinTree T;
	if(!BT)	return; // 空树直接返回
	Q = CreateQueue( MaxSize );
	AddQ(Q, BT);
	while( !IsEmptyQ(Q) ){
		T = DeleteQ( Q );
		printf("%d\n", T->Data);
		if(T->Left)	AddQ(Q, T->Left);
		if(T->Right) AddQ(Q, T->Right);
	}
}

/*
Reflection:
1. 输出二叉树中所有的叶子节点
2. 求二叉树的高度
3. 
 */
