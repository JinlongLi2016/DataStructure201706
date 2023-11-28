// **********               线索二叉树             *********
#include <stdio.h>

typedef int ElemType;

typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;


// 构建一个中序线索二叉树(via 中序遍历)
void InThread(ThreadTree &t, ThreadTree &pre)
{
	if(t != NULL)
	{
		InThread(t->lchild, pre);
		if(t->lchild == NULL)
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		if(pre != NULL && pre->rchild != NULL)
		{
			pre->rtag = 1;
			pre->rchild = t;
		}
		pre = t;
		InThread(t->rchild, pre);
	}
}

void CreatInThread(ThreadTree T)
{
	pre = NULL;
	if(T != NULL)			//非空二叉树线索化
	{
		InThread(T, pre);	//中序线索化
		pre->ltag = 1;		//处理最后一个节点
		pre->lchild = NULL;
	}
}

// 遍历中序线索二叉树
void TraverseInThreadTree(ThreadTree &p)
{
	ThreadNode *t = p;
	while(p->ltag == 0) 
		p = p->lchild;
	printf("%d", p->data); // visit(t)
	while(p->rchild != NULL) // [感觉这个判断是错的] 当 p->rchild为空时不会访问p
	{
		if(p->rtag == 1) 
		{
			p = p->rchild;
			printf("%d", p->data); // visit
		}
		else//p->rtag == 0
		{
			p = p->rchild;
			while(p->ltag == 0) // 当lchild 为孩子节点
				p = p->lchild;
			printf("%d\n", p->data); //
		}
	}
	if(t != p)
		printf("%d", p->data);  //visit(p) 补充访问最后一个 p->rchild == NULL 的节点
							//如果只有一个节点p,难道要访问两次？ add a determine statement
}

// 中序线索二叉树的第一个节点
ThreadNode * FirstNode(ThreadNode *p)
{
	while(p->ltag == 0)
		p = p->lchild;
	return p;
}
// 中序线索二叉树的后驱节点
ThreadNode * NextNode(ThreadNode *p)
{
	if(p->rtag == 1)	return p->lchild;
	else	return FirstNode(p->lchild);
}
// 中序线索二叉树的最后一个节点 最后一个节点应该没有右子树
ThreadNode * LastNode(ThreadNode *p)
{//返回最后一个节点指针
	while(p->rtag == 0) //当右边为孩子节点,说明不是最后一个节点
		p = p->rchild;
	return p;
}
//中序线索二叉树的前驱节点 
ThreadNode * PreNode(ThreadNode *p)
{
	if(p->ltag == 0)	return LastNode(p->lchild);
	else	return p->lchild;
}
// With helper functions above, we can traverse the tree via:
void InOrder_travel_threadtree(ThreadTree T)
{
	for(ThreadNode *p = FirstNode(T); p!= NULL; p = NextNode(p))
		printf("%d", p->data);// visit(p);
}
int main(void)
{
	return 0;
}