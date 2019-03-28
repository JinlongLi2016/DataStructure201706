// 王道复习书  第四章 二叉树 归纳总结部分 练习
#include <stdio.h>

typedef int ElemType;

typedef struct BTNode{
	ElemType data;
	struct BTNode *lchild, *rchild;
}BTNode, *BinTree;

// (5) 统计二叉树的宽度
void BinTreeWidth(BinTree T)
{
	int MaxWidth = 0, t = 0;
	InitQueue(Q);
	EnQueue(Q, T);	t++;//当前层的元素个数
	while(!IsEmpty(Q))
	{

		DeQueue(Q, T);
		t--;
		if(t == 0)
		{
			MaxWidth = (MaxWidth>t)?MaxWidth:t;
		}
		if(T->lchild != NULL)	EnQueue(Q, T->lchild);t++;
		if(T->rchild != NULL) 	EnQueue(Q, T->rchild);t++;

	}
}


// (6) 删去所有叶节点
void DeleteLeaves(BinTree T)
{
	if(T)//先序遍历二叉树
	{
		if(T->lchild->lchild == NULL && T->lchild->rchild == NULL)
			T->lchild == NULL;//free(T->lchild)
		if(T->rchild->lchild == NULL && T->rchild->rchild == NULL)
			T->rchild = NULL;
		DeleteLeaves(T->lchild);
		DeleteLeaves(T->rchild);
	}
}

// (7) 计算二叉树T指定节点 p 所在的层次
void leverlP(BTNode *&p,BinTree T, int &leverl)
{//leverl 即为节点p所在的层次(initialized as 1)
	if(T)
	{
		leverlP(p, T->lchild, leverl);
		leverlP(p, T->rchild, leverl);
		if(T->lchild == p || T->rchild == p)
		{
			leverl++; p = T;
		}
	}
}//采用这种方式可行吗？
// 或者采用返回层的方式？

// (8)

int main(void)
{
	return 0;
}