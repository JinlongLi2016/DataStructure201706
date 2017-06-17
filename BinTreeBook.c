#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int ElemType;

// 二叉树的先序遍历的非递归实现 using a tree
void PreOrderLoop(BTNode * b)
{
	BTNode *St[MaxSize], *p;
	int top = -1;

	if(b!=NULL){
		top++;
		St[top] = b;
		while(top > -1)	//栈不为空时循环
		{
			p = St[top]; top--;	
			printf("%c", p->data);
			if(p->rchild != NULL)
			{
				top++;
				St[top] = p->rchild;
			}
			if(p->lchild != NULL)
			{
				top++;
				St[top] = p->lchild;
			}

		}
		printf("\n");
	}
}

// 后序遍历的非递归算法 (more please refer the page 180 of textbook)
void PostOrderLoop(BTNode *b)
{
	BTNode *St[MaxSize];
	BTNode *p;
	int flag, top = -1;

	if (b!=NULL)
	{
		do{

			while(b!=NULL)
			{
				top++;	St[top] =  b;	b = b->lchild;
			}

			p = NULL;
			flag = 1;
			
			while(top != -1 && flag)
			{
				b = St[top];
				if(b->rchild ==p)	// b的右孩子节点刚才被访问,那么此时可以访问 b 节点
				{
					printf("%c\n", b->data);	top--;	p = b;
				}
				else
				{
					b = b->rchild;
					flag = 0;
				}
			}


		}while(top != -1);
	}

	printf("\n");
}


int main(void)
{
	printf("Hello world\n");
}

