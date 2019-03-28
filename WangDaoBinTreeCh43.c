#include <stdio.h>

// 5 非递归求二叉树高度
int BinTreeHeight(BinTree T)
{//先序遍历
	InitQueue(Q); 
	int pnum = 0, cnum = 0, h = 0;
	if(T)
	{	
		EnQueue(Q, T); 
		pnum++;
		h++;	// h 表示pnum所在的层次
	}
	while(!IsEmpty(Q))
	{
		DeQueue(Q, T);
		pnum--;
		if(T->lchild != NULL)
		{	EnQueue(Q, T->lchild);
			cnum++;
		}
		if(T->rchild != NULL)
		{	EnQueue(Q, T->rchild);
			cnum ++;
		}
		if(pnum == 0)
		{
			pnum = cnum;	cnum = 0;	h++;
		}
	}
	return h;
}
// 7 判断一个二叉树为完全二叉树
bool IsCompleteTree(BinTree T)
{//先序遍历判断每层节点个数 记录本层节点和下一层节点的个数
	除最后一层 其他层都是满的
}

int main(void)
{
	return 0;
}