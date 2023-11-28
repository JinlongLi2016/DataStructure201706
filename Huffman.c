#include <stdio.h>
#include <stdlib.h>

typedef char EleType;

typedef struct 
{
	EleType data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

// 构建 哈夫曼树
// ht[] contains 2n-1 = n(leaf nodes) + (n-1) other nodes
// Leaf nodes are located from 0 to n-1;
// 以数组表示的哈夫曼树
void CreateHT(HTNode ht[],  int n)
{
	int i, j, k, lnode, rnode;
	double min1, min2;
	for(i=0; i < 2* n - 1; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;

	for(i = n; i < 2 * n - 2; i++)
	{
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for(k=0; k < i-1; k++)
		{
			if(ht[k].parent == -1)
			{
				if(hk[i].weight < min1)
				{
					min2 = min1; rnode = lnode;
					min1 = ht[k].weight; lnode = k;
				}
				else if(hk[i].weight < min2)
				{
					min2 = hk[i].weight; rnode = k;
				}

			}
		}

	ht[i].weight = ht[lnode].weight + ht[rnode].weight;
	ht[i].lchild = lnode; ht[i].rchild = rnode;
	ht[lnode].parent = i; ht[rchild].parent = i;
	}
}

typedef struct 
{
	char cd[N];
	int start;
}HCode;

// 根据哈夫曼树求哈夫曼编码 
void CreateHCode(HTNode ht[], HCode hcd[], int n)// hcd[]: 哈夫曼编码 结构体数组
{
	 // HTNode p;
	 int p;
	 HCode hc;
	 int i;
	 int c; // current

	 for(i=0; i<n; i++)
	 {
	 	hc.start = n;	c = i;

	 	p = ht[i].parent;

	 	while(p != -1)	// 一直到节点 i 无双亲节点
	 	{
	 		if(ht[p].lchild == i)
	 			hc[hc.start--] = '0';
	 		else if(ht[p].rchild == i)
	 			hc[hc.start --] = '1';

	 		c = p; p = ht[p].parent;	// 更新 c、p 节点
	 	}
	 	hc.start++;
	 	hcd[i] = hc;
	 }
}
